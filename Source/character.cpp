//
// Created by jeandsmith on 12/3/17.
//

#include "../Headers/character.h"

double character::income () {
	return this->initial_income;
}

void character::set_initial_capital (double cap) {
	this->initial_income = cap;
}

string character::get_class_type () {
	return this->c_class;
}

string character::get_name(){
	return this->c_name;
}

void character::set_name (string & name) {
	this->c_name = name;
}

void character::set_class (string & c_classs) {
	this->c_class = c_classs;
}

void character::get_info () {
	cout << "Name   --> " << c_name << endl;
	cout << "Class  --> " << c_class << endl;
	cout << "Income --> " << initial_income << endl;
}

void character::deduct_cost (double cost) {
	this->initial_income -= cost;
}