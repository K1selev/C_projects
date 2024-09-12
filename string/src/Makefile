NAME = s21_string
CC = gcc
CC_FLAGS = -std=c11 -Wall -Wextra -Werror

all: clean s21_string.a

clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM debug

rebuild: clean all

test: s21_string.a
	$(CC) $(CC_FLAGS) tests/*.c *.c -lcheck -lm
	./a.out

gcov_report:
	$(CC) --coverage *.c tests/*.c -o s21_test -lcheck
	./s21_test
	lcov -t "s21_test" -o s21.info -c -d .
	genhtml -o report s21.info
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_test s21.info

s21_string.a: s21_string.o
	ar rcs s21_string.a *.o
	rm -rf *.o
	ranlib s21_string.a

s21_string.o:
	$(CC) $(CC_FLAGS) -c *.c
