// Copyright [2016] <Vex Woo>

#include <iostream>
#include <string>


int main(int argc, const char *argv[]) {
    char c_string[] = "Hello";
    std::string s_string = c_string;   // convert c-string to string

    std::cout << s_string;             // printed as a library string
    std::cout << s_string.c_str();     // printed as a c-string
    return 0;
}
