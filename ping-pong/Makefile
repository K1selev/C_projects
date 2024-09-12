TARGET = ./main.out
#HDRS_DIR = include

SRCS = \
	src/pong.c

.PHONY: all build rebuild check test clean

all: clean build
	$(TARGET)

$(TARGET): $(SRCS)
	$(CC) -std=c11 -Wall -Werror -Wextra -lncurses -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

rebuild: clean build

check:
	python3 materials/linters/cpplint.py --extensions=c $(SRCS)

test:

clean:
	rm -rf $(TARGET)