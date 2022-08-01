//
// Created by roman on 24.11.2021.
//
#include <stdio.h>
#include <string.h>
#include "general_functions.h"
#define LINUX_FLAG 3
#define ARR_PARAM_SIZE 7
#define M_MIN 0
#define M_MIN_ARROW 1
#define M_ARROW 2
#define M_TAB 3
#define M_DEL 4

#define TAB 9
#define LF 10

#define bb 0
#define EE 1
#define nn 2
#define ss 3
#define TT 4
#define vv 5

#define FREE_INPUT 0
#define READ_WRITE_INPUT 1

int find_flags(int argc, char * argv[], int *arr_param);
int check_flag(const char *format, int *arr_param);

void without_flags(char *file_name, int mode);
void other_flag(char *file_name, const int *arr_param, int mode, int *numirate);

void file_handling(int shift, int argc, char **argv, int *arr_param);
int file_processing(char *file_name_arr, int *arr_param, int *numirate);


void add_dollar(int *buff, int count_line, int number_line, int ee);
void convert_tab(int *buff, int tt);
void convert_control_symbol(int *buff, int v);


int str_flag(char *argv, int *arr_param);
void print_param(int argc, char **argv);
void print_stdout(int *buff);
void add_m_notations(int *buff, int *shift, int flag_add);


void my_cat(int argc, char **argv);

#ifdef MY_CAT

int main(int argc, char * argv[]) {
  my_cat(argc, argv);
}

#endif


void my_cat(int argc, char **argv) {
  if (argc != 1) {
    if (argc != 2 || argv[1][0] != '-') {
      int arr_param[ARR_PARAM_SIZE] = {0};
      int bool = find_flags(argc, argv, arr_param);
      if (bool != FALSE) {
        if (bool / BOLL_SIZE == TRUE) {
          file_handling(1, argc, argv, arr_param);
        } else {
          printf("cat: invalid option -- '");
          print_param(argc, argv);
          printf("'\nTry 'cat --help' for more information.");
        }
      } else {
        file_handling(1, argc, argv, arr_param);
      }
    } else {
        int arr_param[ARR_PARAM_SIZE] = {0};
        int bool = find_flags(argc, argv, arr_param);
        if (bool != FALSE) {
          if (bool / BOLL_SIZE == TRUE) {
            other_flag(NULL, arr_param, FREE_INPUT, NULL);
          } else {
            printf("cat: invalid option -- '");
            print_param(argc, argv);
            printf("'\nTry 'cat --help' for more information.");
          }
        }
    }
  } else {
    without_flags(NULL, FREE_INPUT);
    printf("n/a - no param\n");
  }
}

void file_handling(int shift, int argc, char **argv, int *arr_param) {
  int numirate = 0;
  for (int i = shift; i < argc; i++) {
    if (argv[i][0] != '-') {
      if (file_processing(argv[i], arr_param, &numirate) == FALSE) {
        printf("cat: %s: No such file or directory\n", argv[i]);
      }
    }
  }
}

int file_processing(char *file_name_arr, int *arr_param, int *numirate) {
  FILE * file;
  int bool = TRUE;
  file = fopen(file_name_arr, "r");
  if (file) {
    fclose(file);
    if (check_empty_flag(arr_param) == EMPTY) {
      without_flags(file_name_arr, READ_WRITE_INPUT);
    } else {
      other_flag(file_name_arr, arr_param, READ_WRITE_INPUT, numirate);
    }
  } else {
    bool = FALSE;
  }
  return bool;
}

int check_flag(const char *format, int *arr_param) {
  int bool = 1;
  int shift = 1;
  while (bool == 1 && format[shift] != '\0') {
    switch (format[shift]) {
      case 'b':
        arr_param[bb]++; break;
      case 'e':
        arr_param[EE]++; arr_param[vv]++; break;
      case 'E':
        arr_param[EE]++; break;
      case 'n':
        arr_param[nn]++; break;
      case 's':
        arr_param[ss]++; break;
      case 't':
        arr_param[TT]++; arr_param[vv]++; break;
      case 'T':
        arr_param[TT]++; break;
      case 'A':
        arr_param[TT]++; arr_param[EE]++; arr_param[vv]++; break;
      case 'v':
        arr_param[vv]++; break;
      default:
        bool = 0;
    }
    shift++;
  }
  return bool * BOLL_SIZE + format[--shift];
}

int check_empty_flag(const int *arr_param) {
  int count = FALSE;
  for (int i = 0; i <= ARR_PARAM_SIZE - 1; i++) {
    printf("%d ", arr_param[i]);
    if (arr_param[i] > EMPTY)
      count = TRUE;
  }
  printf("\n");
  return count;
}

