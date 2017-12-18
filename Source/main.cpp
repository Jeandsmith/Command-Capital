#include <iostream>
#include <random>
#include <fstream>

#include "../Headers/economy_controller.h"
#include "../Headers/command_repo.h"

using namespace std;

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

void show_instructions () {
	ifstream ins{R"(../text_files/instructions.txt)"};
	if (ins.fail()) {
		cout << "Could not open" << endl;
	} else {
		while (!ins.eof()) {
			string line;
			getline(ins, line);
			cout << line << endl;
		}
	}

	ins.close();
}


int main () {
	intro_screen();
	show_instructions();
	srand(static_cast<unsigned>(time(nullptr)));
	auto *player = new character();
	command_repo command_r;

	// Check if there is player information the player data file
	fstream player_data{R"(../text_files/saved_game_file.txt)", ios::in};

	// Check if the file fail to open.
	if (player_data.fail()) {
		cout << "The file does not exist" << endl;
		player_data.open(R"(../text_files/saved_game_file.txt)", ios::out);
	}

	player_data.seekg(0, ios::end); // Move the reading pos to the end of the file.
	if (player_data.tellg() == 0) { // Return the size of bytes in the files (chars = 1 byte)
		cout << '\n';
		command_r.new_game();
	} else {
		player_data.seekg(0, ios::beg); // go back to the beginning of the file.
		cout << "File Loaded" << endl;
		string data;
		vector<string> saved_data;
		while (getline(player_data, data)) {
			saved_data.push_back(data);
		}
		player->set_name(saved_data[0]);
		player->set_class(saved_data[1]);
		player->set_initial_capital(stod(saved_data[2]));
		command_r.set_player(*player);
		player_data.close();
	}

	cout << "Welcome: " << player->get_name() << endl;
	cout << "Enter command:: ";
	string command;
	getline(cin, command);


	//TODO: Duplicate cout
	while (command != "exit") {
		command_r.execute_command(command);
		cout << "\n";

		cout << "Enter Command: " << endl;
		getline(cin, command);
	}

	delete player;
	return 0;
}