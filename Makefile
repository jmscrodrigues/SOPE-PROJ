proj1: BasicHandler.o proj.o
	gcc BasicHandler.o proj.o -o proj
BasicHandler.o: BasicHandler.c BasicHandler.h
	gcc -c BasicHandler.c
proj.o: BasicHandler.o proj.c
	gcc -c proj.c
