// Copyright[2016] <Vex Woo>

#include <iostream>

/*
  Unions allow one portion of memory to be accessed as different data types.
  Its declaration and use is similar to the one of structures,
*/

int main(int argc, const char* argv[]) {
    union version_t {
        int version;
        struct {
          short min_ver;
          short max_ver;
        };
    };

    version_t ver;
    ver.version = 0x00020001;
    printf("Version: %08x\n", ver.version);
    printf("Min Ver: %04x\n", ver.min_ver);
    printf("Max Ver: %04x\n", ver.max_ver);
    return 0;
}
