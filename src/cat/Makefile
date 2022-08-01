BI = build/
TXT = txt/
TCTR = cat/test_result/
TCT = cat/test_cat/
GCC = gcc -D_GNU_SOURCE -std=c11 # -Wall -Werror -Wextra


.PHONY = default test_cat_1 test_cat_2 test_cat_3 test_cat_4 test_cat_5 test_cat_6 test_cat_11 test_cat_22 test_cat_33 test_cat_44 test_cat_55 test_cat_66



default: all_cat_compare


all_cat_compare: all_test_cat_my_cat
	$(GCC) -c -o $(BI)test_cat.o $(TCT)test_cat.c
	$(GCC) $(BI)test_cat.o -o $(BI)test_cat
	$(BI)./test_cat $(TXT)name_out.txt > cat/test_result/result.txt


all_test_cat_my_cat: test_cat_1 test_cat_2 test_cat_3 test_cat_4 test_cat_5 test_cat_6 test_cat_11 test_cat_22 test_cat_33 test_cat_44 test_cat_55 test_cat_66

test_cat_1:
	$(BI)./my_cat $(TXT)text_1.txt > cat/test_cat/out1.txt
	$(BI)./my_cat -b $(TXT)text_2.txt > cat/test_cat/out2.txt
	$(BI)./my_cat -n $(TXT)text_3.txt > cat/test_cat/out3.txt
	$(BI)./my_cat -s $(TXT)text_1.txt > cat/test_cat/out4.txt
	$(BI)./my_cat -t $(TXT)text_1.txt > cat/test_cat/out5.txt
	$(BI)./my_cat -v $(TXT)text_ascii_255.txt > cat/test_cat/out6.txt
	$(BI)./my_cat -E $(TXT)text_1.txt > cat/test_cat/out7.txt
	$(BI)./my_cat -T $(TXT)text_1.txt > cat/test_cat/out8.txt
	$(BI)./my_cat -A $(TXT)text_1.txt > cat/test_cat/out9.txt
	$(BI)./my_cat --number-nonblank $(TXT)text_1.txt > cat/test_cat/out10.txt
	$(BI)./my_cat --number $(TXT)text_1.txt > cat/test_cat/out11.txt
	$(BI)./my_cat --squeeze-blank $(TXT)text_1.txt > cat/test_cat/out12.txt
	$(BI)./my_cat -e $(TXT)text_1.txt > cat/test_cat/out13.txt

test_cat_2:
	$(BI)./my_cat -bn $(TXT)text_1.txt > cat/test_cat/out14.txt
	$(BI)./my_cat -bs $(TXT)text_1.txt > cat/test_cat/out15.txt
	$(BI)./my_cat -bt $(TXT)text_1.txt > cat/test_cat/out16.txt
	$(BI)./my_cat -bv $(TXT)text_1.txt > cat/test_cat/out17.txt
	$(BI)./my_cat -be $(TXT)text_1.txt > cat/test_cat/out18.txt
	$(BI)./my_cat -ns $(TXT)text_1.txt > cat/test_cat/out19.txt
	$(BI)./my_cat -nt $(TXT)text_1.txt > cat/test_cat/out20.txt
	$(BI)./my_cat -nv $(TXT)text_1.txt > cat/test_cat/out21.txt
	$(BI)./my_cat -ne $(TXT)text_1.txt > cat/test_cat/out22.txt
	$(BI)./my_cat -st $(TXT)text_1.txt > cat/test_cat/out23.txt
	$(BI)./my_cat -sv $(TXT)text_1.txt > cat/test_cat/out24.txt
	$(BI)./my_cat -se $(TXT)text_1.txt > cat/test_cat/out25.txt
	$(BI)./my_cat -tv $(TXT)text_1.txt > cat/test_cat/out26.txt
	$(BI)./my_cat -te $(TXT)text_1.txt > cat/test_cat/out27.txt


