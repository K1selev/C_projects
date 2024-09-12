#!/bin/bash

gcc -Wall -Werror -Wextra -lncurses game_of_life.c

echo "Введите номер файла с картой"
read fileNum

if [[ $fileNum = '1' ]]; then
    file="file1.txt"
fi
if [[ $fileNum = '2' ]]; then
    file="file2.txt"
fi
if [[ $fileNum = '3' ]]; then
    file="file3.txt"
fi
if [[ $fileNum = '4' ]]; then
    file="file4.txt"
fi
if [[ $fileNum = '5' ]]; then
    file="file5.txt"
fi
cat $file - | ./a.out

