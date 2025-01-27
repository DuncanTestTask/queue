PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
CC=clang

SRC=queue.c
OBJ=$(SRC:.c=.o)

TEST_SRC=test_queue.c
TEST_OBJ=$(TEST_SRC:.c=.o)

ifdef DEBUG
CFLAGS = -g -O0  -Wall -DDEBUG
else
CFLAGS = -Os -Wall
endif

help:
	@echo "Usage: make all|test|testing [DEBUG=1]"
	@echo "make all makes lib.a"
	@echo "make test makes test exe"
	@echo "make testing runs tests"
	@echo "DEBUG=1 verbose output in runtime"

all: lib.a

lib.a: $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

test: $(TEST_OBJ) lib.a
	$(CC)  $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: $(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $(CFLAGS) -o $@ $<

testing: test
	./test

.PHONY: clean
clean:
	rm -f main test lib.a $(OBJ) $(TEST_OBJ)
