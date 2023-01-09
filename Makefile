# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
#TARGET = common.o queue_arr queue_ll assignment
TARGET = common.o assignment

all: $(TARGET)

assignment: sorted_list.o queue_using_array.o queue_using_linked_list.o main.o common.o bst.o
	$(CC) $(CFLAGS) -o assignment sorted_list.o queue_using_array.o queue_using_linked_list.o main.o common.o bst.o

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c

sorted_list.o: sorted_list.c header.h
	$(CC) $(CFLAGS) -c sorted_list.c

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

queue_arr: queue_using_array.o
	$(CC) $(CFLAGS) -o queue_arr queue_using_array.o common.o

queue_using_array.o: queue_using_array.c common.h header.h
	$(CC) $(CFLAGS) -c queue_using_array.c

queue_ll: queue_using_linked_list.o
	$(CC) $(CFLAGS) -o queue_ll queue_using_linked_list.o common.o

queue_using_linked_list.o: queue_using_linked_list.c common.h header.h
	$(CC) $(CFLAGS) -c queue_using_linked_list.c

common.o: common.c common.h
	$(CC) $(CFLAGS) -c common.c
clean:
	$(RM) $(TARGET)
	$(RM) queue_using_array.o queue_using_array.o common.o sorted_list.o main.o bst.o queue_using_linked_list.o
