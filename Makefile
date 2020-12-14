# 27/11/2020
#Makefile

.Phony:
	clean

cflags = -Wall -Wmissing-declarations -Wmissing-prototypes -fsanitize=address -fno-omit-frame-pointer
cc = gcc

main: graph.o main.o init_MST.o prims.o jsonparser.o
	$(cc) $(cflags) -g main.o graph.o init_MST.o prims.o jsonparser.o -o main -lm
	./main
	curl -X PUT -d @./data1.json https://website-8e733.firebaseio.com/root.json
	make clean

main.o: main.c
	$(cc) $(cflags) -g -c main.c graph.h init_MST.h prims.h

graph.o: graph.c graph.h
	$(cc) $(cflags) -g -c graph.c graph.h

init_MST.o: init_MST.c init_MST.h 
	$(cc) $(cflags) -g -c init_MST.c init_MST.h

prims.o: prims.c prims.h
	$(cc) $(cflags) -g -c prims.c prims.h

jsonparser.o: jsonparser.c jsonparser.h
	$(cc) $(cflags) -g -c jsonparser.c jsonparser.h
	
clean:
	rm *.o *.gch
