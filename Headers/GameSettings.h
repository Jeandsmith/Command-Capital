//
// Created by jeandsmith on 12/16/17.
//

#ifndef SPACE_MARINE_GAMESETTINGS_H
#define SPACE_MARINE_GAMESETTINGS_H

#include <iostream>
#include <fstream>

using namespace std;

class GameSettings {
    private:
	fstream user_saved_profile;
	string name, ch_class;
	double cur_income;
    public:
	void save_profile ();

	void set_character_name (string &name);

	void set_character_class (string &c_c);

	void set_character_cur_income (double cur_inc);
};


#endif //SPACE_MARINE_GAMESETTINGS_H
