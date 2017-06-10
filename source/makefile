generic.o: generic.c generic.h
	gcc -c generic.c

tetramino.o: tetramino.c tetramino.h generic.h
	gcc -c tetramino.c

matrix.o: matrix.c matrix.h generic.h
	gcc -c matrix.c

learntris.o: learntris.c tetramino.h matrix.h generic.h
	gcc -c learntris.c

learntris: learntris.o tetramino.o matrix.o generic.o
	gcc learntris.o tetramino.o matrix.o generic.o -o learntris
