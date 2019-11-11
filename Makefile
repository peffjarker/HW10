CC = g++
CXXFLAGS =-std=c++98 -Wall -c

all: build

build: main

main: collegemain.o course.o college.o
	$(CC) -std=c++98 -Wall collegemain.o course.o college.o -o main

course.o: course.cc
	$(CC) $(CXXFLAGS) course.cc

college.o: college.cc
	$(CC) $(CXXFLAGS) college.cc

test: build runtest

runtest: test_college
	./test_college

test_college: test_college.o college.o course.o
	$(CC) -std=c++11 -Wall test_college.o college.o course.o -o test_college

test_college.o: test_college.cc college.cc course.cc
	$(CC) -std=c++11 -Wall -c test_college.cc college.cc course.cc


clean:
	rm *.o test_college main
