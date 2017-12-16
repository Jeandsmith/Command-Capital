//
// Created by jeandsmith on 12/3/17.
//

#include <fstream>
#include "../Headers/Command_Repo.h"

Command_Repo::Command_Repo (Character *current_player): player(current_player) {}



void Command_Repo::end_game () {
	cout << "\tGame-Terminated." << endl;
	cout << "\tStats: " << endl;
	cout << "\t\tTime-Played: " << endl;
//        TODO: Implement the stat of the player.
	exit(EXIT_SUCCESS);
};



// A map of functions
void Command_Repo::execute_command (string &command) {
	typedef void (Command_Repo::*function_pointer) ();
	typedef unordered_map<string, function_pointer> command_map;

	// Save pointers of the function to the key/pointer(value) map
	command_map c_map;
	c_map.emplace("help", &Command_Repo::list_commands);
	c_map.emplace("clear", &Command_Repo::clear_screen);
	c_map.emplace("my-info", &Command_Repo::give_info);
	c_map.emplace("save-game", &Command_Repo::save_game);

	for (auto & com: c_map){
		if (com.first == command){ // If the command is found in the map
			function_pointer pt = c_map[com.first]; // Make a pointer to the function saved as s value of the command
			(this->*pt)(); // Run the function in this instance of the class.
			break;
		}else {
			if (c_map.find(command) == c_map.end()){
				cout << "Command not found:: " << endl;
			}
		}
	}

}


void Command_Repo::save_game () {
	cout << "Saving Game" << endl;
	fstream save_game_file {R"(../text_files/saved_game_file.txt)", ios::out };
	if (save_game_file.fail()){
		cout << "Error Occurred" << endl;
	}else {
		save_game_file << player->get_name() << "\n";
		save_game_file << player->get_class_type() << "\n";
		save_game_file << player->init_incom() << "\n";
		cout << "Saved game" << endl;
	}
}


void Command_Repo::give_info () {
	player->get_info();
}


void Command_Repo::clear_screen () {
	system("clear");
};

void Command_Repo::list_commands () {
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

void Command_Repo::sell_items () {
	// TODO Sell Items Empty
}

// I don't think will be used for anything else but to the set the values of the list.
void Command_Repo::set_list () {

	list.emplace("Dry Land", 450.00f);
	list.emplace("Broken Building", 200.00f);
	list.emplace("Rusted Wood", 20.00f);
	list.emplace("Closed Down Restaurant", 150.00f);
	list.emplace("Bread", 5.00f);
	list.emplace("Meat", 10.00f);
}

//struct Purchases{
//
//	void display_items(unordered_map<string, double> list){
//		cout << "\tItem[name - cost]: " << endl;
//		for (auto &it: list) {
//			cout << "\t\tItem[" << it.first << " - " << "$" << it.second << "]" << endl;
//		}
//		cout << "\n";
//	}
//
//	void Command_Repo::buy_item () {
//		vector<string> stock_item{
//			"Dry Land",
//			"Broken Building",
//			"Rusted Wood",
//			"Closed Down Restaurant",
//			"Bread",
//			"Meat"
//		};
//
////		TODO: Check that this works
//		void display_items(unordered_map<string, double> list);
//		display_items(list);
//
//		cout << "Enter \'cancel\' to cancel" << endl;
//		cout << "Enter \'return\' to the main menu" << endl;
//		cout << "Enter the name of the items you will purchase: ";
//		cout << "\n";
//
//		int count = 1 + rand() % 10;
//		string option;
//		getline(cin, option);
//		while (option != "return") {
//
//			for (auto &item: list) {
//
//				if (option == item.first) {
//					cout << item.first << "--> $"
//					     << item.second << "  X"
//					     << count << endl;
//
//					if (count > 1) {
//						cout << "\tEnter the number of items to buy: ";
//						int item_count = 0;
//						get_count:
//						cin >> item_count;
//
//						// Handle input while it is less than 0
//						while (item_count <= 0) {
//
//							if (item_count == 0) {
//								cout << "\tYou bought nothing."
//								     << endl;
//								goto bottom;
//							} else {
//								cout << "\tThe count cannot be less than 0"
//								     << endl;
//								cout << "Try again" << endl;
//								goto get_count;
//							}
//						}
//
//						// Handle the input if it is greater then current count of items
//						if (item_count >= count) {
//							item_count = count;
//						}
//
//						// Check if the user has enough money to buy
//						if (player.init_incom() < item_count * item.second) {
//							cout << "You do not have enough money. " << endl;
//							cout << "Try again." << endl;
//							goto get_count;
//						}
//
//						// Process transaction
//						double cost = item_count * item.second;
//						cout << "Purchased: " << endl;
//						player.deduct_cost(cost);
//						cout << "Details: \n\t Cost: $" << cost
//						     << "\t\n" << "Income-Left: "
//						     << player.init_incom() << endl;
//
//					} else {
//						player.deduct_cost(static_cast<double>(item.second));
//					}
//					goto bottom;
//
//				} else if (item.first == stock_item[stock_item.size() - 1]
//				           && option != item.first) {
//
//					std::cout << "\tItem: " << option
//					          << " is not in the inventory." << std::endl;
//				}
//			}
//
//			if (option == "exit") {
//				end_game();
//			}
//
//			bottom:
//			cout << "\tEnter item name >> ";
//			getline(cin, option);
//		}
//
//		if (option == "return") {
//			return;
//		}
//	};
//};