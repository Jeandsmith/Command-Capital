//
// Created by jeandsmith on 12/28/17.
//

#include "../Headers/input_check.h"
#include "../Headers/console.h"

//TODO
std::string input_check::format_string(std::string &input) {
    if (input[input.length() - 1] == ' ') {
        console::log("formatting()");
        for (int i = (int) input.size() - 1; i > 0; i--) {
            if (input[i] != ' ') { break; }
            else {
                input.erase(input.find(input[i]));
            }
        }
    }

    return input;
}
