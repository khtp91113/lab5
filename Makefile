lab5: HugeInt.o lab5.o
	g++ -o lab5 lab5.o HugeInt.o
HugeInt.o: HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp
lab5.o: lab5.cpp HugeInt.h
	g++ -c lab5.cpp
