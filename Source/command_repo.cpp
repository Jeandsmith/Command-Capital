//
// Created by jeandsmith on 12/3/17.
//

#include <fstream>
#include "../Headers/command_repo.h"
#include <string>
#include <iostream>

void command_repo::set_player (character & current_player) {
	this->player = current_player;
}

void command_repo::execute_command (string &command) {
	typedef void (command_repo::*function_pointer) ();
	typedef unordered_map<string, function_pointer> command_map;

	// Save pointers of the function to the key/pointer(value) map
	command_map c_map;
	c_map.emplace("help", &command_repo::list_commands);
	c_map.emplace("clear", &command_repo::clear_screen);
	c_map.emplace("my-info", &command_repo::give_info);
	c_map.emplace("save-game", &command_repo::save_game);
	c_map.emplace("buy-items", &command_repo::buy_item);
	c_map.emplace("new-game", &command_repo::new_game);

	for (auto &com: c_map) {
		if (com.first == command) { // If the command is found in the map
			function_pointer pt = c_map[com.first]; // Make a pointer to the function saved as s value of the command
			(this->*pt)(); // Run the function pointed to this member function.
			break;
		} else if (c_map.find(com.first) == c_map.end()) {
			cout << "Command not found:: " << endl;
		}
	}
}

void command_repo::save_game () {
	fstream save_game_file{R"(../text_files/saved_game_file.txt)", ios::out};
	if (save_game_file.fail()) {
		cout << "Error Occurred" << endl;
	} else {
		save_game_file << player.get_name() << "\n";
		save_game_file << player.get_class_type() << "\n";
		save_game_file << player.income() << "\n";
		cout << "Game Saved" << endl;
		save_game_file.close();
	}
}

void command_repo::buy_item () {
	economyController->pur_items(player);
};

void command_repo::give_info () {
	player.get_info();
}

void command_repo::clear_screen () {
	cout << "\nScreen cleared" << endl;
	system("clear");
};

void command_repo::list_commands () {
	fstream guide_file{"../text_files/game_guide.txt", ios::out | ios::in};
	if (guide_file.fail()) {
		throw "Guide not found";
	} else {
		string input;
		while (getline(guide_file, input)) {
			cout << input << endl;
		}
		guide_file.close();
	}
}

// TODO Sell Items Empty
//void command_repo::sell_items () {
//
//}

void get_user_information (character &player);

void get_class (character &player);

void set_initial_income (character &player);

void command_repo::new_game () {
	get_user_information(player); // Dereference the object
}

void get_user_information (character &player) {
	cout << "Name of character:  ";
	string ch_name;
	getline(cin, ch_name);
	while (ch_name.empty()) {
		cout << "Field is empty" << endl;
		cout << "Try again:   " << endl;
		getline(cin, ch_name);
	}

	player.set_name(ch_name);

	cout << "\n";

	get_class(player);
}

void get_class (character &player) {
	cout << "Options:  " << endl;
	cout << "\tBaker.======== 1" << endl;
	cout << "\tBusiness.===== 2" << endl;
	cout << "\tCommoner.===== 3" << endl;
	cout << "Choose class:  " << endl;
	int option = 0;
	cin >> option;

	while (option <= 0 || option > 3 || cin.fail()) {
		cout << "Invalid option. " << endl;
		cout << "Try again. " << '\n' << endl;
		cin.clear();

		// std::streamsize: type representing the size and count of characters in the buffer.
		// numeric_limit: is used to determine the size limit of a type.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Choose class:   ";
		cin >> option;
	}

	string c_class;
	enum class_option {
		baker = 1,
		business,
		commoner,
	};

	switch (option) {
		case class_option::baker :
			cout << "Baker class" << endl;
			c_class = "Baker";
			player.set_class(c_class);
			break;

		case class_option::business :
			cout << "Business Class" << endl;
			c_class = "Business";
			player.set_class(c_class);
			break;

		case class_option::commoner :
			cout << "Commoner class" << endl;
			c_class = "Commoner";
			player.set_class(c_class);
			break;

		default:
			break;
	}

	set_initial_income(player);
}

void set_initial_income (character &player) {
	double init_cap = 0;
	if (player.get_class_type() == "Baker") init_cap = 50.00f;
	else if (player.get_class_type() == "Business") init_cap = 100.0f;
	else if (player.get_class_type() == "Commoner") init_cap = 15.0f;

	player.set_initial_capital(init_cap);
}



