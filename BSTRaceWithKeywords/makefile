all: compile test run

compile:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/Manager.o -c ./src/Manager.cpp
	
test:
	g++ -I ./include/ -o ./bin/Test ./lib/BST.o ./lib/Node.o ./lib/Manager.o ./src/Test.cpp
run:
	./bin/Test