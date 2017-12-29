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
    void pur_items(std::unique_ptr<character> &player);
};


#endif //SPACE_MARINE_ITEMCONTROLLER_H
