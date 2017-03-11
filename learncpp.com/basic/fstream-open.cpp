// Copyright[2016] <Vex Woo>

#include <iostream>
#include <fstream>
#include <string>

/*

    - ofstream: Stream class to write on files
    - ifstream: Stream class to read from files
    - fstream:  Stream class to both read and write from/to files.

*/

/*
    To check if a file stream was successful opening a file,
    you can do it calling to member [is_open]. This member function returns
    a bool value of true in the case that indeed the stream object is associated
    with an open file, or false otherwise.

 */

void fstream_demo() {
    std::ofstream myfile("example.txt");
    if (myfile.is_open()) {
        myfile << "1. Writing this to a file.\n";
        myfile.close();
    }
}

void ofstream_demo() {
    // std::ofstream myfile("example.txt", std::ios::out);
    std::ofstream myfile("example.txt");
    myfile << "2. Writing this to a file.\n";
    myfile.close();
}

void ifstream_demo() {
    std::string contents;
    // std::ifstream myfile("example.txt" std::ios::in);
    std::ifstream myfile("example.txt");
    if (myfile.is_open()) {
        while (getline(myfile, contents)) {
            std::cout << contents << "\n";
        }
        myfile.close();
    }
}

int main(int argc, const char *argv[]) {
    fstream_demo();
    ofstream_demo();
    ifstream_demo();
    return 0;
}


/*

  ## Open a file

  open(filename, mode);

  ios::in      - Open for input operations
  ios::out     - Open for output operations
  ios::binary  - Open in binary mode
  ios::ate     - Set the initial position at the end of the file. If this flag is not set,
                 the initial position is the beginning of the file.
  ios::app     - All output operations are performed at the end of the file, appending the content to the current content of the file.
  ios::trunc   - If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.

*/
