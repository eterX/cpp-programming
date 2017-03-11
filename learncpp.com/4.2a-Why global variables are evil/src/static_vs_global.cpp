#include <iostream>

static int x;  // restrict direct access to this file only
int y;         // can be exported and used directly in any file

int main(int argc, const char * argv[])
{
    return 0;
}
