#include <libutils/strings.hh>
#include <regex>
#include <cstring>
#define TAB "    "

std::string indentString(std::string text) {
    return TAB + std::regex_replace(text, std::regex("\\n"), "\n" TAB);
}

bool isFlagLongName(std::string longName) {
    if (longName.size() <= 2)
        return false;
    if (longName.substr(0, 2) != "--")
        return false;
    for (auto it = longName.begin()+2; it != longName.end(); ++it) {
        char c = *it;
        if (! ((c == '-') ||
               ((c >= '0' ) && (c <= '9')) ||
               ((c >= 'A' ) && (c <= 'Z')) ||
               ((c >= 'a' ) && (c <= 'z'))))
            return false;
    }
    return true;
}

bool isFlagShortName(std::string shortName) {
    if (shortName.size() != 2)
        return false;
    if (shortName[0] != '-')
        return false;
    char c = shortName[1];
    if (! ((c == '-') ||
           ((c >= '0' ) && (c <= '9')) ||
           ((c >= 'A' ) && (c <= 'Z')) ||
           ((c >= 'a' ) && (c <= 'z'))))
        return false;
    return true;
}

std::string encodeFlagLongName(std::string longName) {
    for (auto it = longName.begin(); it != longName.end(); ++it) {
        if (*it == ' ')
            *it = '-';
    }
    return longName;
}

std::vector<std::string> tokenizeString(std::string text, const char* delim) {
    std::vector<std::string> tokens = {};
    std::string buffer = "";
    for (auto cIt = text.begin(); cIt != text.end(); ++cIt) {
        if (strchr(delim, *cIt) != NULL) {
            if (buffer.size() > 0) {
                tokens.push_back(buffer);
                buffer = "";
            }
        } else {
            buffer += *cIt;
        }
    }
    if (buffer.size() > 0) {
        tokens.push_back(buffer);
    }
    return tokens;
}
