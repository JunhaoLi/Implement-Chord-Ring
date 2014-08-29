CC=g++



Chord_Ring:main.o helper.o sha_ex.o
	$(CC) -o chord_ring main.o

main.o: main.c
	$(CC) -c main.c

helper.o: helper.c
	$(CC) -c helper.c

sha_ex.o: sha_ex.c
	$(CC) -c sha_ex.c

clean:
	rm -f *.o
