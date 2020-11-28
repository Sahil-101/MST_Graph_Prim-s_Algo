## Linux Executable file generation steps ##

make

## WINDOWS EXECUTABLE FILE GENERATION STEPS (mingW) ##

gcc -c graph.c

gcc -c prism.c

gcc -c init_MST.c

gcc main.c graph.o init_MST.o prims.o

./a.exe

## After using Files remove them by ##

make clean (for Linux)
del *.o a.exe (for windows)
