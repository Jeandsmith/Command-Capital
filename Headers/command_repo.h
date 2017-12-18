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


using namespace std;

class command_repo {
   private:
	economy_controller * economyController = new economy_controller;
	character player;

   public:
	explicit command_repo () = default;

	void set_player (character & current_player);

	void execute_command (string &command);

	void clear_screen ();

	void list_commands ();

	void sell_items ();

	void buy_item ();

	void give_info ();

	void save_game ();

	void new_game ();
};


#endif //SPACE_MARINE_COMMAND_REPO_H
