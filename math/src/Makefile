CC:=gcc
CFLAGS := -Wall -Werror -Wextra
GCOV:= #-fprofile-arcs -ftest-coverage

all : clean s21_math.a

s21_math.a :
	${CC} ${CFLAGS} ${GCOV} -c -o s21_math.o s21_math.c
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a

test : all 
	${CC} ${CFLAGS} -c -o tests/s21_math_test.o tests/s21_math_test.c
	${CC} tests/s21_math_test.c s21_math.c -lcheck -lm  -o s21_math_test.out
	./s21_math_test.out

gcov_report:
	${CC} --coverage s21_math.c tests/s21_math_test.c -o s21_test -lcheck
	./s21_test
	gcov --stdout s21_test
	gcov s21_math.c -m
	brew install lcov
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open report/index.html

clean :
	rm -f *.html *.css *.gcno *.gcov *.gcda test ./tests/*.gcda ./tests/*.gcno ./tests/*.o *.out *.a *.o gcov_test

rebuild: clean all
