//
// Created by jeandsmith on 12/3/17.
//

#ifndef SPACE_MARINE_CHARACTER_H
#define SPACE_MARINE_CHARACTER_H

#include "iostream"
#include <string>

using namespace std;

class Character {
    private:
	string c_name = " ";
	string c_class = " ";
	double initial_income = 0;

    public:
	Character() = default;

	double init_incom();

	string class_type();

	void info();

	void deduct_cost(double cost);

	void set_name(string name);

	void set_class(string classs);
};


#endif //SPACE_MARINE_CHARACTER_H
