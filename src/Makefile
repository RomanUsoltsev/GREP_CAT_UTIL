CT = cat/
GRP = grep/
TCT = cat/test_cat/
TGRP = grep/test_grep/
TREC = grep/test_result/
TREG = cat/test_result/
BI = build/
TXT = txt/
GCC = gcc -D_GNU_SOURCE -std=c11 # -Wall -Werror -Wextra

ifeq ($(OS), Darwin)
	CC2 += -D OS_MAC
else
	CC2 += -D OS_LINUX
endif
.PHONY: clean clear_txt

clean: clear_txt
	rm -rf $(BI)*.o $(BI)my_cat $(BI)my_grep $(BI)test_cat $(BI)test_grep

clear_txt:
	rm -rf $(TCT)*.txt $(TGRP)*.txt $(TREG)*.txt $(TREC)*.txt

my_cat:
	$(GCC) -D MY_CAT -c -o  $(BI)my_cat.o $(CT)my_cat.c
	$(GCC) $(BI)my_cat.o -o $(BI)my_cat

test_cat: my_cat
	$(MAKE) $(MAKESILENT) -f cat/Makefile



my_grep: my_cat.o
	$(GCC) -c -o  $(BI)my_grep.o $(GRP)my_grep.c
	$(GCC) $(BI)my_grep.o $(BI)my_cat.o -o $(BI)my_grep

test_grep: my_grep
	$(MAKE) $(MAKESILENT) -f grep/Makefile


my_cat.o:
	$(GCC) -c -o  $(BI)my_cat.o $(CT)my_cat.c

linters:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c $(CT)*.c $(CT)*.h $(GRP)*.c

cppcheck:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem $(CT)*.c $(CT)*.h $(GRP)*.c $(GRP)*.h