//
// Created by jeandsmith on 12/3/17.
//

#include <fstream>
#include "../Headers/command_repo.h"
#include "../Headers/console.h"

command_repo::command_repo(){
//      clear_screen();
      set_commands();
}

void command_repo::set_player(unique_ptr<character> &current_player) {
      this->_unique_player = std::move(current_player);
}

void command_repo::set_commands() {
      // Save pointers of the function to the key/pointer(value) map
      c_map.emplace("help", &command_repo::list_commands);
      c_map.emplace("clear", &command_repo::clear_screen);
      c_map.emplace("my-info", &command_repo::give_info);
      c_map.emplace("save-game", &command_repo::save_game);
      c_map.emplace("buy-items", &command_repo::buy_item);
      c_map.emplace("new-game", &command_repo::new_game);

}

void command_repo::execute_command(const char * command) {
     if (c_map.empty()){
           console::log("The command lib is empty");
           return;
     }else {
           for (auto &com: c_map) {
                 if (com.first == std::string(command)) { // If the command is found in the map
                       function_pointer pt = c_map[com.first]; // Make a pointer to the function saved as s value of the command
                       (this->*pt)(); // Run the function pointed to this member function.
                       break;
                 }
           }
     }
}

void command_repo::save_game() {
      fstream save_game_file{R"(../text_files/saved_game_file.txt)", ios::out};
      if (save_game_file.fail()) {
            console::log("Error Occurred");
      } else {
            save_game_file << _unique_player->get_name() << "\n";
            save_game_file << _unique_player->get_class_type() << "\n";
            save_game_file << _unique_player->income() << "\n";
            console::log("Game Saved");
            save_game_file.close();
      }
}

void command_repo::buy_item() {
      _controller->pur_items(_unique_player);
};

void command_repo::give_info() {
      _unique_player->get_info();
}

void command_repo::clear_screen() {
      console::log("clear_screen()");
      system("clear");
}

void command_repo::list_commands() {
      fstream guide_file{"../text_files/game_guide.txt", ios::out | ios::in};
      if (guide_file.fail()) {
            throw "Guide not found";
      } else {
            string input;
            while (getline(guide_file, input)) {
                  cout << input << endl;
            }
            guide_file.close();
      }
}

// TODO Sell Items Empty
//void command_repo::sell_items () {
//
//}

void command_repo::new_game() {
      get_user_information(_unique_player); // Dereference the object
}

void command_repo::get_user_information(std::unique_ptr<character> &player) {
      cout << "Name of character:  ";
      string ch_name;
      getline(cin, ch_name);
      while (ch_name.empty()) {
            cout << "Field is empty" << endl;
            cout << "Try again:   " << endl;
            getline(cin, ch_name);
      }

      player->set_name(ch_name);

      cout << "\n";

      get_class(player);
}

void command_repo::get_class(std::unique_ptr<character> &player) {
      printf("Options:  \n");
      printf("\tBaker.======== 1  \n");
      printf("\tBusiness.===== 2 \n");
      printf("\tCommoner.===== 3 \n");
      printf("\tChoose class:   \n");

      uint32_t option = 0;
      cin >> option;
      cin.ignore();
      while (option <= 0 || option > 3 || cin.fail()) {
            printf("Invalid option. \n");
            printf("Try again. \n");

            // std::streamsize: type representing the size and count of characters in the buffer.
            // numeric_limit: is used to determine the size limit of a type.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("Choose class:   ");
            cin >> option;
            cin.ignore();
      }

      string c_class;
      enum class_option {
            baker = 1,
            business,
            commoner,
      };

      switch ((int)option) {
            case class_option::baker :
                  printf("Baker class \n");
                  c_class = "Baker";
                  player->set_class(c_class);
                  break;

            case class_option::business :
                  printf("Business Class \n");
                  c_class = "Business";
                  player->set_class(c_class);
                  break;

            case class_option::commoner :
                  printf("Commoner class \n");
                  c_class = "Commoner";
                  player->set_class(c_class);
                  break;

            default:
                  break;
      }

      void set_initial_income(std::unique_ptr<character> &player);
      set_initial_income(player);
}

void set_initial_income(std::unique_ptr<character> &player) {
      double init_cap = 0;
      if (player->get_class_type() == "Baker") init_cap = 50.00f;
      else if (player->get_class_type() == "Business") init_cap = 100.0f;
      else if (player->get_class_type() == "Commoner") init_cap = 15.0f;

      player->set_initial_capital(init_cap);
}



