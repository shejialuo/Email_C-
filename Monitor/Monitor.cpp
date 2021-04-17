#include "Monitor.hpp"

string Monitor::stringSplit(string& message, int n, char splitChar) {
    vector<string> param;
    istringstream iss(message);
    string token;
    while(getline(iss, token, splitChar)) {
        param.push_back(token);
    }
    return param.at(n);
}

int Monitor::stringFindNumber(string& message) {
    int length = 0;
    int number = 0;
    for(auto &m: message) {
        if(m >= '0' && m <= '9') {
            length++;
        }
    }
    for(auto &m: message) {
        if(m >= '0' && m <= '9') {
            number+= (m - '0') * pow(10, length - 1);
            length--;
        }
    }
    return number;
}

string Monitor::shellExecute(string& command) {
    FILE *fp = NULL;
	char *buff = NULL;
	buff = (char*)malloc(500);
	memset(buff, 0, 500);
	fp = popen(command.c_str(), "r");
	fgets(buff, 500, fp);
	string result = buff;
	pclose(fp);
	free(buff);
    return result;
}

Monitor::Monitor() {
    messageCounter = 0;
    numberOfMessagesInAMonitorWindow = {
        10, 10, 10, 10, 10, 10, 10,
		30, 30, 30, 30, 30, 30, 30,
		80, 80, 80, 80, 80, 80, 80,
		160, 160, 160, 160, 160, 160, 160,
		180, 180, 180, 180, 180, 180, 180,
		100, 100, 100, 100, 100, 100, 100,
		80, 80, 80, 80, 80, 80, 80,
		60, 60, 60, 60, 60, 60, 60
    };
    monitorWindowDimension = 200;
    numberOfHedaerAnalyser = 1;
    numberOfLinkAnalyser = 1;
    numberOfTextAnalyser = 1;
    numberOfSentimentAnalyser = 1;
    numberOfImageAnalyser = 1;
    numberOfImageRecgonizer = 1;
    numberOfNSFWDetector = 1;
    index = 0;
}

string Monitor::dataBaseQuery(string& command) {
    return shellExecute(command);
}

vector<string> Monitor::headerAnalyserQuery() {
    vector<string> results;
    for(int i = 1; i <= numberOfHedaerAnalyser; i++) {
            string command = "sudo docker logs headeranalyser"+ to_string(i) + " | tail -1";
            string shellResult = shellExecute(command);
            results.push_back(shellResult);
    }
    return results;
}

vector<string> Monitor::linkAnalyserQuery() {
    vector<string> results;
    for(int i = 1; i <= numberOfLinkAnalyser; i++) {
            string command = "sudo docker logs linkanalyser"+ to_string(i) + " | tail -1";
            string shellResult = shellExecute(command);
            results.push_back(shellResult);
    }
    return results;
}

vector<string> Monitor::textAnalyserQuery() {
    vector<string> results;
    for(int i = 1; i <= numberOfTextAnalyser; i++) {
            string command = "sudo docker logs textanalyser"+ to_string(i) + " | tail -1";
            string shellResult = shellExecute(command);
            results.push_back(shellResult);
    }
    return results;
}

vector<string> Monitor::sentimentAnalyserQuery() {
    vector<string> results;
    for(int i = 1; i <= numberOfSentimentAnalyser; i++) {
            string command = "sudo docker logs sentimentanalyser"+ to_string(i) + " | tail -1";
            string shellResult = shellExecute(command);
            results.push_back(shellResult);
    }
    return results;
}

