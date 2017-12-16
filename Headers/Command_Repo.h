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
#include "Character.h"


using namespace std;

class Command_Repo {
    private:
	unordered_map<string, double> list{};

    public:

	explicit Command_Repo () = default;

	void end_game();

	void execute_command(string & command);

	void clear_screen();

	void list_commands();

	void sell_items();

	void buy_item (Character player);

	void set_list ();
};


#endif //SPACE_MARINE_COMMAND_REPO_H
