#include <ncurses/ncurses.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

char login(const std::string& username, const std::string& password) {
    std::ifstream file("user_data.txt");
    if (!file.is_open()) {
        return 'N';
    }

    std::string line;
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string file_username, file_password;

        if (iss >> file_username >> file_password) {

            std::cout << "File Username: " << file_username << ", File Password: " << file_password << std::endl;
            

            if (username == file_username && password == file_password) {
                return 'Y';
            }
        }
    }

    return 'N';
}
