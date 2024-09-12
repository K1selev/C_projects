#include <ctype.h>
#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct options {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int first_iter;
  int file_num;
  int current_file;
} opt;

void parser(int argc, char* argv[], opt* options);  // считывание
void print_input_error();  // если нет флага
void use_grep(char* filename, char* pattern, opt* options);
void file_flags_output(char* filename, int match_num, int inv_match_num,
                       opt* options);
void print_output(char* filename, char* line, int line_num, opt* options);
int compile_regex(char* line, char* pattern, int* search_status, opt* options);
void print_match(char* filename, char* line, char* pattern, int line_num,
                 opt* options);
void create_f_pattern(char* f_filename, char* array);
void add_i_to_arr(char* optarg, char* array, opt* options);
int check_for_files(int argc, int optind, char* argv[]);