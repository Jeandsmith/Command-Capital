#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <string>
#include <map>
#include <array>

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


struct character {
        string c_name = " ";
        string c_class = " ";
        double initial_income = 0;

        character() = default;

        void set_name(string name) {
                this->c_name = move(name);
        }

        void set_class(string c_class) {
                this->c_class = move(c_class);
        }

        void info() {
                cout << "Name   --> " << c_name << endl;
                cout << "Class  --> " << c_class << endl;
                cout << "Income --> " << initial_income << endl;
        }

        void deduct_cost(double cost) {
                initial_income -= cost;
        }
};

struct command_rep {

        void end_game() {
                cout << "\tGame-Terminated." << endl;
                cout << "\tStats: " << endl;
                cout << "\t\tTime-Played: " << endl;
//        TODO: Implement the stat of the player.
                exit(EXIT_SUCCESS);
        };

        void clear_screen() {
                system("clear");
        };

        void list_commands() {
                cout << "=========================================================================" << endl;
                cout << "=                             List of Commands                          =" << endl;
                cout << "=========================================================================" << endl;
                cout << "my-info --> View your information" << endl;
                cout << "sell-items --> Sell items you don't need anymore." << endl;
                cout << "buy-items --> Buy items evadable in the city or other merchants" << endl;
                cout << "expand-env --> With enough money, expand your environment to boost income" << endl;
                cout << "clear --> Clear the screen" << endl;
                cout << "show-items --> Show a list in detail of the items you currently have" << endl;
        };

        void sell_items(map<string, double> &list) {

        };

        void buy_item(map<string, double> &items, character &pl) {
                unsigned seed{static_cast<unsigned>(time(nullptr))};
                srand(seed);
                vector<string> stock_item{
                        "Dry Land",
                        "Broken Building",
                        "Rusted Wood",
                        "Closed Down Restaurant",
                        "Bread",
                        "Meat"
                };

                items["Dry Land"] = 450.00f;
                items["Broken Building"] = 200.00f;
                items["Rusted Wood"] = 20.00f;
                items["Closed Down Restaurant"] = 150.00f;
                items["Bread"] = 5.00f;
                items["Meat"] = 10.00f;

                cout << "\tItem[name - cost]: " << endl;
                for (auto &it: items) {
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

                        for (auto &item: items) {

                                if (option == item.first) {
                                        cout << item.first << "--> $" << item.second
                                             << "  X" << count << endl;

                                        if (count > 1) {
                                                cout << "\tNum of items to buy: ";
                                                int item_count;
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
                                                if (pl.initial_income < item_count * item.second) {
                                                        cout << "You do not have enough money. " << endl;
                                                        cout << "Try again." << endl;
                                                        goto get_count;
                                                }

                                                // Process transaction
                                                double cost = item_count * item.second;
                                                cout << "Purchased: " << endl;
                                                pl.deduct_cost(static_cast<double>(cost));
                                                cout << "Details: \n\t Cost: $" << cost
                                                     << "\t\n" << "Income-Left: " << pl.initial_income << endl;

                                        } else {
                                                pl.deduct_cost(static_cast<double>(item.second));
                                        }
                                        goto bottom;

                                } else if (item.first == stock_item[stock_item.size() - 1] && option != item.first) {
                                        cout << "\tItem: " << option << " is not in the inventory." << endl;
                                }
                        }

                        if (option == "exit") {
                                end_game();
                        }

                        bottom:
                        option.empty();
                        cout << "\tEnter item name >> ";
                        getline(cin, option);
                }

                if (option == "return") {
                        return;
                }
        };

}COMMAND;

void get_user_information(character &pl) {
        get_name:
        cout << "Name of character: ";
        string ch_name;
        getline(cin, ch_name);

        if (ch_name == " " || ch_name.empty()) {
                cout << "Field is empty" << endl;
                cout << "Try again: " << endl;
                goto get_name;
        } else {
                void get_class(character &);
                get_class(pl);
                pl.set_name(ch_name);
                if (pl.c_class == "Baker") pl.initial_income = 50.0f;
                else if (pl.c_class == "Business") pl.initial_income = 100.0f;
                else if (pl.c_class == "Commoner") pl.initial_income = 15.0f;
        }

        cout << "\n";
}

void get_class(character &pl) {

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

void process_command(const string &c, character &pl, map<string, double> &item_con) {
        vector<string> commands;
        commands.emplace_back("help");
        commands.emplace_back("my-info");
        commands.emplace_back("clear");
        commands.emplace_back("sell-items");
        commands.emplace_back("buy-items");
        commands.emplace_back("expand-env");

        int co = 1;

        // TODO: Complete the function pointer
        map <string, void(*)()> pmetho;
        pmetho["help"] = &COMMAND.list_commands;

        for (const auto &command: commands) {
//                if (command == "help") list_commands();
//
//                if (command == "my-info") {
//                        pl.info();
//                }
//
//                if (command == "clear") {
//                        clear_screen();
//                }
//
//                if (command == "sell-items") {
//
//                }
//
//                if (command == "buy-items") {
//                        buy_item(item_con, pl);
//                }
//
//                if (command == "expand-env") {
//                        // Expand env
//                } else {
//                        cout << "Command: " << command << " not-found." << endl;
//                        list_commands();
//                }
                if (c == command) {

                }
        }
}

int main() {
        intro_screen();
        cout << "Enter command->>  \n";
        cout << "Enter \'help\' for list of commands." << endl;
        cout << "Enter \'exit\' to close the console." << endl;

        map<string, double> item_con;
        character pl;
        get_user_information(pl);
        string command;
        cin.ignore();
        cout << "Enter command:: ";
        command.empty();
        getline(cin, command);


        while (command != "exit") {

                cout << "\n";


                cout << "\n";
                command.empty();
                cout << "Enter command:: ";
                getline(cin, command);
                cout << "\n";
        }

        return 0;
}