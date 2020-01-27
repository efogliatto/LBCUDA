GCC=gcc

latticeBox2D: latticeBox2D.o 
	$(GCC) -o latticeBox2D latticeBox2D.o

latticeBox2D.o: latticeBox2D.c
	$(GCC) -c latticeBox2D.c

clean:
	rm *.o latticeBox2D
