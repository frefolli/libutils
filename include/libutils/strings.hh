#ifndef UTILS_STRINGS_HH
#define UTILS_STRINGS_HH

#include <string>
#include <vector>

std::string indentString(std::string text);
bool isFlagLongName(std::string longName);
bool isFlagShortName(std::string shortName);
std::string encodeFlagLongName(std::string longName);
std::vector<std::string> tokenizeString(std::string text, const char* delim);

#endif
