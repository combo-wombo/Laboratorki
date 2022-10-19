all: las_16fp

las_16fp: las_16fp.o las_16u.o
	gcc -o las_16fp las_16fp.o las_16u.o

las_16fp.o: las_16fp.c
	gcc -c las_16fp.c

las_16u.o: las_16u.c
	gcc -c las_16u.c
	
clean:
	rm -rf *.o las_16fp

