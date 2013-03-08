# MAKEFILE para la práctica 6

CXX = gcc
PROJ = msh     # Executable (the micro-shell)

all: $(PROJ)
$(PROJ): libparser.a msh.c parser.h
	$(CXX) -Wall -o $(PROJ) msh.c -L. -lparser

#msh.o: msh.c parser.h
#	$(CXX) -Wall -o msh.o -c msh.c

libparser.a: parser.c parser.h
	$(CXX) -Wall -o parser.o -c parser.c
	ar -r libparser.a parser.o
	rm parser.o

clean:              
	-rm -f *.o *.a $(PROJ)
