# GREP_CAT_UTIL
Implementation of some functions of standard linux cat and grep utilities in C language.

Programs are compiled using a Makefile located in the src folder. 
Makefiles located in subdirectories cat and grep are necessary for building tests. 
The test result is in subdirectories in test_result.

test_grep.c and test_cat.c are used to compare the performance of the original grep and kat (Arch Linux, 2021.09.01) with grep and kat implemented independently.

There are also checks for code style (cpplint util) and logical errors (cppcheck util).