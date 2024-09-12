CC=gcc
CFLAGS= -Wall -Werror -Wextra

all: clean s21_cat

s21_cat:
	$(CC) $(CFLAGS) s21_cat.c s21_cat.h -o s21_cat
	
test:
	sh test_func_cat.sh
check:
	python3 ../materials/linters/cpplint.py --extensions=c *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

clean:
	rm -rf s21_cat
	rm -rf test