//
// Created by jeandsmith on 12/28/17.
//

#include "../Headers/economy_controller.h"
#include "../Headers/input_check.h"

void economy_controller::set_list_of_items() {
    list.emplace("Dry Land", 450.00f);
    list.emplace("Broken Building", 200.00f);
    list.emplace("Rusted Wood", 20.00f);
    list.emplace("Closed Down Restaurant", 150.00f);
    list.emplace("Bread", 5.00f);
    list.emplace("Meat", 10.00f);
}


void economy_controller::get_item_list() const {
    // O(n)
    for (auto &item: list) {
        printf("\t\tItem[%s  -  $ %.2lf] \n", item.first.c_str(), item.second);
    }

    cout << '\n';
}

void economy_controller::pur_items(std::unique_ptr<character> &player) {
    printf("\tItem[name - cost]: \n");
    set_list_of_items();
    get_item_list();

    printf("Enter \'cancel\' to cancel \n");
    printf("Enter \'return\' to the main menu \n");
    printf("Enter the name of the items you will purchase: \n");
    printf("\n");

    string user_option{};
    getline(cin, user_option);
    user_option = input_check::format_string(user_option);

    //TODO: The program does not check options after the first wrong input.
    while (user_option != "return" || user_option != "cancel") {

        for (auto &item: list) {
            if (user_option == item.first) {
                int count = 1 + rand() % 10;
                printf("\t\tItem[%s  -  $ %.2lf] \n", item.first.c_str(), item.second);

                printf("How many Items: \n");
                int item_count = 0;
                cin >> item_count;
                cin.ignore();
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
                    printf("You do not have enough money. ");
                    goto bottom;
                }

                // Process transaction
                double cost = item_count * item.second;
                if (cin.fail()) {
                    printf("\tNothing Purchased: ");
                } else {
                    printf("\tItem Purchased: %s", item.first.c_str());
                }
                player->deduct_cost(cost);
                printf("\n\tCost: $%.2lf  \t\t\n \tIncome-Left: $%.2lf\n", cost, player->income());
                break;

            } else {
                printf("Nothing found. ");
            }
        }


        bottom:
        printf("Enter another item name or enter return >> ");
        cin.clear();
        cin.ignore(256, '\n');
        getline(cin, user_option);
    }
}
