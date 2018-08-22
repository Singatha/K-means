# ML Lab 1 makefile
# Xhanti Singatha
CC=g++


kmean: KmeanAlgorithm.o 
	$(CC)  KmeanAlgorithm.o -std=c++11 -o kmean

KmeanAlgorithm.o: KmeanAlgorithm.cpp
	$(CC) KmeanAlgorithm.cpp -std=c++11 -c

clean:
	@rm -f *.o
