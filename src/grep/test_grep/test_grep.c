//
// Created by roman on 24.11.2021.
//
#include <stdio.h>
void compare_text(char *file_m, char *file_o, int *error_test);
void print_asci();
int len_buff(const char *buff);

int main(int argc, char * argv[]) {
  FILE *file = fopen(argv[1], "r");
  int count_error = 0;
  if (file != NULL) {
    char file_my[200] = {0};
    char file_orig[200] = {0};
    while (!feof(file)) {
      fgets(file_my, 30, file);
      fgets(file_orig, 30, file);
      if (file_my[len_buff(file_my) - 1] == '\n') {
        file_my[len_buff(file_my) - 1] = '\0';
      }
      if (file_orig[len_buff(file_orig) - 1] == '\n') {
        file_orig[len_buff(file_orig) - 1] = '\0';
      }
      compare_text(file_my, file_orig, &count_error);
    }


  } else {
    printf("error file no found: %s\n", argv[1]);
  }
  printf("ERROR TEST : %d\n", count_error);
  return 0;
}

int len_buff(const char *buff) {
  int i = 0;
  for (; buff[i] != '\0'; i++) {}
  return i;
}

void print_asci() {
  for (int i = 0; i < 300; i++) {
    printf("%c", i);
  }
}
void compare_text(char *file_m, char *file_o, int *error_test) {
  FILE *file_my = fopen(file_m, "r");
  FILE *file_orig = fopen(file_o, "r");
  if (file_my != NULL && file_orig != NULL) {
    int c = ' ';
    int c1 = ' ';
    while (c != EOF && c1 != EOF) {
      c = fgetc(file_my);
      c1 = fgetc(file_orig);
      if (c1 != c) {
        *error_test = *error_test + 1;
        printf("_______________FAIL_______________\n|%c|  != |%c|\n%s\n", c, c1, file_m);
        printf("\n\n");
        while (c != EOF) {
          c = fgetc(file_my);
          printf("%c", c);
        }
        printf("\n\n");
        break;
      }
    }
    fclose(file_my);
    fclose(file_orig);
  } else {
    if (file_my == NULL)
      printf("error, %s\n", file_m);
    if (file_orig == NULL)
      printf("error, %s\n", file_o);
  }
}
