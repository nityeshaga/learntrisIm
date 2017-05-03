tetramino.o: tetramino.c tetramino.h
	gcc -c tetramino.c

matrix.o: matrix.c matrix.h
	gcc -c matrix.c

learntris.o: learntris.c tetramino.h
	gcc -c learntris.c

learntris: learntris.o tetramino.o matrix.o
	gcc learntris.o tetramino.o matrix.o -o learntris
