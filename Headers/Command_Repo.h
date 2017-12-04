//
// Created by jeandsmith on 12/3/17.
//

#ifndef SPACE_MARINE_COMMAND_REPO_H
#define SPACE_MARINE_COMMAND_REPO_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include "Character.h"


using namespace std;

class Command_Repo {
    private:
	Character player;
	unordered_map<string, double> list{};
	map <string, void(Command_Repo::*)()> point{};
	vector<void(Command_Repo::*)()>func_pointer{};

    public:

	explicit Command_Repo(Character current_player);

	void end_game();

	void execute_command(string & command);

	void clear_screen();

	void list_commands();

	void sell_items();

	void buy_item();
};


#endif //SPACE_MARINE_COMMAND_REPO_H