void Monitor::scaleHeaderAnalyser(string& dataBaseQuery, vector<string>& headerAnalyserQuery) {
    string resultSplited = stringSplit(dataBaseQuery, 6,' ');
    int arriveNumber = stringFindNumber(resultSplited);
    int difference = messageCounter - arriveNumber;
    if( difference > 0) {
        int numberOfHeaderAnalyserInAMonitorTime = monitorWindowDimension / 5;
        double scaleUpNumber_ = static_cast<double>(difference) / 
                                static_cast<double>(numberOfHeaderAnalyserInAMonitorTime);
        int scaleUpNumber = ceil(scaleUpNumber_);
        for(int i = 1; i <= scaleUpNumber; i++) {
            string command = "/home/shejialuo/Projects/Email_Microservices/scripts/HeaderAnalyser.sh headeranalyser"
                             + to_string(i + numberOfHedaerAnalyser);
            shellExecute(command);
            time_t now_time=time(NULL);  
            tm*  t_tm = localtime(&now_time);  
            string stt = asctime(t_tm);
            stt.erase(remove(stt.begin(), stt.end(), '\n'), stt.end());
            std::string logString = stt + " " + "创建了HeaderAnalyser" + to_string(i + numberOfHedaerAnalyser);
            std::cout << logString << std::endl;
        }
    }
    else {
        vector<int> headerAnalyserQuery_;
        for(auto &query: headerAnalyserQuery) {
            string stringSplited = stringSplit(query, 5, ' ');
            headerAnalyserQuery_.push_back(stringFindNumber(stringSplited));
        }
        sort(headerAnalyserQuery_.begin(),headerAnalyserQuery_.end());
        for(int i = 0; i < headerAnalyserQuery_.size() - 1; i++) {
            if(headerAnalyserQuery_.at(i) + 1 != headerAnalyserQuery_.at(i+1)) {
                return;
            }
        }
        int messageNumber = numberOfMessagesInAMonitorWindow.at(index);
        int numberRequired_ = messageNumber / (monitorWindowDimension / 5);
        int numberRequired = ceil(numberRequired_);
        while(numberRequired < numberOfHedaerAnalyser) {
            Client newClient("192.168.84.0",8000,8001);
            newClient.socket();
            newClient.bind();
            newClient.connect();
            newClient.send("disconnect");
            newClient.close();
            string command = "sudo docker container rm -f headeranalyser" + to_string(numberOfHedaerAnalyser);
            shellExecute(command);
            time_t now_time=time(NULL);  
            tm*  t_tm = localtime(&now_time);  
            string stt = asctime(t_tm);
            stt.erase(remove(stt.begin(), stt.end(), '\n'), stt.end());
            std::string logString = stt + " " + "删除了HeaderAnalyser" + to_string(numberOfHedaerAnalyser);
            std::cout << logString << std::endl;
            numberOfHedaerAnalyser--;
        }
    }
}

void Monitor::scaleTextAnalyser(string& saQuery, vector<string>& textAnalyserQuery) {
    string resultSplited = stringSplit(saQuery, 5,' ');
    int arriveNumber = stringFindNumber(resultSplited);
    int difference = messageCounter - arriveNumber;
    if( difference > 0) {
        int numberOfTextAnalyserInAMonitorTime = monitorWindowDimension / 2;
        double scaleUpNumber_ = static_cast<double>(difference) / 
                                static_cast<double>(numberOfTextAnalyserInAMonitorTime);
        int scaleUpNumber = ceil(scaleUpNumber_);
        for(int i = 1; i <= scaleUpNumber; i++) {
            string command = "/home/shejialuo/Projects/Email_Microservices/scripts/TextAnalyser.sh textanalyser"
                             + to_string(i + numberOfTextAnalyser);
            shellExecute(command);
            time_t now_time=time(NULL);  
            tm*  t_tm = localtime(&now_time);  
            string stt = asctime(t_tm);
            stt.erase(remove(stt.begin(), stt.end(), '\n'), stt.end());
            std::string logString = stt + " " + "创建了TextAnalyser" + to_string(i + numberOfTextAnalyser);
            std::cout << logString << std::endl;
        }
    }
    else {
        vector<int> textAnalyserQuery_;
        for(auto &query: textAnalyserQuery) {
            string stringSplited = stringSplit(query, 5, ' ');
            textAnalyserQuery_.push_back(stringFindNumber(stringSplited));
        }
        sort(textAnalyserQuery_.begin(),textAnalyserQuery_.end());
        for(int i = 0; i < textAnalyserQuery_.size() - 1; i++) {
            if(textAnalyserQuery_.at(i) + 1 != textAnalyserQuery_.at(i+1)) {
                return;
            }
        }
        int messageNumber = numberOfMessagesInAMonitorWindow.at(index);
        int numberRequired_ = messageNumber / (monitorWindowDimension / 2);
        int numberRequired = ceil(numberRequired_);
        while(numberRequired < numberOfHedaerAnalyser) {
            Client newClient("192.168.88.0",8000,8001);
            newClient.socket();
            newClient.bind();
            newClient.connect();
            newClient.send("disconnect");
            newClient.close();
            string command = "sudo docker container rm -f textanalyser" + to_string(numberOfTextAnalyser);
            shellExecute(command);
            time_t now_time=time(NULL);  
            tm*  t_tm = localtime(&now_time);  
            string stt = asctime(t_tm);
            stt.erase(remove(stt.begin(), stt.end(), '\n'), stt.end());
            std::string logString = stt + " " + "删除了TextAnalyser" + to_string(numberOfTextAnalyser);
            std::cout << logString << std::endl;
            numberOfTextAnalyser--;
        }
    }
}

