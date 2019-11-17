all: compile test run

compile:
	g++ -I ./include/ -o ./lib/Ball.o -c ./src/Ball.cpp
	g++ -I ./include/ -o ./lib/Bucket.o -c ./src/Bucket.cpp
	g++ -I ./include/ -o ./lib/BucketControl.o -c ./src/BucketControl.cpp
	
test:
	g++ -I ./include/ -o ./bin/Test ./lib/Ball.o ./lib/BucketControl.o ./lib/Bucket.o ./src/Test.cpp
run:
	./bin/Test