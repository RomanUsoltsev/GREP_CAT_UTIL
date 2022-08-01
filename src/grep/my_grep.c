#include <regex.h>
#include <stdio.h>
#include "../cat/general_functions.h"


#define ARR_PARAM_SIZE 11
#define P_MATCH_SIZE 20
#define TOKEN_SIZE 2000
#define ARR_REGEX_SIZE 500
#define ARR_FILE_SIZE 500

#define ee 0
#define ii 1
#define vv_ 2
#define cc 3
#define ll 4
#define nn_ 5
#define hh 6
#define ss_ 7
#define ff 8
#define oo 9
#define file_count 10

#define FLAGS 0
#define SIMPLE_CHECK 2

#define TRUE_REG 0
#define FALSE_REG 1


int g_check_flag(const char *format, int *arr_param);
int g_find_flags(int argc, char * argv[], int *arr_param);
int g_file_processing(char *file_name_arr, int *arr_param, char *regexp, int mode);
void g_file_handling(int shift, int argc, char **argv, int *arr_param);
int check_regex_exp(char *regexp);

int check_e_flag(const char *argv);
int check_f_flag(const char *argv);

void result_regex(char *file_name,
                  char *buff_str,
                  const int *a_p,
                  int i,
                  int line_count,
                  regmatch_t *pmatch,
                  regex_t *preg,
                  size_t nmatch);

void o_flag_print(char *file_name,
                  char *buff_str,
                  const int *a_p,
                  int i,
                  regmatch_t *pmatch,
                  regex_t *preg,
                  size_t nmatch);


void without_E_F(int *i_, char **argv, int *arr_param, int *bool_regexp_, int *index_regex);
void with_E_F(char **file_name, char *regex_arr, int *arr_param);


void insert_all_regex(const char *argv, char *regex_arr, int *shift, const int *a_p);
void parse_regex_and_file(int argc, char **argv, char **file_name, char *regex_arr, int *arr_param);
int insert_regex_from_file(char *file_name, char *regex_arr, int *shift, const int *a_p);

void g_regex_exp(char *regexp, char *file_name, int *a_p);
int len_buff(const char *buff);
void clear_buff(char *buff);
void insert_token(const char * buff_str, char *token, int size, int start);

void s21_grep(int argc, char * argv[]);

void g_print_stdout_debag(int *buff);

int main(int argc, char * argv[]) {
  s21_grep(argc, argv);
  return 0;
}

void s21_grep(int argc, char * argv[]) {
  if (argc != 1) {
    int arr_param[ARR_PARAM_SIZE] = {0};
    int bool = g_find_flags(argc, argv, arr_param);
//    g_print_stdout_debag(arr_param);
    if (check_empty_flag(arr_param) == TRUE && bool / BOLL_SIZE == TRUE) {
        g_file_handling(1, argc, argv, arr_param);
      } else if (check_empty_flag(arr_param) == FALSE && bool / BOLL_SIZE == TRUE) {
            g_file_handling(1, argc, argv, arr_param);
      } else {
        printf("error_1 %c - %d\n", bool % BOLL_SIZE, bool);
      }
  } else {
    printf("n/a param");
  }
}

int g_find_flags(int argc, char * argv[], int *arr_param) {
  int bool = TRUE * BOLL_SIZE;
  --arr_param[file_count];
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] != '-') {
      bool = g_check_flag(argv[i], arr_param);
      if (bool / BOLL_SIZE != TRUE) {
        break;
      }
    } else {
      ++arr_param[file_count];
    }
  }
  return bool;
}

int g_check_flag(const char *format, int *arr_param) {
  int bool = TRUE;
  int shift = 1;
  while (bool == 1 && format[shift] != '\0') {
    switch (format[shift]) {
      case 'e':
        ++arr_param[ee]; break;
      case 'i':
        ++arr_param[ii]; break;
      case 'v':
        ++arr_param[vv_]; break;
      case 'c':
        ++arr_param[cc]; break;
      case 'l':
        ++arr_param[ll]; break;
      case 'n':
        ++arr_param[nn_]; break;
      case 'h':
        ++arr_param[hh]; break;
      case 's':
        ++arr_param[ss_]; break;
      case 'f':
        ++arr_param[ff]; break;
      case 'o':
        ++arr_param[oo]; break;
      default:
        bool = FALSE;
    }
    shift++;
  }
  return bool * BOLL_SIZE + format[--shift];
}

