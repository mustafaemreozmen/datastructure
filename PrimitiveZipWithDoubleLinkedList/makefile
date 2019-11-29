all: compile test run

compile:
	g++ -I ./include/ -o ./lib/DoubleLinkedList.o -c ./src/DoubleLinkedList.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/ReadingOperations.o -c ./src/ReadingOperations.cpp
	
test:
	g++ -I ./include/ -o ./bin/Test ./lib/DoubleLinkedList.o ./lib/Node.o ./lib/ReadingOperations.o ./src/Test.cpp
run:
	./bin/Test