.PHONY:clean all
src=$(wildcard ./*.cpp)
objs=$(patsubst %.cpp,%,$(src))
target=main
CC=g++
CFLAGS=-Wall -g
#CPPFLAGS=-I
all:$(objs)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(objs) $(target)

