BI = build/
TXT = txt/
TCTR = cat/test_result/
TCT = cat/test_cat/
GCC = gcc -D_GNU_SOURCE -std=c11 # -Wall -Werror -Wextra


.PHONY = default all_grep_compare



default: all_grep_compare

all_grep_compare: all_test_grep_my_cat
	$(GCC) -c -o $(BI)test_cat.o $(TCT)test_cat.c
	$(GCC) $(BI)test_cat.o -o $(BI)test_cat
	$(BI)./test_cat $(TXT)name_out_grep.txt > grep/test_result/result.txt


all_test_grep_my_cat: test_grep_1 test_grep_11 test_grep_2 test_grep_22 test_grep_3 test_grep_33 test_grep_4 test_grep_44

test_grep_1:
	$(BI)./my_grep textbook $(TXT)text_1.txt > grep/test_grep/out1.txt
	$(BI)./my_grep -v textbook $(TXT)text_1.txt > grep/test_grep/out2.txt
	$(BI)./my_grep -i textbook $(TXT)text_1.txt > grep/test_grep/out3.txt
	$(BI)./my_grep -c textbook $(TXT)text_1.txt > grep/test_grep/out4.txt
	$(BI)./my_grep -l textbook $(TXT)text_1.txt $(TXT)text_2.txt> grep/test_grep/out5.txt
	$(BI)./my_grep -n textbook $(TXT)text_1.txt > grep/test_grep/out6.txt
	$(BI)./my_grep -o textbook $(TXT)text_1.txt $(TXT)text_2.txt> grep/test_grep/out7.txt
	#$(BI)./my_grep -s textbook $(TXT)text_11.txt $(TXT)text_22.txt> grep/test_grep/out8.txt
	$(BI)./my_grep -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out9.txt
	$(BI)./my_grep -o textbook $(TXT)text_1.txt > grep/test_grep/out10.txt
	$(BI)./my_grep -e textbook $(TXT)text_1.txt > grep/test_grep/out11.txt

test_grep_2:
	$(BI)./my_grep -vi textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out12.txt
	$(BI)./my_grep -vc textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out13.txt
	$(BI)./my_grep -vl textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out14.txt
	$(BI)./my_grep -vn textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out15.txt
	$(BI)./my_grep -v textbook  $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out16.txt
	$(BI)./my_grep -v -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out17.txt
	$(BI)./my_grep -ic textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out18.txt
	$(BI)./my_grep -il textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out19.txt
	$(BI)./my_grep -in textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out20.txt
	$(BI)./my_grep -io textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out21.txt
	$(BI)./my_grep -i -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out22.txt
	#$(BI)./my_grep -cl textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out23.txt
	$(BI)./my_grep -cn textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out24.txt
	$(BI)./my_grep -co textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out25.txt
	$(BI)./my_grep -c -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out26.txt
	$(BI)./my_grep -ln textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out27.txt
	$(BI)./my_grep -lo textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out28.txt
	$(BI)./my_grep -l -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out29.txt
	$(BI)./my_grep -o -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out30.txt

test_grep_3:
	$(BI)./my_grep -e textbook  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out31.txt
	$(BI)./my_grep -c -e Οὐχὶ  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out32.txt
	#$(BI)./my_grep -cl -e textbook  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out33.txt
	$(BI)./my_grep -ln -e Οὐχὶ  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out34.txt
	$(BI)./my_grep -oln -e textbook  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out35.txt
	$(BI)./my_grep -vln -e text  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out36.txt
	$(BI)./my_grep -vhln -e textbook  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out37.txt
	$(BI)./my_grep -vhlcn -e Οὐχὶ  -e [стр][о] -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out38.txt
	$(BI)./my_grep -vhlcn -e Οὐχὶ  -e and -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out39.txt

test_grep_4:
	$(BI)./my_grep -i -e cat -e textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out40.txt
	$(BI)./my_grep -i -e cat -f txt/regex_file.txt -e textbook  $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out41.txt
	$(BI)./my_grep -i -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out42.txt


test_grep_11:
	grep textbook $(TXT)text_1.txt > grep/test_grep/out01.txt
	grep -v textbook $(TXT)text_1.txt > grep/test_grep/out02.txt
	grep -i textbook $(TXT)text_1.txt > grep/test_grep/out03.txt
	grep -c textbook $(TXT)text_1.txt > grep/test_grep/out04.txt
	grep -l textbook $(TXT)text_1.txt $(TXT)text_2.txt> grep/test_grep/out05.txt
	grep -n textbook $(TXT)text_1.txt > grep/test_grep/out06.txt
	grep -o textbook $(TXT)text_1.txt $(TXT)text_2.txt> grep/test_grep/out07.txt
	#grep -s textbook $(TXT)text_11.txt $(TXT)text_22.txt> grep/test_grep/out08.txt
	grep -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt> grep/test_grep/out09.txt
	grep -o textbook $(TXT)text_1.txt > grep/test_grep/out010.txt
	grep -e textbook $(TXT)text_1.txt > grep/test_grep/out011.txt

test_grep_22:
	grep -vi textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out012.txt
	grep -vc textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out013.txt
	grep -vl textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out014.txt
	grep -vn textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out015.txt
	grep -v textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out016.txt
	grep -v -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out017.txt
	grep -ic textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out018.txt
	grep -il textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out019.txt
	grep -in textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out020.txt
	grep -io textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out021.txt
	grep -i -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out022.txt
	#grep -cl textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out023.txt
	grep -cn textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out024.txt
	grep -co textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out025.txt
	grep -c -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out026.txt
	grep -ln textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out027.txt
	grep -lo textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out028.txt
	grep -l -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out029.txt
	grep -o -e cat    $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out030.txt

test_grep_33:
	grep -e textbook  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out031.txt
	grep -c -e Οὐχὶ  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out032.txt
	#grep -cl -e textbook  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out033.txt
	grep -ln -e Οὐχὶ  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out034.txt
	grep -oln -e textbook  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out035.txt
	grep -vln -e text  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out036.txt
	grep -vhln -e textbook  -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out037.txt
	grep -vhlcn -e Οὐχὶ  -e [стр][о] -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out038.txt
	grep -vhlcn -e Οὐχὶ  -e and -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out039.txt

test_grep_44:
	grep -i -e cat -e textbook $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out040.txt
	grep -i -e cat -f txt/regex_file.txt -e textbook  $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out041.txt
	grep -i -e cat -f txt/regex_file.txt $(TXT)text_1.txt $(TXT)text_2.txt > grep/test_grep/out042.txt