void g_file_handling(int shift, int argc, char **argv, int *arr_param) {
  if (arr_param[ee] != EMPTY || arr_param[ff] != EMPTY) {
    char regex_arr[ARR_REGEX_SIZE] = {0};
    char *file_name[ARR_FILE_SIZE] = {NULL};
    parse_regex_and_file(argc, argv, file_name, regex_arr, arr_param);
    if (regex_arr[len_buff(regex_arr) - 1] == '|') { regex_arr[len_buff(regex_arr) - 1] = '\0'; }

//    printf("%s\n", regex_arr);
//    for (int i = 0; file_name[i] != NULL; ++i) {
//      printf("%s\n", file_name[i]);
//    }
    arr_param[ii] = 0;
//    g_print_stdout_debag(arr_param);
    with_E_F(file_name, regex_arr, arr_param);
  }

  if (arr_param[ee] == EMPTY && arr_param[ff] == EMPTY) {
    int bool_regexp = TRUE;
    int index_regex = 0;
    for (int i = shift; i < argc; i++) {
      without_E_F(&i, argv, arr_param, &bool_regexp, &index_regex);
    }
  } else {
  }
}
int check_e_flag(const char *argv) {
  int bool = FALSE;
  for (int i = 1; argv[i] != '\0' ; i++) {
    if (argv[i] == 'e') {
      bool = TRUE;
    }
  }
  return bool;
}

int check_f_flag(const char *argv) {
  int bool = FALSE;
  for (int i = 1; argv[i] != '\0' ; i++) {
    if (argv[i] == 'f') {
      bool = TRUE;
    }
  }
  return bool;
}


void parse_regex_and_file(int argc, char **argv, char **file_name, char *regex_arr, int *arr_param) {
  int shift_regex_arr = 0;
  int shift_file_arr = 0;
  arr_param[file_count] = 0;
  for (int i = 1; i < argc; ++i) {
    if (argv[i][0] == '-') {
      if (check_e_flag(argv[i]) == TRUE) {
        insert_all_regex(argv[i + 1], regex_arr, &shift_regex_arr, arr_param);
      }
      if (check_f_flag(argv[i]) == TRUE) {
        insert_regex_from_file(argv[i + 1], regex_arr, &shift_regex_arr, arr_param);
      }
      if (check_e_flag(argv[i]) == TRUE || check_f_flag(argv[i]) == TRUE) {
        ++i;
      }
    } else {
      file_name[shift_file_arr++] = argv[i];
      ++arr_param[file_count];
    }
  }
}

int insert_regex_from_file(char *file_name, char *regex_arr, int *shift, const int *a_p) {
  int bool = TRUE;
  int shift_ = *shift;
  FILE *file = fopen(file_name, "r");
  if (file) {
    char c = ' ';
    int count_empty_str = 0;
    int flag_empty = 0;
    if (shift_ != 0) { regex_arr[shift_++] = '|'; }

    for (int i = 0; c != EOF; i++) {
      char old_c = c;
      c = (char)fgetc(file);
      if (c != EOF) {
        if (c != '\n') {
            regex_arr[shift_++] = c;
            count_empty_str = 0;
        }
        if (c == '\n' && count_empty_str == 0) {
          regex_arr[shift_++] = '|';
          ++count_empty_str;
        }
        if (old_c == '\n' && c == '\n' && flag_empty == 0) {
          regex_arr[shift_++] = c;
          regex_arr[shift_++] = '|';
          flag_empty = 1;
        }
      }
    }
    fclose(file);

    if (a_p[ii] != EMPTY) {
      c = ' ';
      count_empty_str = 0;
      flag_empty = 0;
      file = fopen(file_name, "r");

      if (shift_ != 0) { regex_arr[shift_++] = '|'; }

      for (int i = 0; c != EOF; i++) {
        char old_c = c;
        c = (char)fgetc(file);
        if (c != EOF) {
          if (c != '\n') {
            if (c >= 97 && c <= 122) {
              regex_arr[shift_++] = (char)((int)c - 32);
            } else if (c >= 65 && c <= 90) {
              regex_arr[shift_++] = (char)((int)c + 32);
            } else {
              regex_arr[shift_++] = c;
            }
            count_empty_str = 0;
          }
          if (c == '\n' && count_empty_str == 0) {
            regex_arr[shift_++] = '|';
            ++count_empty_str;
          }
          if (old_c == '\n' && c == '\n' && flag_empty == 0) {
            regex_arr[shift_++] = '|';
            flag_empty = 1;
          }
        }
      }
      fclose(file);
    }

  } else { bool = FALSE; }
  *shift = shift_;
  return bool;
}

