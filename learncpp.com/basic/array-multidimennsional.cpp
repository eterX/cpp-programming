// Copyright [2016] <Vex Woo>

#include <stdio.h>
#include <iostream>


int main(int argc, const char *argv[]) {
    // ----- Equal ----
    // int jimmy[9][9];
    // int jimmy[9 * 9];
    const int height = 9;
    const int width = 9;

    int jimmy[height][width];

    for (int h = 0; h < height; ++h) {
      for (int w = 0; w < width; ++w) {
        jimmy[h][w] = h * w;
      }
    }

    for (int h = 0; h < height; ++h) {
      for (int w = 0; w < width; ++w) {
        // std::cout << " " << jimmy[h][w] << " ";
        printf("%4d", jimmy[h][w]);
      }
      printf("\n");
      // std::cout << std::endl;
    }
    return 0;
}