test_cat_3:
	$(BI)./my_cat -bnest $(TXT)text_1.txt > cat/test_cat/out28.txt
	$(BI)./my_cat -bbbb $(TXT)text_1.txt > cat/test_cat/out29.txt
	$(BI)./my_cat -nnnn $(TXT)text_1.txt > cat/test_cat/out30.txt
	$(BI)./my_cat -eeee $(TXT)text_1.txt > cat/test_cat/out31.txt
	$(BI)./my_cat -sss $(TXT)text_1.txt > cat/test_cat/out32.txt
	$(BI)./my_cat -ttt $(TXT)text_1.txt > cat/test_cat/out33.txt
	$(BI)./my_cat -TTT $(TXT)text_1.txt > cat/test_cat/out34.txt
	$(BI)./my_cat -EEEE $(TXT)text_1.txt > cat/test_cat/out35.txt
	$(BI)./my_cat -AAAA $(TXT)text_1.txt > cat/test_cat/out36.txt
	$(BI)./my_cat --number-nonblank --number-nonblank --number-nonblank --number-nonblank $(TXT)text_1.txt > cat/test_cat/out37.txt
	$(BI)./my_cat --number --number $(TXT)text_1.txt > cat/test_cat/out.txt
	$(BI)./my_cat  --squeeze-blank --squeeze-blank --squeeze-blank $(TXT)text_1.txt > cat/test_cat/out38.txt

test_cat_4:
	$(BI)./my_cat $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out39.txt
	$(BI)./my_cat -b $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out40.txt
	$(BI)./my_cat -n $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out41.txt
	$(BI)./my_cat -s $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out42.txt
	$(BI)./my_cat -t $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out43.txt
	$(BI)./my_cat -v $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out44.txt
	$(BI)./my_cat -E $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out45.txt
	$(BI)./my_cat -T $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out46.txt
	$(BI)./my_cat -A $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out47.txt
	$(BI)./my_cat --number-nonblank $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out48.txt
	$(BI)./my_cat --number $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out49.txt
	$(BI)./my_cat --squeeze-blank $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out50.txt
	$(BI)./my_cat -e $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out51.txt

test_cat_5:
	$(BI)./my_cat -bnest $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out52.txt
	$(BI)./my_cat -bbbb $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out53.txt
	$(BI)./my_cat -nnnn $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out54.txt
	$(BI)./my_cat -eeee $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out55.txt
	$(BI)./my_cat -sss $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out56.txt
	$(BI)./my_cat -ttt $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out57.txt
	$(BI)./my_cat -TTT $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out58.txt
	$(BI)./my_cat -EEEE $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out59.txt
	$(BI)./my_cat -AAAA $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out60.txt
	$(BI)./my_cat --number-nonblank --number-nonblank --number-nonblank --number-nonblank $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out61.txt
	$(BI)./my_cat --number --number $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out62.txt
	$(BI)./my_cat  --squeeze-blank --squeeze-blank --squeeze-blank $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out63.txt

test_cat_6:
	$(BI)./my_cat -b $(TXT)text_1.txt --number-nonblank $(TXT)text_2.txt --number-nonblank $(TXT)text_3.txt -e $(TXT)text_4.txt -n $(TXT)text_ascii_255.txt > cat/test_cat/out64.txt
	$(BI)./my_cat -bbbb $(TXT)text_1.txt $(TXT)text_2.txt --squeeze-blank $(TXT)text_3.txt $(TXT)text_4.txt --number $(TXT)text_ascii_255.txt > cat/test_cat/out65.txt
	$(BI)./my_cat -nnnn $(TXT)text_1.txt -E $(TXT)text_2.txt $(TXT)text_3.txt -T $(TXT)text_4.txt -s $(TXT)text_ascii_255.txt --squeeze-blank > cat/test_cat/out66.txt


test_cat_11:
	cat $(TXT)text_1.txt > cat/test_cat/out01.txt
	cat -b $(TXT)text_2.txt > cat/test_cat/out02.txt
	cat -n $(TXT)text_3.txt > cat/test_cat/out03.txt
	cat -s $(TXT)text_1.txt > cat/test_cat/out04.txt
	cat -t $(TXT)text_1.txt > cat/test_cat/out05.txt
	cat -v $(TXT)text_ascii_255.txt > cat/test_cat/out06.txt
	cat -E $(TXT)text_1.txt > cat/test_cat/out07.txt
	cat -T $(TXT)text_1.txt > cat/test_cat/out08.txt
	cat -A $(TXT)text_1.txt > cat/test_cat/out09.txt
	cat --number-nonblank $(TXT)text_1.txt > cat/test_cat/out010.txt
	cat --number $(TXT)text_1.txt > cat/test_cat/out011.txt
	cat --squeeze-blank $(TXT)text_1.txt > cat/test_cat/out012.txt
	cat -e $(TXT)text_1.txt > cat/test_cat/out013.txt

