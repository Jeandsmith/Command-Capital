//
// Created by jeandsmith on 12/28/17.
//

#include <string>
#include <streambuf>
#include <iostream>
#include <cstring>
#include "../Headers/input_check.h"
#include "../Headers/console.h"

char * input_check::format_string(char * input) {
      console::log("formatting()");
      if (input == nullptr) { //If the first index is a null ending character
            return (char *)"NULL";
      }


      //TODO
      for (; *input; ++input){
            if (*input == (char) toupper(*input)){
                  *input = (char) tolower(*input);
            }else continue;
      }

      printf("%s", input);
      return input;
}