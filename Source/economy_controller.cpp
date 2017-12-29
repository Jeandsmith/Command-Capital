//
// Created by jeandsmith on 12/28/17.
//

#include "../Headers/economy_controller.h"

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
        cout << "\t\tItem[" << item.first << " - "
             << "$" << item.second << "]" << endl;
    }

    cout << '\n';
}
