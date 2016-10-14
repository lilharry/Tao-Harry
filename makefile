compile:myTunez.c nodeFunctions.c
	gcc myTunez.c nodeFunctions.c -o mixtape

run:mixtape
	./mixtape

clean:
	rm *.o
	rm *~
