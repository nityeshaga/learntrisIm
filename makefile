tetramino.o: tetramino.c tetramino.h
	gcc -c tetramino.c

learntris.o: learntris.c tetramino.h
	gcc -c learntris.c

learntris: learntris.o tetramino.o
	gcc learntris.o tetramino.o -o learntris
