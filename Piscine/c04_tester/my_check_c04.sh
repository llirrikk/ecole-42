#!/bin/sh

SPLITTER="\n-------------------------------------------------------------------------------------"
FOLDER_TESTERS_NAME="my_check_c04_c_testers"

cd $1

echo $SPLITTER

echo "norminette:\n"
norminette -R CheckForbiddenSourceHeader

echo $SPLITTER

echo '"ls -l */**" (all files in directory):\n'
ls -l */**

for i in {0..5}
do
	echo $SPLITTER
	echo "ex0$i:\n"
	if [ $i != 5 ]
	then
		gcc -Wall -Wextra -Werror ex0$i/ft_*.c ../$FOLDER_TESTERS_NAME/tester_ex0$i/test.c -o ../$FOLDER_TESTERS_NAME/tester_ex0$i/a.out
		../$FOLDER_TESTERS_NAME/tester_ex0$i/a.out
	else
		echo "Нет теста для №$i. Пропуск..."
	fi
done

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
