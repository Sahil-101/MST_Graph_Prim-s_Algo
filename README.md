# DSC Project
Euclidean Minimum Spanning Tree

## Team Members
1. Sahil (1MS19CS103)
2. Shubham (1MS19CS118)
3. Siddharth (1MS19CS121)
4. Sai Aakash (1MS19CS104)

## Linux Executable file generation steps ##

make run

## WINDOWS EXECUTABLE FILE GENERATION STEPS (mingW) ##

gcc -c graph.c

gcc -c prism.c

gcc -c init_MST.c

gcc main.c graph.o init_MST.o prims.o

./a.exe

## After using Files remove them by ##

make clean (for Linux)
del *.o a.exe (for windows)
