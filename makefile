compile: makeTunez.c nodeFunctions.c
	gcc makeTunez.c nodeFunctions.c -o mixtape

run: mixtape
	./mixtape

clean:
	rm *.o
	rm *~
