#include <stdio.h>

int main(int argc, char *argv[]) {

  for (int i = 0; i < 10; i++) {
    switch (i) {
    case 1:
      printf("One \n");
    case 2:
      printf("Two \n");
    case 3:
      printf("Three \n");
    case 4:
      printf("Four\n");
    case 5:
      printf("Five \n");
    case 6:
      printf("Six \n");
    case 7:
      printf("Seven \n");
    case 8:
      printf("Eight \n");
    case 9:
      printf("Nine \n");
    }

    printf("\n");
  }
  return 0;
}
