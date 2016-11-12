CXX = g++
CXXFLAGS = -O3 -std=c++11
SRC = src/*.cpp
BIN = bin/so-t2
INC = includes/

all:
	@$(CXX) -I $(INC) $(SRC) $(CXXFLAGS) -o $(BIN)

clean:
	@rm -rf $(BIN)
