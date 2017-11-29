#include <iostream>
#include <random>
#include <algorithm>
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
        map<string, double> list;
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
};


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

void list_commands() {
        array<string, 10> comm_list;
        cout << "=========================================================================" << endl;
        cout << "=                             List of Commands                          =" << endl;
        cout << "=========================================================================" << endl;
        comm_list[0] = "my-info --> View your information";
        comm_list[1] = "sell-items --> Sell items you don't need anymore.";
        comm_list[2] = "buy-items --> Buy items evadable in the city or other merchants";
        comm_list[3] = "expand-env --> With enough money, expand your environment to boost income";
        comm_list[4] = "clear --> Clear the screen";
        comm_list[5] = "show-items --> Show a list in detail of the items you currently have";
        for (auto &command: comm_list) {
                cout << command << endl;
        }
}

void clear_screen() {
        system("clear");
}


void buy_item() {
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

        int land = 0;
        int meat = 0;
        int bread = 0;
        int rest = 0;
        int building = 0;
        int wood = 0;

        array<string, 3> ev_items;
        for (auto &ev_item : ev_items) {
                int rval = static_cast<int>(rand() % stock_item.size() - 1);
                ev_item = stock_item[rval];
                switch (rval) {
                        case 0:
                                land++;
                                break;
                        case 1:
                                building++;
                                break;
                        case 2:
                                wood++;
                                break;
                        case 3:
                                rest++;
                                break;
                        case 4:
                                bread++;
                                break;
                        case 5:
                                meat++;
                                break;
                        default:
                                break;
                }

        }


        double price = 0.00f;
        for (const auto &ev_item : ev_items) {
                if (ev_item == "Bread") {
                        price = 4.00f;
                } else if (ev_item == "Broken Building") {
                        price = 500.00f;
                } else if (ev_item == "Rusted Wood") {
                        price = 10.00f;
                } else if (ev_item == "Meat") {
                        price = 7.00f;
                } else if (ev_item == "Closed Down Restaurant") {
                        price = 250.00f;
                } else if (ev_item == "Rusted Wood") {
                        price = 10.00f;
                }
                cout << ev_item << "-->" << price << endl;
        }
        cout << "\n";

        cout << "Enter \'cancel\' to cancel" << endl;
        cout << "Enter \'return\' to the main menu" << endl;
        cout << "Enter the name of the item you will purchase: ";
        cout << "\n";

        string option = " ";
        getline(cin, option);
        while (option != "cancel" || option != "return") {
                for (auto &item: ev_items) {
                        if (option == item) {
                                cout << item << "--> " << land << ": " << price << endl;
                                break;
                        }else if (ev_items.end()){
                                cout << "Item: " << option << " is not in the inventory." << endl;
                        }
                }
                option.empty();
                getline(cin, option);
        }
}

//void sell_items(map<string, double> &list) {
//        if (list.empty()) {
//                cout << "\tThe list is empty" << endl;
//                cout << "\tCome back when you have bought something" << endl;
//                return;
//        }
//
//        for (auto & item: list){
//                cout << item.first << ": " << item.second << "X--count of item";
//        }
//
//        cout << "Enter the name of the item you would like to sell" << endl;
//        cout << "\t";
//        string item_name;
//        getline(cin, item_name);
//        int count = 0;
//        cout << "How many are you selling?:";
//        cin >> count;
//}

int main() {
        intro_screen();
        cout << "Enter command->>  \n";
        cout << "Enter \'help\' for list of commands." << endl;
        cout << "Enter \'exit\' to close the console." << endl;

        character pl;
        get_user_information(pl);
        string command;
        cin.ignore();
        cout << "Enter command:: ";
        getline(cin, command);
        while (command != "exit") {
                cout << "\n";
                if (command == "help") list_commands();
                if (command == "my-info") {
                        pl.info();
                }
                if (command == "clear") {
                        clear_screen();
                }
                if (command == "sell-items") {

                }
                if (command == "buy-items") {
                        buy_item();
                }
                if (command == "expand-env") {
                        // Expand env
                }else {
                        cout << "Command not found. " << endl;
                        list_commands();
                }
                
                command.empty();
                cout << "Enter command:: ";
                getline(cin, command);
                cout << "\n";
        }

        return 0;
}