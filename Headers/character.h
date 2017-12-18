//
// Created by jeandsmith on 12/3/17.
//

#ifndef SPACE_MARINE_CHARACTER_H
#define SPACE_MARINE_CHARACTER_H

#include "iostream"
#include <string>

using namespace std;

class character {
    private:
	string c_name;
	string c_class;
	double initial_income = 0;

    public:
	explicit character () = default;

	double income ();

	string get_class_type ();

	void get_info ();

	string get_name ();

	void deduct_cost (double cost);

	void set_name (string & name);

	void set_class (string & classs);

	void set_initial_capital (double cap);
};


#endif //SPACE_MARINE_CHARACTER_H