void insert_all_regex(const char *argv, char *regex_arr, int *shift, const int *a_p) {
  int shift_ = *shift;
  if (shift_ != 0) { regex_arr[shift_++] = '|'; }
  for (int i = 0; argv[i] != '\0'; i++) {
    regex_arr[shift_++] = argv[i];
  }
  if (a_p[ii] != EMPTY) {
    regex_arr[shift_++] = '|';
    for (int i = 0; argv[i] != '\0'; i++) {
      if (argv[i] >= 97 && argv[i] <= 122) {
        regex_arr[shift_++] = (char)((int)argv[i] - 32);
      } else if (argv[i] >= 65 && argv[i] <= 90) {
        regex_arr[shift_++] = (char)((int)argv[i] + 32);
      } else {
        regex_arr[shift_++] = argv[i];
      }
    }
  }
  *shift = shift_;
}

void with_E_F(char **file_name, char *regex_arr, int *arr_param) {
  for (int i = 0; file_name[i] != NULL; i++) {
    if (g_file_processing(file_name[i], arr_param, regex_arr, FLAGS) == FALSE) {
      if (arr_param[ss_] == EMPTY) {
        printf("grep: %s: No such file or directory", file_name[i]);
      }
    }
  }
}

void without_E_F(int *i_, char **argv, int *arr_param, int *bool_regexp_, int *index_regex) {
  int i = *i_;
  int bool_regexp = *bool_regexp_;
  if (argv[i][0] != '-') {
    int index_regex_ = *index_regex;
    if (bool_regexp == TRUE) {
      if (check_regex_exp(argv[i]) == TRUE_REG) {
        bool_regexp = FALSE;
//        printf("\nbool - %d\n", bool_regexp);
        index_regex_ = i;
        *index_regex = index_regex_;
        if (g_file_processing(argv[++i], arr_param, argv[index_regex_], FLAGS) == FALSE) {
          if (arr_param[ss_] == EMPTY) {
            printf("grep: %s: No such file or directory", argv[i]);
          }
        }
      } else {
        printf("bool_regexp_2: %d   ", bool_regexp);
        printf("error regex_2: %s\n", argv[i]);
      }
    } else {
      if (g_file_processing(argv[i], arr_param, argv[index_regex_], FLAGS) == FALSE) {
        if (arr_param[ss_] == EMPTY) {
          printf("grep: %s: No such file or directory", argv[i]);
        }
      }
    }
  }
  *i_ = i;
  *bool_regexp_ = bool_regexp;
}


int g_file_processing(char *file_name_arr, int *arr_param, char *regexp, int mode) {
  FILE * file;
  int bool = TRUE;
  if (mode == FLAGS) {
//    printf("\n%s - %s\n", file_name_arr, regexp);

    file = fopen(file_name_arr, "r");
    if (file) {
      fclose(file);
      g_regex_exp(regexp, file_name_arr, arr_param);
    } else {
      bool = FALSE;
    }
  }  else if (mode == SIMPLE_CHECK) {
    file = fopen(file_name_arr, "r");
    if (file) {
      fclose(file);
    } else {
      bool = FALSE;
    }
  }
  return bool;
}

int check_regex_exp(char *regexp) {
  int bool = FALSE_REG;
    regex_t preg;
    bool = regcomp(&preg, regexp, 0);
    regfree(&preg);
  return bool;
}

