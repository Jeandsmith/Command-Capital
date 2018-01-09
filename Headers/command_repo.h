//
// Created by jeandsmith on 12/3/17.
//

#ifndef SPACE_MARINE_COMMAND_REPO_H
#define SPACE_MARINE_COMMAND_REPO_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <list>
#include "character.h"
#include "economy_controller.h"

class command_repo {
      typedef void (command_repo::*function_pointer)();
      typedef unordered_map<string, function_pointer> command_map;
      command_map c_map;
      unique_ptr<economy_controller> _controller{new economy_controller};
      unique_ptr<character> _unique_player;

public:
      explicit command_repo();

      void set_commands();

      void set_player(std::unique_ptr<character> &current_player);

      void execute_command(const char *command);

      void get_class(std::unique_ptr<character> &player);

      void get_user_information(std::unique_ptr<character> &player);

      void clear_screen();

      void list_commands();

//    void sell_items();

      void buy_item();

      void give_info();

      void save_game();

      void new_game();
};


#endif //SPACE_MARINE_COMMAND_REPO_H
