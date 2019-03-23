proj1: BasicHandler.o proj.o VHandler.o
	gcc BasicHandler.o proj.o VHandler.o -o forensic
BasicHandler.o: BasicHandler.c BasicHandler.h
	gcc -c BasicHandler.c
VHandler.o: VHandler.c VHandler.h
	gcc -c VHandler.c
HHandler.o: HHandler.c HHandler.h 
	gcc -c HHandler.c
proj.o: BasicHandler.o VHandler.o HHandler.o proj.c
	gcc -c proj.c

