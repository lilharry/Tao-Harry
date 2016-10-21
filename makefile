compile:playlistFunctions.c nodeFunctions.c myTunez.c
	gcc playlistFunctions.c nodeFunctions.c myTunez.c -o mixtape

run:mixtape
	./mixtape

clean:
	rm *.o
	rm *~
