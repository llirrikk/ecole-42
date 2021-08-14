#!/bin/sh

SPLITTER="\n-------------------------------------------------------------------------------------"
FOLDER_TESTERS_NAME="my_check_c08_c_testers"

cd $1

echo $SPLITTER

echo "norminette -R CheckForbiddenSourceHeader:\n"
norminette -R CheckForbiddenSourceHeader

echo $SPLITTER

echo "norminette -R CheckDefine:\n"
norminette -R CheckDefine

echo $SPLITTER

echo '"ls -l */**" (all files in directory):\n'
ls -l */**

for i in {0..3}
do
	echo $SPLITTER
	echo "ex0$i:\n"
	if [ $i != 0 ]
	then
		cp ../$FOLDER_TESTERS_NAME/tester_ex0$i/test.c ex0$i/my_test.c
		gcc -Wall -Wextra -Werror ex0$i/my_test.c -o ../$FOLDER_TESTERS_NAME/tester_ex0$i/a.out
		../$FOLDER_TESTERS_NAME/tester_ex0$i/a.out
	else
		echo "Нет теста для №$i. Пропуск..."
	fi
done

# ex04 + ex05
echo $SPLITTER
echo "ex04 + ex05:\n"

mkdir ex04_ex05
cp ../$FOLDER_TESTERS_NAME/tester_ex04_ex05/ft_stock_str.h ex04_ex05/ft_stock_str.h
cp ../$FOLDER_TESTERS_NAME/tester_ex04_ex05/main.c ex04_ex05/main.c
cp ex04/ft_strs_to_tab.c ex04_ex05/ft_strs_to_tab.c
cp ex05/ft_show_tab.c ex04_ex05/ft_show_tab.c
gcc -Wall -Wextra -Werror ex04_ex05/ft_strs_to_tab.c ex04_ex05/ft_show_tab.c ex04_ex05/main.c -o ../$FOLDER_TESTERS_NAME/tester_ex04_ex05/a.out

cd ../$FOLDER_TESTERS_NAME/tester_ex04_ex05/
./a.out iof3 iop3fj jop2f

cd ../../$1
rm -rf */my_test.c
rm -rf ex04_ex05/
# for i in {10..12}
# do
# 	echo $SPLITTER
# 	echo "ex$i:\n"
# 	if [ $i != 12 ]
# 	then
# 		gcc -Wall -Wextra -Werror ex$i/ft_*.c ../$FOLDER_TESTERS_NAME/tester_ex$i/test.c -o ../$FOLDER_TESTERS_NAME/tester_ex$i/a.out
# 		../$FOLDER_TESTERS_NAME/tester_ex$i/a.out
# 	else
# 		echo "Нет теста для №$i. Пропуск..."
# 	fi
# done