void Monitor::scaleSentimentAnalyser(string& dataBaseQuery, vector<string>& sentimentAnalyserQuery) {
    string resultSplited = stringSplit(dataBaseQuery, 6,' ');
    int arriveNumber = stringFindNumber(resultSplited);
    int difference = messageCounter - arriveNumber;
    if( difference > 0) {
        int numberOfSentimentAnalyserInAMonitorTime = monitorWindowDimension / 4;
        double scaleUpNumber_ = static_cast<double>(difference) / 
                                static_cast<double>(numberOfSentimentAnalyserInAMonitorTime);
        int scaleUpNumber = ceil(scaleUpNumber_);
        for(int i = 1; i <= scaleUpNumber; i++) {
            string command = "/home/shejialuo/Projects/Email_Microservices/scripts/SentimentAnalyser.sh textanalyser"
                             + to_string(i + numberOfSentimentAnalyser);
            shellExecute(command);
            time_t now_time=time(NULL);  
            tm*  t_tm = localtime(&now_time);  
            string stt = asctime(t_tm);
            stt.erase(remove(stt.begin(), stt.end(), '\n'), stt.end());
            std::string logString = stt + " " + "创建了SentimentAnalyser" + to_string(i + numberOfSentimentAnalyser);
            std::cout << logString << std::endl;
        }
    }
    else {
        vector<int> sentimentAnalyserQuery_;
        for(auto &query: sentimentAnalyserQuery) {
            string stringSplited = stringSplit(query, 5, ' ');
            sentimentAnalyserQuery_.push_back(stringFindNumber(stringSplited));
        }
        sort(sentimentAnalyserQuery_.begin(),sentimentAnalyserQuery_.end());
        for(int i = 0; i < sentimentAnalyserQuery_.size() - 1; i++) {
            if(sentimentAnalyserQuery_.at(i) + 1 != sentimentAnalyserQuery_.at(i+1)) {
                return;
            }
        }
        int messageNumber = numberOfMessagesInAMonitorWindow.at(index);
        int numberRequired_ = messageNumber / (monitorWindowDimension / 4);
        int numberRequired = ceil(numberRequired_);
        while(numberRequired < numberOfHedaerAnalyser) {
            Client newClient("192.168.90.0",8000,8001);
            newClient.socket();
            newClient.bind();
            newClient.connect();
            newClient.send("disconnect");
            newClient.close();
            string command = "sudo docker container rm -f sentimentanalyser" + to_string(numberOfSentimentAnalyser);
            shellExecute(command);
            time_t now_time=time(NULL);  
            tm*  t_tm = localtime(&now_time);  
            string stt = asctime(t_tm);
            stt.erase(remove(stt.begin(), stt.end(), '\n'), stt.end());
            std::string logString = stt + " " + "删除了SentimentAnalyser" + to_string(numberOfSentimentAnalyser);
            std::cout << logString << std::endl;
            numberOfSentimentAnalyser--;
        }
    }
}