void without_flags(char *file_name, int mode) {
  FILE * file;
  if (mode == READ_WRITE_INPUT) {
    file = fopen(file_name, "r");
  }
    int el = 1;
    while (el != EOF) {
      if (mode == READ_WRITE_INPUT) {
        el = fgetc(file);
      } else {
        el = getchar();
      }
      if (el != EOF) {
        printf("%c", el);
      }
    }
  if (mode == READ_WRITE_INPUT) {
    fclose(file);
  }
}

void other_flag(char *file_name, const int *arr_param, int mode, int *numirate) {
  int line_count = 1;
  FILE * file;
  if (mode == READ_WRITE_INPUT) {
    file = fopen(file_name, "r");
    line_count = count_line(file_name);
  }
  int b = arr_param[bb], ee = arr_param[EE], n = arr_param[nn],
  s = arr_param[ss], tt = arr_param[TT], v = arr_param[vv];

  int i = 0, numirate_ = *numirate, old_len_line = 0, count_empty_line = 0; n = b > EMPTY ? EMPTY : n;
  int el = ' ';
  for (; i < line_count; i++) {
    int buff_str[LEN_MAX];
    int k = 0;
    for (; el != EOF; k++) {
      if (mode == READ_WRITE_INPUT) {
        el = fgetc(file);
      } else {
        el = getchar();
      }
      if (el != EOF) {
          buff_str[k] = el;
      }
      if (el == '\n')
        break;
    }
    if (mode == FREE_INPUT) {
      line_count++;
    }
    buff_str[++k] = EOF;
    convert_tab(buff_str, tt);
    convert_control_symbol(buff_str, v);
    add_dollar(buff_str, line_count, i, ee);

        if (len_str(buff_str) <= 2) {
          if ((buff_str[0] == '$' && buff_str[1] == '\n') || buff_str[0] == '\n') {
            if (n != EMPTY && (count_empty_line == 0 || s == EMPTY)) {
              numirate_++;
              print_numirate(numirate_, EMPTY, n);
            }
            if (s != EMPTY && count_empty_line == 0) {
              print_stdout(buff_str);
            }
            if (s == EMPTY) {
              print_stdout(buff_str);
            }
            count_empty_line++;
          } else {
            if (i != line_count - 1) {
              numirate_++;
              print_numirate(numirate_, b, n);
            }
            print_stdout(buff_str);
          }
        } else {
          if (i != line_count || old_len_line >= 2) {
              numirate_++;
              print_numirate(numirate_, b, n);
              count_empty_line = 0;
          }
          print_stdout(buff_str);
        }
    old_len_line = len_str(buff_str);
    clear_arr(buff_str);
  }
  if (mode == READ_WRITE_INPUT) {
    fclose(file);
  }
  *numirate = numirate_;
}

void clear_arr(int *buff) {
  for (int i = 0; buff[i] != EOF; i++) {
    buff[i] = EOF;
  }
}

int len_str(const int *format) {
  int i = 0;
  for (; format[i] != EOF; i++) {}
  return i;
}

int len_number(int num) {
  int count = 0;
  while (num > 0) {
    num = num / 10;
    count++;
  }
  return count;
}
int count_line(char *file_name) {
  int count = 0;
  FILE * file = fopen(file_name, "r");
  while (!feof(file)) {
    char buff_str[LEN_MAX];
    fgets(buff_str, LEN_MAX, file);
    count++;
  }
  fclose(file);
  return count;
}

void print_numirate(int numirate, int b, int n) {
  if (b != EMPTY || n != EMPTY) {
    for (int j = 0; j <= 5 - len_number(numirate); j++) {
      printf(" ");
    }
    printf("%d\t", numirate);
  }
}

void add_dollar(int *buff, int count_line, int number_line, int ee) {
  if (ee != EMPTY) {
    int len = len_str(buff);
    int tmp = buff[len - 1];
    if (tmp == '\n') {
      buff[len - 1] = '$';
      buff[len] = tmp;
      buff[len + 1] = EOF;
    } else if (len_str(buff) > 2 && (number_line < count_line - 1)) {
      buff[len] = '$';
      buff[len + 1] = EOF;
    }
  }
}

int find_flags(int argc, char * argv[], int *arr_param) {
  int bool = FALSE;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '-') {
           bool = check_flag(argv[i], arr_param);
           if (bool / BOLL_SIZE != TRUE) {
             break;
           }
        } else if (argv[i][0] == '-' && argv[i][1] == '-') {
          bool = str_flag(argv[i], arr_param);
          if (bool / BOLL_SIZE != TRUE) {
            break;
          }
        }
    }
  return bool;
}

