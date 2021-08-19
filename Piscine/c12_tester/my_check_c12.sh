#!/bin/sh

SPLITTER="\n-------------------------------------------------------------------------------------"
FOLDER_TESTERS_NAME="my_check_c12_c_testers"

cd $1

echo $SPLITTER

echo "norminette:\n"
norminette -R CheckForbiddenSourceHeader

echo $SPLITTER

echo '"ls -l */**" (all files in directory):\n'
ls -l */**

for i in {0..9}
do
	echo $SPLITTER
	echo "ex0$i:\n"
	if [ $i != 8 ]
	then
		gcc -Wall -Wextra -Werror ex0$i/ft_*.c ../$FOLDER_TESTERS_NAME/tester_ex0$i/test.c -Iex0$i -o ../$FOLDER_TESTERS_NAME/tester_ex0$i/a.out
		../$FOLDER_TESTERS_NAME/tester_ex0$i/a.out
	else
		cp ../$FOLDER_TESTERS_NAME/tester_ex0$i/ft_list.h ex0$i/ft_list.h
		gcc -Wall -Wextra -Werror ex0$i/ft_*.c ../$FOLDER_TESTERS_NAME/tester_ex0$i/test.c -o ../$FOLDER_TESTERS_NAME/tester_ex0$i/a.out
		../$FOLDER_TESTERS_NAME/tester_ex0$i/a.out
	fi
done

for i in {10..12}
do
	echo $SPLITTER
	echo "ex$i:\n"
	if [ $i != -1 ]
	then
		gcc -Wall -Wextra -Werror ex$i/ft_*.c ../$FOLDER_TESTERS_NAME/tester_ex$i/test.c -Iex$i -o ../$FOLDER_TESTERS_NAME/tester_ex$i/a.out
		../$FOLDER_TESTERS_NAME/tester_ex$i/a.out
	else
		echo "Нет теста для №$i. Пропуск..."
	fi
done

rm ex08/ft_list.h
rm ../$FOLDER_TESTERS_NAME/**/a.out