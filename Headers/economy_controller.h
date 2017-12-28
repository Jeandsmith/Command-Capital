//
// Created by jeandsmith on 12/17/17.
//

#ifndef SPACE_MARINE_ITEMCONTROLLER_H
#define SPACE_MARINE_ITEMCONTROLLER_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <list>
#include <limits>
#include <bits/unique_ptr.h>

#include "character.h"

using namespace std;

class economy_controller {
private:
    unordered_map<string, double> list;

    void set_list_of_items();

public:
    void get_item_list() const;

    void pur_items(std::unique_ptr<character> &player) {
        printf("\tItem[name - cost]: \n");
        set_list_of_items();
        get_item_list();

        printf("Enter \'cancel\' to cancel \n");
        printf("Enter \'return\' to the main menu \n");
        printf("Enter the name of the items you will purchase: \n");
        printf("\n");

        string user_option;
        getline(cin, user_option);
        //TODO: The program does not check options after the first wrong input.
        while (user_option != "return") {

            for (auto &item: list) {
                if (user_option == item.first) {
                    int count = 1 + rand() % 10;
                    cout << '[' << item.first << " -- $" << item.second << "] X"
                         << count << endl;

                    cout << "How many Items: ";
                    int item_count = 0;
                    cin >> item_count;
                    while (item_count <= 0 || cin.fail()) {
                        cout << "\tInvalid input" << endl;
                        cout << "\tTry again:  ";
                        while (!(cin >> item_count)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }

                    if (item_count >= count) {
                        item_count = count;
                    }

                    // Check if the user has enough money to buy
                    if (player->income() < item_count * item.second) {
                        cout << "You do not have enough money. " << endl;
                        goto bottom;
                    }

                    // Process transaction
                    double cost = item_count * item.second;
                    if (cin.fail()) {
                        cout << "\tNothing Purchased: " << endl;
                    } else {
                        cout << "\tItem Purchased: " << item.first << endl;
                    }
                    player->deduct_cost(cost);
                    cout << "\n\tCost: $" << cost << "\t\t\n" << "\tIncome-Left: $"
                         << player->income() << endl;

                    break;

                } else {
                    cout << "Nothing found. " << endl;
                }
            }


            bottom:
            cout << "Enter another item name or enter return >> ";
            cin.clear();
            cin.ignore(256, '\n');
            getline(cin, user_option);
        }
    }
};


#endif //SPACE_MARINE_ITEMCONTROLLER_H
