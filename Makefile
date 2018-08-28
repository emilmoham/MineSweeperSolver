CC = gcc
CXX = g++

CFLAGS = -std=c++11

HEADERS = MineSweeperSolver.h
SOURCES = Game.cpp Grid.cpp Cell.cpp
SOURCE_FOLDER = src

BINOUT = bin
GAME_EXE = Game
SOLVER_EXE = Solver


all: folders
	$(CXX) $(CFLAGS) $(HEADERS) $(SOURCES) -o $(BINOUT)/$(GAME_EXE)

folders:
	mkdir -p ./$(BINOUT)

clean:
	rm -rf ./$(BINOUT)
