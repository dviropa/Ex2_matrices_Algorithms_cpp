CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
SRC = SquareMat.cpp Node.cpp

all: Main

Main: main.cpp $(SRC)
	$(CXX) $(CXXFLAGS) -o Main main.cpp $(SRC)

test: test_matrices.cpp $(SRC)
	$(CXX) $(CXXFLAGS) -o test test_matrices.cpp $(SRC)
	./test

valgrind: test_matrices.cpp $(SRC)
	valgrind --leak-check=full ./test

clean:
	rm -f Main test *.o
	