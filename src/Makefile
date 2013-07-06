SRCS = rdwr.c llist_threads_rw.c
TARGET = librwl3.dylib
CCFLAGS = -O2 -Wall -pipe

all:
	$(CC) $(CCFLAGS) -dynamiclib -o $(TARGET) $(SRCS)

clean:
	$(RM) $(TARGET)