void Monitor::scaleLinkAnalyser(string& dataBaseQuery, vector<string>& linkAnalyserQuery) {
    string resultSplited = stringSplit(dataBaseQuery, 6,' ');
    string result = stringSplit(resultSplited, 0, '_');
    int arriveNumber = stringFindNumber(result);
    int difference = messageCounter - arriveNumber;
    if( difference > 0) {
        int numberOfLinkAnalyserInAMonitorTime = monitorWindowDimension / 5;
        double scaleUpNumber_ = static_cast<double>(difference) / 
                                static_cast<double>(numberOfLinkAnalyserInAMonitorTime);
        int scaleUpNumber = ceil(scaleUpNumber_);
        for(int i = 1; i <= scaleUpNumber; i++) {
            string command = "/home/shejialuo/Projects/Email_Microservices/scripts/LinkAnalyser.sh linkanalyser"
                             + to_string(i + numberOfLinkAnalyser);
            shellExecute(command);
            time_t now_time=time(NULL);  
            tm*  t_tm = localtime(&now_time);  
            string stt = asctime(t_tm);
            stt.erase(remove(stt.begin(), stt.end(), '\n'), stt.end());
            std::string logString = stt + " " + "创建了LinkAnalyser" + to_string(i + numberOfLinkAnalyser);
            std::cout << logString << std::endl;
        }
    }
    else {
        vector<int> linkAnalyserQuery_;
        for(auto &query: linkAnalyserQuery) {
            string stringSplited = stringSplit(query, 5, ' ');
            string result = stringSplit(stringSplited, 0, '_');
            linkAnalyserQuery_.push_back(stringFindNumber(result));
        }
        sort(linkAnalyserQuery_.begin(),linkAnalyserQuery_.end());
        for(int i = 0; i < linkAnalyserQuery_.size() - 1; i++) {
            if(linkAnalyserQuery_.at(i) + 1 != linkAnalyserQuery_.at(i+1)) {
                return;
            }
        }
        int messageNumber = numberOfMessagesInAMonitorWindow.at(index);
        int numberRequired_ = messageNumber / (monitorWindowDimension / 5);
        int numberRequired = ceil(numberRequired_);
        while(numberRequired < numberOfHedaerAnalyser) {
            Client newClient("192.168.86.110",8000,8001);
            newClient.socket();
            newClient.bind();
            newClient.connect();
            newClient.send("disconnect");
            newClient.close();
            string command = "sudo docker container rm -f linkanalyser" + to_string(numberOfLinkAnalyser);
            shellExecute(command);
            time_t now_time=time(NULL);  
            tm*  t_tm = localtime(&now_time);  
            string stt = asctime(t_tm);
            stt.erase(remove(stt.begin(), stt.end(), '\n'), stt.end());
            std::string logString = stt + " " + "删除了LinkAnalyser" + to_string(numberOfLinkAnalyser);
            std::cout << logString << std::endl;
            numberOfLinkAnalyser--;
        }
    }
}

void Monitor::run() {
    while(true) {
        sleep(monitorWindowDimension);
        messageCounter += numberOfMessagesInAMonitorWindow.at(index);

        string command = "sudo docker logs database | grep \"Headers\" | tail -1";
        string headerAnalyserDataBaseQuery = dataBaseQuery(command);

        command = "sudo docker logs saloadbalancer | tail -1";
        string textAnalyserSaQuery = dataBaseQuery(command);

        command = "sudo docker logs database | grep \"Texts\" | tail -1";
        string sentimentAnalyserDataBaseQuery = dataBaseQuery(command);

        command = "sudo docker logs database | grep \"Links\" | tail -1";
        string linkAnalyserDataBaseQuery = dataBaseQuery(command);

        auto headeranalyserQuery = headerAnalyserQuery();
        auto textanalyserQuery = textAnalyserQuery();
        auto sentimentanalyserQuery = sentimentAnalyserQuery();
        auto linkanalyserQuery = linkAnalyserQuery();

        
        auto ScaleHeaderAnalyser = async(launch::async,
                                        [&]{scaleHeaderAnalyser(headerAnalyserDataBaseQuery, headeranalyserQuery);});
        auto ScaleTextAnalyser = async(launch::async, 
                                        [&]{scaleTextAnalyser(textAnalyserSaQuery, textanalyserQuery);});
        auto ScaleSentimentAnalyser = async(launch::async, 
                                        [&]{scaleSentimentAnalyser(sentimentAnalyserDataBaseQuery, sentimentanalyserQuery);});
        auto ScaleLinkAnalyser = async(launch::async, 
                                        [&]{scaleLinkAnalyser(linkAnalyserDataBaseQuery, linkanalyserQuery);});
        index = (index + 1) % numberOfMessagesInAMonitorWindow.size();
    }
}
