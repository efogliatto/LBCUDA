GCC=gcc
OBJS=latticeBox2D.o int2dArray.o latticeVelocities.o D2Q9_Vel.o latticeReverseDir.o D2Q9_Reverse.o writeBasicMesh.o

latticeBox2D: ${OBJS}
	$(GCC) -o latticeBox2D ${OBJS}

latticeBox2D.o: latticeBox2D.c include/basicMesh.h
	$(GCC) -c latticeBox2D.c

int2dArray.o: int2dArray.c 
	$(GCC) -c int2dArray.c

latticeVelocities.o: latticeVelocities.c
	$(GCC) -c latticeVelocities.c

D2Q9_Vel.o: D2Q9_Vel.c 
	$(GCC) -c D2Q9_Vel.c

latticeReverseDir.o: latticeReverseDir.c
	$(GCC) -c latticeReverseDir.c

D2Q9_Reverse.o: D2Q9_Reverse.c 
	$(GCC) -c D2Q9_Reverse.c

writeBasicMesh.o: writeBasicMesh.c 
	$(GCC) -c writeBasicMesh.c

clean:
	rm *.o latticeBox2D
