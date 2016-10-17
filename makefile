compile:nodeFunctions.c myTunez.c
	gcc nodeFunctions.c myTunez.c -o mixtape

run:mixtape
	./mixtape

clean:
	rm *.o
	rm *~
