LIBPATH=$(HOME)/codes/CG

all:mainwithoutDetectioncg

cg_lib.o: cg_lib.cpp cg_lib.hpp
	g++ -c -I/$(LIBPATH) cg_lib.cpp
	#mpic++ -c -I/$(LIBPATH) cg_lib.cpp
	#mv cg_lib.o $(LIBPATH)/cg_lib.o

main.o: main.cpp
	g++ -c -I/$(LIBPATH) main.cpp
	#mpic++ -c -I/$(LIBPATH) main.cpp
	#mv main.o $(LIBPATH)/main.o

mainwithoutDetectioncg: cg_lib.o main.o
	#g++ main.o $(LIBPATH)/cg_lib.o -lm -o main
	g++ main.o cg_lib.o -lm -o mainwithoutDetectioncg
	#mpic++ main.o cg_lib.o -lm -o main

clean:
	rm *.o   
	rm mainwithoutDetectioncg
