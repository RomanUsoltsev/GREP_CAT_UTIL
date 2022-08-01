# GREP_CAT_UTIL
Implementation of some functions of standard linux cat and grep utilities in C language.

Programs are compiled using a Makefile located in the src folder. 
Makefiles located in subdirectories cat and grep are necessary for building tests. 
The test result is in subdirectories in test_result.

test_grep.c and test_cat.c are used to compare the performance of the original grep and cat (Alpine Linux 3.15.0 released) with grep and cat implemented independently.

There are also checks for code style (cpplint util) and logical errors (cppcheck util).

The txt directory contains a set of test text files.