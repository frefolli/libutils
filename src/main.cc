#include <libutils/strings.hh>
#include <libutils/vectors.hh>
#include <libutils/sets.hh>
#include <iostream>

std::string to_string(bool value) {
    if (value)
        return "true";
    return "false";
}

int main(int argc, char**args) {
    std::cout << "{\n" << indentString("a\nb") << "\n}" << std::endl;
    std::cout << "--log     = " << to_string(isFlagLongName("--log")) << std::endl;
    std::cout << "--logF    = " << to_string(isFlagLongName("--logF")) << std::endl;
    std::cout << "-l        = " << to_string(isFlagShortName("-l")) << std::endl;
    std::cout << "-ll       = " << to_string(isFlagShortName("-ll")) << std::endl;
    std::cout << "some name = " << encodeFlagLongName("some name") << std::endl;
    std::cout << "someName  = " << encodeFlagLongName("someName") << std::endl;
    std::string magic_string = "a,b,c";
    std::vector<std::string> magic_vector = tokenizeString(magic_string, ",");
    std::set<int> A = {0, 1, 2};
    std::set<int> B = {2};
    std::set<int> C = set_diff(A, B);
    std::cout << magic_vector << std::endl;
    std::cout << C << std::endl;
}
