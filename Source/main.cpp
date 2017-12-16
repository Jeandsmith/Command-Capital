#include <iostream>
#include <random>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>

#include "../Headers/Character.h"
#include "../Headers/Command_Repo.h"
#include "../Headers/GameSettings.h"

using namespace std;

GameSettings settings;

// Display the game screen
void intro_screen () {
	fstream title_screen{R"(../text_files/intro.txt)", ios::in};

	if (!title_screen.is_open()) {
		cout << "The file could not be open" << endl;
		return;
	} else {
		string input;
		while (getline(title_screen, input)) {
			cout << input << endl;
		}
	}

	title_screen.close();
}

void get_user_information () {
	Character *player = new Character();
	cout << "Name of character: ";
	string ch_name;

	while (getline(cin, ch_name)) {
		if (ch_name.empty()) {
			cout << "Field is empty" << std::endl;
			cout << "Try again: " << std::endl;
			goto getinput;
		} else {
			void get_class (Character &);
			player->set_name(ch_name);
			settings.set_character_name(ch_name);
			get_class(*player);
			break;
		}
		getinput:
		getline(cin, ch_name);
	}

	cout << "\n";
}


void get_class (Character &pl) {

	cout << "Choose class" << endl;
	cout << "Options --> " << endl;
	cout << "\tBaker.======== 1" << endl;
	cout << "\tBusiness.===== 2" << endl;
	cout << "\tCommoner.===== 3" << endl;

	int option = 1;
	cin >> option;
	while (option <= 0 || option > 3) {
		cout << "Invalid option: " << endl;
		cout << "Try again: " << endl;
		cin >> option;
	}

	string c_class;
	switch (option) {
		case 1:
			cout << "Baker class" << endl;
			c_class = "Baker";
			pl.set_class(c_class);
			settings.set_character_class(c_class);
			break;

		case 2:
			cout << "Business Class" << endl;
			c_class = "Business";
			pl.set_class(c_class);
			settings.set_character_class(c_class);
			break;

		case 3:
			cout << "Commoner class" << endl;
			c_class = "Commoner";
			pl.set_class(c_class);
			settings.set_character_class(c_class);
			break;

		default:
			break;
	}

	void set_initial_income (Character *);
	set_initial_income(&pl);
}


void set_initial_income (Character *player) {
	double init_cap = 0;
	if (player->class_type() == "Baker")init_cap = 50.00f;
	else if (player->class_type() == "Business") init_cap = 100.0f;
	else if (player->class_type() == "Commoner") init_cap = 15.0f;

	player->set_initial_capital(init_cap);
	settings.set_character_cur_income(init_cap);
}


int main () {
	srand(static_cast<unsigned>(time(nullptr)));

	intro_screen();
	cout << "Enter command->  \n";
	cout << "Enter \'help\' for list of commands." << endl;
	cout << "Enter \'exit\' to close the console." << endl;
	cout << "Enter \'save\' to save the current player profile." << endl;

	get_user_information();

	Command_Repo command_r;
	string command;
	command.clear();
	cout << "Enter command:: ";
	getline(cin, command);


	while (command != "exit") {
		cout << "\n";
		command_r.execute_command(command);
		command.clear();
		getline(cin, command);
	}

	return 0;
}