int str_flag(char *argv, int *arr_param) {
  int bool = FALSE;
  for (int i = 0; i < LINUX_FLAG; i++) {
    if (i == 0) {
      bool = strcmp(argv, "--number-nonblank");
      if (bool == 0) {
        arr_param[bb]++; break;
      }
    } else if (i == 1) {
      bool = strcmp(argv, "--number");
      if (bool == 0) {
        arr_param[nn]++; break;
      }
    } else if (i == 2) {
      bool = strcmp(argv, "--squeeze-blank");
      if (bool == 0) {
        arr_param[ss]++; break;
      }
    }
  }
  if (bool == FALSE) {
    bool = BOLL_SIZE;
  } else {
    bool = bool * BOLL_SIZE;
  }
  return bool;
}

void print_param(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    if (i != argc - 1) {
      printf("%s ", argv[i]);
    } else {
      printf("%s", argv[i]);
    }
  }
}
void convert_tab(int *buff, int tt) {
  if (tt != EMPTY) {
    for (int i = 0; buff[i] != EOF; i++) {
      if (buff[i] == '\t') {
        add_m_notations(buff, &i, M_TAB);
      }
    }
  }
}

void convert_control_symbol(int *buff, int v) {
  if (v != EMPTY) {
    for (int i = 0; buff[i] != EOF; i++) {
      if (buff[i] < 128) {
        if (buff[i] >= 0 && buff[i] <= 31 && buff[i] != TAB && buff[i] != LF) {
          add_m_notations(buff, &i, M_ARROW);
        } else if (buff[i] == 127) {
          add_m_notations(buff, &i, M_DEL);
        }
      } else if (buff[i] > 159) {
        add_m_notations(buff, &i, M_MIN);

      } else {
        add_m_notations(buff, &i, M_MIN_ARROW);
      }
    }
  }
}


void print_stdout(int *buff) {
  for (int i = 0; buff[i] != EOF; i++) {
      if (buff[i] <= 127) {
        printf("%c", buff[i]);
      } else {
        printf("%d ", buff[i]);
      }
  }
}

void add_m_notations(int *buff, int *shift, int flag_add) {
  int shift_ = *shift;

  if (buff != NULL) {
    if (flag_add == M_TAB) {
      buff[shift_] = 'I';
      int tmp = buff[shift_];
      buff[shift_] = '^';
      int tmp1 = buff[shift_ + 1];
      for (int j = shift_ + 1; j < len_str(buff) + 1; j++) {
        buff[j] = tmp;
        tmp = tmp1;
        tmp1 = buff[j + 1];
      }
      buff[len_str(buff) + 1] = EOF;
    }
    if (flag_add == M_MIN) {
      int tmp = buff[shift_], tmp1 = buff[++shift_], tmp2 = buff[++shift_];
      shift_ -= 2;
      buff[shift_] = 'M'; buff[++shift_] = '-'; buff[++shift_] = tmp - 128;
      for (int j = ++shift_; j < len_str(buff) + 2; j++) {
        tmp = buff[j]; buff[j] = tmp1;
        tmp1 = tmp; tmp = buff[++j];
        buff[j] = tmp2; tmp2 = tmp;
      }
      shift_ = *shift;
    }
    if (flag_add == M_ARROW || flag_add == M_DEL) {
      int tmp = buff[shift_];
      buff[shift_] = '^';
      int tmp1 = buff[++shift_];

      buff[shift_] = flag_add == M_ARROW ? tmp + 64 : tmp - 64;
      for (int j = shift_ + 1; j < len_str(buff) + 1; j++) {
        tmp = buff[j];
        buff[j] = tmp1;
        tmp1 = tmp;
      }
      buff[len_str(buff)] = EOF;
      shift_ = *shift;
    }
  }
  if (flag_add == M_MIN_ARROW) {
    int tmp = buff[shift_];
    int tmp1 = buff[++shift_];
    int tmp2 = buff[++shift_];
    int tmp3 = buff[++shift_];
    shift_ -= 3;
    buff[shift_] = 'M';
    buff[++shift_] = '-';
    buff[++shift_] = '^';
    buff[++shift_] = tmp - 64;
    for (int j = ++shift_; j < len_str(buff) + 3; j++) {
      tmp = buff[j];
      buff[j] = tmp1;
      tmp1 = tmp;
      tmp = buff[++j];
      buff[j] = tmp2;
      tmp2 = tmp;
      tmp = buff[++j];
      buff[j] = tmp3;
      tmp3 = tmp;
    }
    shift_ = *shift;
  }

  *shift = shift_;
}

 void print_stdout_debag(int *buff) {
  printf("\n\n");
  for (int i = 0; buff[i] != EOF; i++) {
    if (buff[i] > 0)
      printf("%d ", buff[i]);
  }
  printf("\n\n");
 }
