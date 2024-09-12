FILES=s21_helper.c parse_string.c stack.c calculate.c credit_calc.c
OS=$(shell uname)
STDFLAGS=-Wall -Werror -Wextra -std=c11
LIBS=-lcheck
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
FLAG_COV = --coverage
TEST_LIBS = -lcheck -lm -lpthread

ifeq (${OS}, Linux)
	TEST_FLAGS = -lcheck -lpthread -lrt -lm -lsubunit
else
	TEST_FLAGS = -lcheck
endif

all: install

calc.a: calc.o
	cd Calc && ar rc calc.a *.o && ranlib calc.a

calc.o: 
	cd Calc && gcc ${STDFLAGS} ${FILES} -c

install:
	mkdir -p build
	cd build && cmake ../Calc && make && mv calc ~/Desktop/

uninstall:
	rm -rf ~/Desktop/calc
	cd build && rm -rf *

clean: 
	cd Calc && rm -rf report *.info a.out *.dSYM *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno .gdb_history build-* html latex *.a 
	cd build && rm -rf *
	rm -rf build-*
#	rm *.tar

dvi:
	doxygen Doxyfile.txt
ifeq (${OS}, Linux)
	firefox ./html/index.html
else
	open ./html/index.html
endif

dist: install
	tar -cvf calc.tar build

test: calc.a
ifeq ($(OS), Darwin)
	${CC} $(STDFLAGS) Calc/calc_test.c Calc/calc.a -o calc_test $(LIBS)
else
	${CC} $(STDFLAGS) Calc/calc_test.c Calc/calc.a -o calc_test $(LIBS) $(LINUX_FLAGS)
endif
	./calc_test


gcov_flag:
	$(eval STDFLAGS += --coverage)

gcov_report: clean gcov_flag test
	mkdir -p gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov
	rm -rf *.gcno *.gcda *.gcov
	firefox gcov/index.html


