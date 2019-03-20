proj1: BasicHandler.o proj.o VHandler.o
	gcc BasicHandler.o proj.o VHandler.o -o forensic
BasicHandler.o: BasicHandler.c BasicHandler.h
	gcc -c BasicHandler.c
VHandler.o: VHandler.c VHandler.h
	gcc -c VHandler.c
proj.o: BasicHandler.o VHandler.o proj.c
	gcc -c proj.c

