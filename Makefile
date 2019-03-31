proj1: BasicHandler.o proj.o VHandler.o RHandler.o
	gcc BasicHandler.o proj.o VHandler.o RHandler.o -o forensic -Wall
BasicHandler.o: BasicHandler.c BasicHandler.h
	gcc -c BasicHandler.c
VHandler.o: VHandler.c VHandler.h
	gcc -c VHandler.c
RHandler.o: RHandler.c RHandler.h
	gcc -c RHandler.c
proj.o: BasicHandler.o VHandler.o RHandler.o proj.c
	gcc -c proj.c
