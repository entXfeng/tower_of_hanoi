all: bin/hanoi

clean:
	@echo limpiando..
	rm obj/*.o
mrproper:
	clean
	rm bin/*
run:
	bin/hanoi

obj/hanoi.o:	src/hanoi.cpp include/tower.h
	g++ -c -Iinclude -o obj/hanoi.o src/hanoi.cpp

obj/tower.o:	src/tower.cpp include/tower.h
	g++ -c -Iinclude -o obj/tower.o src/tower.cpp

bin/hanoi:	obj/hanoi.o obj/tower.o 
	g++ -o bin/hanoi obj/hanoi.o obj/tower.o 
