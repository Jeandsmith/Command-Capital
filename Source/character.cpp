//
// Created by jeandsmith on 12/3/17.
//

#include "../Headers/character.h"

double character::income() {
    return this->initial_income;
}

void character::set_initial_capital(double &cap) {
    this->initial_income = cap;
}

std::string character::get_class_type() const {
    return this->_c_class;
}

std::string character::get_name() const{
    return _c_name;
}

void character::set_name(std::string &name) {
    this->_c_name = std::move(name);
}

void character::set_class(std::string &c_classs) {
    this->_c_class = std::move(c_classs);
}

void character::get_info() const {
    printf("Name   --> %s \n", _c_name.c_str());
    printf("Class  --> %s \n", _c_class.c_str());
    printf("Income --> $%.2lf \n", initial_income);
}

void character::deduct_cost(double cost) {
    this->initial_income -= cost;
}