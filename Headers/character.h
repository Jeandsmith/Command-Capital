//
// Created by jeandsmith on 12/3/17.
//

#ifndef SPACE_MARINE_CHARACTER_H
#define SPACE_MARINE_CHARACTER_H

#include <iostream>
#include <string>

class character {
private:
    std::string _c_name{};
    std::string _c_class{};
    double initial_income = 0;

public:
    explicit character() = default;

    explicit character(std::string & player_name): _c_name(player_name){};

    double income();

    std::string get_class_type() const;

    void get_info() const;

    std::string get_name() const;

    void deduct_cost(double cost);

    void set_name(std::string &name);

    void set_class(std::string &classs);

    void set_initial_capital(double & cap);
};


#endif //SPACE_MARINE_CHARACTER_H
