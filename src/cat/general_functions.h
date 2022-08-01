#ifndef SRC_CAT_GENERAL_FUNCTIONS_H_
#define SRC_CAT_GENERAL_FUNCTIONS_H_

#define BOLL_SIZE 1000
#define TRUE 1
#define FALSE 0
#define EMPTY 0
#define LEN_MAX 20000


int len_str(const int *format);
int len_number(int num);
int check_empty_flag(const int *arr_param);
int count_line(char *file_name);
void clear_arr(int *buff);
void print_numirate(int numirate, int b, int n);


#endif  // SRC_CAT_GENERAL_FUNCTIONS_H_
