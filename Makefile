# 27/11/2020
#Makefile

.Phony:
	clean

cflags = -Wall -Wmissing-declarations -Wmissing-prototypes -fsanitize=address -fno-omit-frame-pointer
cc = gcc

main: main.o graph.o init_MST.o prims.o
	$(cc) $(cflags) -g main.o graph.o init_MST.o prims.o

main.o: main.c graph.o init_MST.o prims.o
	$(cc) $(cflags) -g -c main.c graph.o init_MST.o prims.o

graph.o: graph.c graph.h
	$(cc) $(cflags) -g -c graph.c graph.h

init_MST.o: init_MST.c init_MST.h
	$(cc) $(cflags) -g -c init_MST.c init_MST.h

prims.o: prims.c prims.h
	$(cc) $(cflags) -g -c prims.c prims.h

clean:
	rm *.o main
