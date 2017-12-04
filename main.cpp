#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <map>
#include <array>
#include <unordered_map>
#include "Headers/Character.h"
#include "Headers/Command_Repo.h"

using namespace std;

void intro_screen() {
	cout << "  ________________   " << "_______" << "       _______ " << "_____    _____" << endl;
	cout << " /    ________    \\" << "|        |" << "    /      \\" << "  \\  \\  /   /" << endl;
	cout << "|     |      |     |" << "|        |" << "   /   /\\  \\" << "  \\  \\/   /" << endl;
	cout << "|     |      |     |" << "|        |" << "  /   /  \\  \\" << "  \\     /" << endl;
	cout << "|     |      |     |" << "|        |" << " /   /    \\  \\" << " |    |" << endl;
	cout << "|     |______/     |" << "|        |" << "---------------" << "|    |" << endl;
	cout << "|                 /" << " |        ----" << "             " << " -----" << endl;
	cout << "|       _________/" << "  |___________|" << endl;
	cout << "|      |" << endl;
	cout << "|      |" << endl;
	cout << "|      |" << endl;
	cout << "|______|" << endl;
}

auto *player = new Character();

void get_user_information() {
	get_name:
	cout << "Name of character: ";
	string ch_name;
	getline(std::cin, ch_name);

	if (ch_name == " " || ch_name.empty()) {
		cout << "Field is empty" << std::endl;
		cout << "Try again: " << std::endl;
		goto get_name;
	} else {
		void get_class(Character &);
		if (player->class_type() == "Baker") player->init_incom() == 50.0f;
		else if (player->class_type() == "Business") player->init_incom() == 100.0f;
		else if (player->class_type() == "Commoner") player->init_incom() == 15.0f;
		player->set_name(ch_name);
		get_class(*player);
	}

	cout << "\n";
}


void get_class(Character &pl) {

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
			break;

		case 2:
			cout << "Business Class" << endl;
			c_class = "Business";
			pl.set_class(c_class);
			break;

		case 3:
			cout << "Commoner class" << endl;
			c_class = "Commoner";
			pl.set_class(c_class);
			break;

		default:
			break;
	}
}

void process_command(string &user_command) {
	vector<string> command_repo;
	command_repo.emplace_back("help");
	command_repo.emplace_back("my-info");
	command_repo.emplace_back("clear");
	command_repo.emplace_back("sell-items");
	command_repo.emplace_back("buy-items");
	command_repo.emplace_back("expand-env");


	// Loop trough all commands
	Command_Repo command_r(*player);
	command_r.execute_command(user_command);

}

int main() {
	unsigned seed{static_cast<unsigned>(time(nullptr))};
	srand(seed);

	intro_screen();
	cout << "Enter command->>  \n";
	cout << "Enter \'help\' for list of commands." << endl;
	cout << "Enter \'exit\' to close the console." << endl;

	get_user_information();


	string command;
	cin.ignore();
	cout << "Enter command:: ";
	command.empty();
	getline(cin, command);


	while (command != "exit") {

		cout << "\n";
		process_command(command);
		cout << "\n";
		cout << "Enter command:: ";
		getline(cin, command);
		cout << "\n";
	}

	return 0;
}