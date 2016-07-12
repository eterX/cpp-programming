// Copyright[2016] <Vex Woo>

#include <iostream>
#include <string>


int main(int argc, const char *argv[]) {
    std::string command;

    std::cout << "Enter [exit] to exit the console" << std::endl;
    do {
        std::cout << "[cmd]: ";
        std::getline(std::cin, command);
    } while (command != "exit");

    return 0;
}