void g_regex_exp(char *regexp, char *file_name, int *a_p) {
  int coincidence = 0;
  int line_count = count_line(file_name);
  FILE *file = fopen(file_name, "r");
//  printf("%d - ", line_count);

  for (int i = 0; i < line_count; i++) {
    int el = ' ', k = 0; char buff_str[LEN_MAX] = {0};

    for (; el != EOF; k++) {
      el = fgetc(file);
      if (el != EOF) { buff_str[k] = (char)el; }
      if (el == '\n') { break; }
    }
    regex_t preg;
    size_t nmatch = P_MATCH_SIZE; regmatch_t pmatch[P_MATCH_SIZE];
    int reg_flag = a_p[ii] == EMPTY ? REG_EXTENDED : REG_ICASE;
      int rc = regcomp(&preg, regexp, reg_flag);

      if (rc != TRUE_REG) {
        printf("regcomp() no zero value (%d)\n", rc);
      }
      rc = regexec(&preg, buff_str, nmatch, pmatch, EMPTY);
      if (rc == TRUE_REG && a_p[vv_] == EMPTY) {
        coincidence++;
        result_regex(file_name, buff_str, a_p, i, line_count, pmatch, &preg, nmatch);

      } else if (rc == FALSE_REG && a_p[vv_] != EMPTY) {
        coincidence++;
        result_regex(file_name, buff_str, a_p, i, line_count, pmatch, &preg, nmatch);
      }
      clear_buff(buff_str);
      regfree(&preg);
  }
  if (a_p[ll] != EMPTY && coincidence > 0) { coincidence = 1;}
  if (a_p[cc] != EMPTY) {
    if (a_p[vv_] != EMPTY) { --coincidence; }
    if (coincidence != 0) {
      if (a_p[file_count] > 1) { printf("%s:", file_name);}
      printf("%d\n", coincidence);
    }
  }
  if (a_p[ll] != EMPTY) { printf("%s\n", file_name);}
  fclose(file);
}

void result_regex(char *file_name, char *buff_str, const int *a_p, int i,
                  int line_count, regmatch_t *pmatch, regex_t *preg, size_t nmatch) {
  if (a_p[cc] == EMPTY && a_p[ll] == EMPTY) {
    if (i < line_count - 1) {
      if (a_p[hh] == EMPTY && a_p[file_count] > 1) { printf("%s:", file_name); }
      if (a_p[nn_] != EMPTY) {printf("%d:", i + 1); }

    } else if (buff_str[0] != '\0') {
      if (a_p[hh] == EMPTY && a_p[file_count] > 1) { printf("%s:", file_name); }

      if (a_p[nn_] != EMPTY) {printf("%d:", i + 1); }
    }
    if (a_p[oo] == EMPTY) {
      printf("%.*s", len_buff(buff_str), buff_str);

    } else {
      o_flag_print(file_name, buff_str, a_p, i, pmatch, preg, nmatch);
    }
  }
}

void o_flag_print(char *file_name, char *buff_str, const int *a_p,
                  int i, regmatch_t *pmatch, regex_t *preg, size_t nmatch) {
  int size = (int)(pmatch[0].rm_eo - pmatch[0].rm_so);
  printf("%.*s\n", size, &buff_str[pmatch[0].rm_so]);

  char token[TOKEN_SIZE] = {0};
  int start = (int)(pmatch[0].rm_eo);

  for (int j = (int)(pmatch[0].rm_eo); j < len_buff(buff_str); j++) {
    insert_token(buff_str, token, size, start);
    ++start;

    int rc = regexec(preg, (const char *) &token, nmatch, pmatch, EMPTY);

    if (rc == TRUE_REG && a_p[vv_] == EMPTY) {
      if (a_p[hh] == EMPTY && a_p[file_count] > 1) { printf("%s:", file_name);}
      if (a_p[nn_] != EMPTY) {printf("%d:", i + 1); }
      printf("%.*s\n", size, token);

    } else if (rc != TRUE_REG && a_p[vv_] != EMPTY) {
      if (a_p[hh] == EMPTY && a_p[file_count] > 1) { printf("%s:", file_name);}
      if (a_p[nn_] != EMPTY) {printf("%d:", i + 1); }
      printf("%.*s\n", size, token);
    }
    clear_buff(token);
  }
}

void insert_token(const char * buff_str, char *token, int size, int start) {
  for (int i = 0; i < size; i++) {
    token[i] = buff_str[start + i];
  }
}

int len_buff(const char *buff) {
  int i = 0;
  for (; buff[i] != '\0'; i++) {}
  return i;
}
void clear_buff(char *buff) {
  for (int i = 0; buff[i] != '\0'; i++) {
    buff[i] = '\0';
  }
}

void g_print_stdout_debag(int *buff) {
    for (int i = 0; i < ARR_PARAM_SIZE; i++) {
    printf("%d ", buff[i]);
    }
    printf("\n");
}
