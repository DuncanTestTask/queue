PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
CC=clang

SRC=queue.c
OBJ=$(SRC:.c=.o)

TEST_SRC=test_queue.c
TEST_OBJ=$(TEST_SRC:.c=.o)

CFLAGS += -g -O0 -fPIC -no-pie
#CFLAGS += -Os

all: lib.a

lib.a: $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

test: $(TEST_OBJ) lib.a
	$(CC)  $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: $(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $(CFLAGS) -o $@ $<

testing: test
	./test
clean:
	rm -f main test lib.a $(OBJ)
