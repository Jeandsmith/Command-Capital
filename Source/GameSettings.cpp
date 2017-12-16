//
// Created by jeandsmith on 12/16/17.
//

#include "../Headers/GameSettings.h"

void GameSettings::set_character_name (string &name) {
	this->name = name;
}

void GameSettings::set_character_class (string &c_c) {
	this->ch_class = c_c;
}

void GameSettings::set_character_cur_income (double cur_inc) {
	this->cur_income = cur_inc;
}

void GameSettings::save_profile () {
	user_saved_profile.open("../text_files/" + name + "_profile.txt", ios::app | ios::in);
	user_saved_profile << "Name: " << name << "\n"
	                   << "Class:  " << ch_class << "\n"
	                   << "Current Income:  " << cur_income << endl;
}