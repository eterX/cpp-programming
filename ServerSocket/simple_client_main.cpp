# Copyright[2002] <Copyright Rob Tougher>

#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main(int argc, const char *argv[]) {
  try {
    ClientSocket client_socket("localhost", 30000);
    std::string reply;
    try {
      client_socket << "Test message.";
      client_socket >> reply;
    } catch (SocketException&) {}

    std::cout << "The response from the server:\n\"" << reply << "\"\n";
  }
  catch (SocketException& e) {
    std::cout << "Exception was caught:" << e.description() << "\n";
  }
  return 0;
}

// References: http://tldp.org/LDP/LG/issue74/tougher.html
