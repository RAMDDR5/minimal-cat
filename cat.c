#include <stdio.h>

void clrscr() {
  //clears screen when used
  printf("\033[H\033[J");
}

int main(int argc, char *argv[]) {
  //if user gives no file name
  if (argv[1] == NULL) {
    printf("usage:\n  %s [file]", argv[1]);
  }

  //opens the file with readonly and checks if the file is there
  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    printf("File not found.");
    return 1;
  }

  //creates a buffer and reads the content of the file
  char buffer[2048/*2kb*/];
  fread(buffer, 2048, 1, f);

  //prints the content
  clrscr();
  printf("%s", buffer);
  fclose(f);
  return 0x0;
}
