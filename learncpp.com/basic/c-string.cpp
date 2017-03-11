// Copyright[2016] <Vex Woo>

#include <iostream>
#include <string>

/*
 C++ provides following two types of string representations:

   - The C-style character string.
   - The string class type introduced with Standard C++.

 */

/*

  strcpy(s1, s2);  - Copies string s2 into s1
  strcat(s1, s2);  - Concatenates string s2 onto the end of string s1.
  strlen(s1);      - Returns the length of string s1.
  strcmp(s1, s2);  - Returns 0 if s1 and s2 are the same; less than 0 if s1 < s2; greater than 0 if s1 > s2
  strchr(s1, ch);  - Returns a pointer to the first occurrence of character ch in string s1.
  strstr(s1, s2);  - Returns a pointer to the first occurrence of string s1 in string s1.

 */
void c_string(void) {
    char demostr[6] = "12345";
    char copystr[6] = "abcde";

    std::cout << demostr << "\n";
    strcpy(demostr, copystr);
    std::cout << demostr << "\n";

    std::cout << strlen(demostr) << "\n";

    std::cout << strcmp(demostr, demostr) << "\n";
    std::cout << strcmp(demostr, copystr) << "\n";

    std::cout << strchr(demostr, 'c') << "\n";
    std::cout << strstr(demostr, "cde") << "\n";
}


void cplusplus_string(void) {
    std::string demostr("12345");
    std::string copystr("abcdef");

    demostr = copystr;  // similar to strcpy
    std::cout << demostr << "\n";

    std::cout << demostr.size() << "\n";
    std::cout << demostr.length() << "\n";

    std::cout << (demostr == copystr) << "\n";
    std::cout << demostr.find("c") << "\n";

    std::cout << demostr + copystr << "\n";
}

int main(int argc, const char *argv[]) {
    c_string();
    cplusplus_string();
    return 0;
}
