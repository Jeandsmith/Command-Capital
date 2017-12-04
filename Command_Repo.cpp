//
// Created by jeandsmith on 12/3/17.
//

#include "Headers/Command_Repo.h"

Command_Repo::Command_Repo(Character current_player) {
	this->player = current_player;

}

void Command_Repo::end_game() {
	cout << "\tGame-Terminated." << endl;
	cout << "\tStats: " << endl;
	cout << "\t\tTime-Played: " << endl;
//        TODO: Implement the stat of the player.
	exit(EXIT_SUCCESS);
};

void Command_Repo::execute_command(string & command) {
	point["help"] = this->list_commands;

	if (command == "help" || command == "Help"){
		point[command];
	}
}

void Command_Repo::clear_screen() {
	system("clear");
};

void Command_Repo::list_commands() {
	cout << "=========================================================================" << endl;
	cout << "=                             List of Commands                          =" << endl;
	cout << "=========================================================================" << endl;
	cout << "my-info --> View your information" << endl;
	cout << "sell-items --> Sell items you don't need anymore." << endl;
	cout << "buy-items --> Buy items evadable in the city or other merchants" << endl;
	cout << "expand-env --> With enough money, expand your environment to boost income" << endl;
	cout << "clear --> Clear the screen" << endl;
	cout << "show-items --> Show a list in detail of the items you currently have" << endl;

}

void Command_Repo::sell_items() {}

void Command_Repo::buy_item() {
	vector<string> stock_item{
		"Dry Land",
		"Broken Building",
		"Rusted Wood",
		"Closed Down Restaurant",
		"Bread",
		"Meat"
	};

	list.emplace("Dry Land", 450.00f);
	list.emplace("Broken Building", 200.00f);
	list.emplace("Rusted Wood", 20.00f);
	list.emplace("Closed Down Restaurant", 150.00f);
	list.emplace("Bread", 5.00f);
	list.emplace("Meat", 10.00f);

	cout << "\tItem[name - cost]: " << endl;
	for (auto &it: list) {
		cout << "\t\t" << it.first << " " << "$" << it.second << endl;
	}
	cout << "\n";

	cout << "Enter \'cancel\' to cancel" << endl;
	cout << "Enter \'return\' to the main menu" << endl;
	cout << "Enter the name of the items you will purchase: ";
	cout << "\n";

	int count = 1 + rand() % 10;
	string option;
	getline(cin, option);
	while (option != "return") {

		for (auto &item: list) {

			if (option == item.first) {
				cout << item.first << "--> $"
				     << item.second << "  X"
				     << count << endl;

				if (count > 1) {
					cout << "\tEnter the number of items to buy: ";
					int item_count = 0;
					get_count:
					cin >> item_count;

					// Handle input while it is less than 0
					while (item_count <= 0) {

						if (item_count == 0) {
							cout << "\tYou bought nothing." << endl;
							goto bottom;
						} else {
							cout << "\tThe count cannot be less than 0" << endl;
							cout << "Try again" << endl;
							goto get_count;
						}
					}

					// Handle the input if it is greater then current count of items
					if (item_count >= count) {
						item_count = count;
					}

					// Check if the user has enough money to buy
					if (player.init_incom() < item_count * item.second) {
						cout << "You do not have enough money. " << endl;
						cout << "Try again." << endl;
						goto get_count;
					}

					// Process transaction
					double cost = item_count * item.second;
					cout << "Purchased: " << endl;
					player.deduct_cost(cost);
					cout << "Details: \n\t Cost: $" << cost
					     << "\t\n" << "Income-Left: "
					     << player.init_incom() << endl;

				} else {
					player.deduct_cost(static_cast<double>(item.second));
				}
				goto bottom;

			} else if (item.first == stock_item[stock_item.size() - 1]
			           && option != item.first) {

				std::cout << "\tItem: " << option
				          << " is not in the inventory." << std::endl;
			}
		}

		if (option == "exit") {
			end_game();
		}

		bottom:
		cout << "\tEnter item name >> ";
		getline(cin, option);
	}

	if (option == "return") {
		return;
	}
};