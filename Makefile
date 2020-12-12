# 27/11/2020
#Makefile

.Phony:
	clean

cflags = -Wall -Wmissing-declarations -Wmissing-prototypes -fsanitize=address -fno-omit-frame-pointer
cc = gcc

main: main.o graph.o init_MST.o prims.o jsonparser.o
	$(cc) $(cflags) -g main.o graph.o init_MST.o prims.o jsonparser.o -o main

main.o: main.c graph.o init_MST.o prims.o
	$(cc) $(cflags) -g -c main.c graph.o init_MST.o prims.o

graph.o: graph.c graph.h
	$(cc) $(cflags) -g -c graph.c graph.h

init_MST.o: init_MST.c init_MST.h
	$(cc) $(cflags) -g -c init_MST.c init_MST.h

prims.o: prims.c prims.h
	$(cc) $(cflags) -g -c prims.c prims.h

jsonparser.o: jsonparser.c jsonparser.h
	$(cc) $(cflags) -g -c jsonparser.c jsonparser.h


run : main.c jsonparser.c init_MST.c prims.c graph.c
	gcc main.c jsonparser.c init_MST.c prims.c graph.c
		./a.out
	make clean
			
clean:
	rm *.o main *.gch
