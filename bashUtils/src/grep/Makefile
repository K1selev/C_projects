CC=gcc
CFLAGS= -Wall -Werror -Wextra

all: clean s21_grep

s21_grep:
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep
	
test:
	sh test_func_grep.sh
check:
	python3 ../materials/linters/cpplint.py --extensions=c *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

clean:
	rm -rf s21_grep
	rm -rf test