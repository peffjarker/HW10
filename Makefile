CC = g++
CXXFLAGS =-std=c++98 -Wall -c

all: build

build: main

main: collegemain.o course.o college.o
	$(CC) -std=c++98 -Wall collegemain.o course.o college.o -o main

collegemain.o: collegemain.cc course.cc  college.cc
	$(CC) $(CXXFLAGS) collegemain.cc course.cc college.cc

course.o: course.cc
	$(CC) $(CXXFLAGS) course.cc

college.o: college.cc
	$(CC) $(CXXFLAGS) college.cc

test: build runtest

runtest: test_college
	./test_college

test_college: test_college.cc course.cc college.cc
	$(CC) $(CXXFLAGS) test_college.cc course.cc college.cc -o test_college

clean:
	rm *.o main test_college
