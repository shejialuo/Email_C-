#include <string>
#include <unordered_set>

struct MessageFields {
    std::string headers;
    std::string sender;
    std::string messageHeader;
    std::unordered_set<std::string> links;
    std::unordered_set<std::string> attachments;
};