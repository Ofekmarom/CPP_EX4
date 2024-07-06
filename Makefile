#ID : 208336701
#mail : ofekmarom9@gmail.com

#matala 4

CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99
# Header files
HEADERS = Complex.hpp Node.hpp Tree.hpp
# Source files
SRC_MAIN = Main.cpp Complex.cpp
SRC_TEST = Test.cpp Complex.cpp
# Object files
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)
OBJ_TEST = $(SRC_TEST:.cpp=.o)



# Targets
all: main test

tree: main
	./main

runtest: test
	./$^

main: $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) $(OBJ_MAIN) -o main $(LDFLAGS)

test: $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) $(OBJ_TEST) -o test $(LDFLAGS)

valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test


%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean tree runtest

clean:
	rm -f *.o main test

