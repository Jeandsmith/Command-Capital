//
// Created by jeandsmith on 12/28/17.
//

#include <string>
#include "../Headers/input_check.h"
#include "../Headers/console.h"

//TODO
std::string input_check::format_string(std::string &input) {
    console::log("formatting()");
    if (input.empty()) {
        input = " ";
        return input;
    }

    for (size_t i = input.size(); i > 0; --i) {
        if (input[i] != ' ') { break; }
        else {
            input.erase(input.find(input[i]));
        }
    }

    for (char &c : input) {
        c = static_cast<char>(tolower(c));
    }

    console::debug_log("Formatted: %s", input.c_str());
    return input;
}
