SRCS = llist_threads_rw_test.c
TARGET = ./testrunner
INCLUDES = -I../src
LIBS = -L../src -lrwl3
CCFLAGS = -O2 -Wall -pipe
PRINT = | ./tp.sh

all:: target test

target:
	$(CC) $(CCFLAGS) $(INCLUDES) $(LIBS) -o $(TARGET) $(SRCS)

test:
	DYLD_LIBRARY_PATH=../src $(TARGET) $(PRINT)

clean:
	$(RM) $(TARGET)
