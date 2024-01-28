CC = gcc
CFLAGS = -Wall -g
FPIC_FLAG = -fPIC

all: mains maindloop maindrec loops loopd recursives recursived #default target

# Create dynamic libraries
recursived: libclassrec.so 
loopd: libclassloops.so 


# Create static libraries
loops: libclassloops.a 
recursives: libclassrec.a


# Build executables
mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.o ./libclassloops.so 

maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o ./libclassrec.so


# Build static libraries
libclassloops.a:basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o


# Build dynamic/shared libraries
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o 

libclassrec.so: basicClassification.o advancedClassificationRecursion.o	
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o


# Build object files
main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) $(FPIC_FLAG) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) $(FPIC_FLAG) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) $(FPIC_FLAG) -c advancedClassificationRecursion.c


# Clean build files
clean:
	rm -f *.so *.a *.o mains maindrec maindloop 