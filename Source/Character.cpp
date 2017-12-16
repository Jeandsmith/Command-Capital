//
// Created by jeandsmith on 12/3/17.
//

#include "../Headers/Character.h"

double Character::init_incom () {
	return this->initial_income;
}

void Character::set_initial_capital (double cap) {
	this->initial_income = cap;
}

string Character::get_class_type () {
	return this->c_class;
}

string Character::get_name(){
	return this->c_name;
}

void Character::set_name (string name) {
	this->c_name = move(name);
}

void Character::set_class (string c_classs) {
	this->c_class = move(c_classs);
}

void Character::get_info () {
	cout << "Name   --> " << c_name << endl;
	cout << "Class  --> " << c_class << endl;
	cout << "Income --> " << initial_income << endl;
}

void Character::deduct_cost (double cost) {
	this->initial_income -= cost;
}