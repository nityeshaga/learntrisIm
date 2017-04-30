learntris.o: learntris.c
	gcc -c learntris.c

learntris: learntris.o
	gcc learntris.o -o learntris
