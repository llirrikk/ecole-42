#!/bin/sh

SPLITTER="\n-------------------------------------------------------------------------------------"
FOLDER_TESTERS_NAME="my_check_c01_c_testers"

cd $1

echo $SPLITTER

echo "norminette:\n"
norminette -R CheckForbiddenSourceHeader

echo $SPLITTER

echo '"ls -l */**" (all files in directory):\n'
ls -l */**

for i in {0..8}
do
		echo $SPLITTER
		echo "ex0$i:\n"
	if [ $i != 1 ] 
	then
		cp ../$FOLDER_TESTERS_NAME/tester_ex0$i/test.c ex0$i/test.c

		gcc -Wall -Wextra -Werror ex0$i/ft_*.c ex0$i/test.c -o ex0$i/a.out
		./ex0$i/a.out
	else
		echo "Нет теста для ex0$i. Пропуск..."
	fi
done

