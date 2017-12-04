//
// Created by jeandsmith on 12/3/17.
//

#include "Headers/Character.h"

double Character::init_incom() {
	return this->initial_income;
}

string Character::class_type() {
	return this->c_class;
}

void Character::set_name(string name) {
	this->c_name = move(name);
}

void Character::set_class(string c_classs) {
	this->c_class = move(c_classs);
}

void Character::info() {
	cout << "Name   --> " << c_name << endl;
	cout << "Class  --> " << c_class << endl;
	cout << "Income --> " << initial_income << endl;
}

void Character::deduct_cost(double cost) {
	this->initial_income -= cost;
}