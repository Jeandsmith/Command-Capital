#include <iostream>
#include <random>
#include <fstream>
#include <memory>

#include "../Headers/input_check.h"
#include "../Headers/economy_controller.h"
#include "../Headers/command_repo.h"
#include "../Headers/console.h"

using namespace std;

// Display the game screen
void intro_screen() {
    fstream title_screen{R"(../text_files/intro.txt)", ios::in};

    if (!title_screen.is_open()) {
        cout << "The file could not be open" << endl;
        return;
    } else {
        string input;
        while (getline(title_screen, input)) {
            cout << input << endl;
        }
    }

    title_screen.close();
}

void show_instructions() {
    ifstream ins{R"(../text_files/instructions.txt)"};
    if (ins.fail()) {
        cout << "Could not open" << endl;
    } else {
        while (!ins.eof()) {
            string line;
            getline(ins, line);
            cout << line << endl;
        }
    }

    ins.close();
}


int main() {
    intro_screen();
    show_instructions();
    srand(static_cast<unsigned>(time(nullptr)));
    unique_ptr<character> player{new character()}; //Value initializer syntax {class(direct initializer syntax)}
    unique_ptr<command_repo> command_r{new command_repo()};

    // Check if there is player information the player data file
    fstream player_data{R"(../text_files/saved_game_file.txt)", ios::in};

    // Check if the file fail to open.
    if (player_data.fail()) {
        printf("The file does not exist \n");
        player_data.open(R"(../text_files/saved_game_file.txt)", ios::out);
    }

    player_data.seekg(0, ios::end); // Move the reading pos to the end of the file.
    if (player_data.tellg() == 0.0) { // Return the size of bytes in the files (chars = 1 byte)
        printf("\n");
        command_r->new_game();
    } else {
        player_data.seekg(0, ios::beg); // go back to the beginning of the file.
        console::log("Profile loaded!");
        string data{};
        vector<string> saved_data;
        saved_data.reserve(3);
        while (getline(player_data, data)) {
            saved_data.push_back(data);
        }
        player->set_name(saved_data[0]);
        player->set_class(saved_data[1]);
        double init_income{stod(saved_data[2])};
        player->set_initial_capital(init_income);
        player_data.close();
    }

    // Because I moved the player, to the command repo, this was not running.
    printf("Welcome: %s \n", player->get_name().c_str());
    command_r->set_player(player);
    printf("Enter command:: \n");
    string command;
    getline(cin, command);


    //TODO: Duplicate cout
    while (input_check::format_string(command) != "exit") {
        command_r->execute_command(command);
        printf("\n");

        printf("Enter Command:: \n");
        getline(cin, command);
    }

    player.release();
    command_r.release();
    return 0;
}