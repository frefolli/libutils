#include <libutils/strings.hh>
#include <regex>
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
