LIBPATH=$(HOME)/codes/CG

all: maincr1

cg_lib.o: cg_lib.cpp cg_lib.hpp
	g++ -c -I/$(LIBPATH) cg_lib.cpp
	#mpic++ -c -I/$(LIBPATH) cg_lib.cpp
	#mv cg_lib.o $(LIBPATH)/cg_lib.o

main.o: main.cpp
	g++ -c -I/$(LIBPATH) main.cpp
	#mpic++ -c -I/$(LIBPATH) main.cpp
	#mv main.o $(LIBPATH)/main.o

mainbcr: cg_lib.o main.o
	#g++ main.o $(LIBPATH)/cg_lib.o -lm -o main
	g++ main.o cg_lib.o -lm -o maincr1
	#mpic++ main.o cg_lib.o -lm -o main

clean:
	rm *.o   
	rm maincr1