test_cat_22:
	cat -bn $(TXT)text_1.txt > cat/test_cat/out014.txt
	cat -bs $(TXT)text_1.txt > cat/test_cat/out015.txt
	cat -bt $(TXT)text_1.txt > cat/test_cat/out016.txt
	cat -bv $(TXT)text_1.txt > cat/test_cat/out017.txt
	cat -be $(TXT)text_1.txt > cat/test_cat/out018.txt
	cat -ns $(TXT)text_1.txt > cat/test_cat/out019.txt
	cat -nt $(TXT)text_1.txt > cat/test_cat/out020.txt
	cat -nv $(TXT)text_1.txt > cat/test_cat/out021.txt
	cat -ne $(TXT)text_1.txt > cat/test_cat/out022.txt
	cat -st $(TXT)text_1.txt > cat/test_cat/out023.txt
	cat -sv $(TXT)text_1.txt > cat/test_cat/out024.txt
	cat -se $(TXT)text_1.txt > cat/test_cat/out025.txt
	cat -tv $(TXT)text_1.txt > cat/test_cat/out026.txt
	cat -te $(TXT)text_1.txt > cat/test_cat/out027.txt


test_cat_33:
	cat -bnest $(TXT)text_1.txt > cat/test_cat/out028.txt
	cat -bbbb $(TXT)text_1.txt > cat/test_cat/out029.txt
	cat -nnnn $(TXT)text_1.txt > cat/test_cat/out030.txt
	cat -eeee $(TXT)text_1.txt > cat/test_cat/out031.txt
	cat -sss $(TXT)text_1.txt > cat/test_cat/out032.txt
	cat -ttt $(TXT)text_1.txt > cat/test_cat/out033.txt
	cat -TTT $(TXT)text_1.txt > cat/test_cat/out034.txt
	cat -EEEE $(TXT)text_1.txt > cat/test_cat/out035.txt
	cat -AAAA $(TXT)text_1.txt > cat/test_cat/out036.txt
	cat --number-nonblank --number-nonblank --number-nonblank --number-nonblank $(TXT)text_1.txt > cat/test_cat/out037.txt
	cat --number --number $(TXT)text_1.txt > cat/test_cat/out0.txt
	cat --squeeze-blank --squeeze-blank --squeeze-blank $(TXT)text_1.txt > cat/test_cat/out038.txt

test_cat_44:
	cat $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out039.txt
	cat -b $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out040.txt
	cat -n $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out041.txt
	cat -s $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out042.txt
	cat -t $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out043.txt
	cat -v $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out044.txt
	cat -E $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out045.txt
	cat -T $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out046.txt
	cat -A $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out047.txt
	cat --number-nonblank $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out048.txt
	cat --number $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out049.txt
	cat --squeeze-blank $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out050.txt
	cat -e $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out051.txt

test_cat_55:
	cat -bnest $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out052.txt
	cat -bbbb $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out053.txt
	cat -nnnn $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out054.txt
	cat -eeee $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out055.txt
	cat -sss $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out056.txt
	cat -ttt $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out057.txt
	cat -TTT $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out058.txt
	cat -EEEE $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out059.txt
	cat -AAAA $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out060.txt
	cat --number-nonblank --number-nonblank --number-nonblank --number-nonblank $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out061.txt
	cat --number --number $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out062.txt
	cat --squeeze-blank --squeeze-blank --squeeze-blank $(TXT)text_1.txt $(TXT)text_2.txt $(TXT)text_3.txt $(TXT)text_4.txt $(TXT)text_ascii_255.txt > cat/test_cat/out063.txt

test_cat_66:
	cat -b $(TXT)text_1.txt --number-nonblank $(TXT)text_2.txt --number-nonblank $(TXT)text_3.txt -e $(TXT)text_4.txt -n $(TXT)text_ascii_255.txt > cat/test_cat/out064.txt
	cat -bbbb $(TXT)text_1.txt $(TXT)text_2.txt --squeeze-blank $(TXT)text_3.txt $(TXT)text_4.txt --number $(TXT)text_ascii_255.txt > cat/test_cat/out065.txt
	cat -nnnn $(TXT)text_1.txt -E $(TXT)text_2.txt $(TXT)text_3.txt -T $(TXT)text_4.txt -s $(TXT)text_ascii_255.txt --squeeze-blank > cat/test_cat/out066.txt