#include <libutils/strings.hh>
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
}
