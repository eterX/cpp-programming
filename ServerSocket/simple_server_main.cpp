# Copyright[2002] <Copyright Rob Tougher>

#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>


int main(int argc, const char *argv[]) {
  try {
    // Create the socket
    ServerSocket server(30000);

    while (true) {
      ServerSocket new_sock;
      server.accept(new_sock);

      // rest of code -
      // read request, send reply, etc...
      try {
        while (true) {
          std::string data;
          new_sock >> data;
          new_sock << data;
        }
      }
      catch (SocketException&) {}
    }
  }
  catch (SocketException& e) {
    std::cout << "Exception was caught:" << e.description() << "\nExiting\n";
  }
  return 0;
}


// References: http://tldp.org/LDP/LG/issue74/tougher.html
