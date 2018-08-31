# MineSweeperSolver
## Contents
10. Overview
20. Build Instructions
30. Features
  1. Implemented
  2. Planned
40. Directory and File Descriptions

## 1. Overview
This project is an attempt to create a simple Mine Sweeper Solver AI similar to
that described by [Code-Bullet](https://github.com/Code-Bullet/minesweeper-AI)
in the YouTube video "[I created a PERFECT minesweeper AI](https://www.youtube.com/watch?v=cGUHehFGqBc)".
This project is purely an excuse to become more familiar with C++ programming.
The project will contain the following deliverables:
1. **MineSweeper Game** - A simple program to handle all game logic. Will be
responsible for randomly generating the game board, accepting input, and keeping
track of the game state.
2. **Solver** - A program which attempts to solve the game board created by the
MineSweeper Game Program.

## 2. Build Instructions
### MineSweeper Game
```Shell
$ cd .../MineSweeperSolver/
$ make
```

### Solver
Not Yet Created

## 3. Features
Laundry list of current and future features for the deliverables included with
this project. Features are listed in no particular order.

### 3.1 Implemented Features
#### Mine Sweeper Game
* Generates a 16x30 grid of cells
* Randomly hides 99 mines throughout the board **(CURRENTLY DISABLED FOR
DEVELOPMENT)**
* Cell values are dynamically calculated based on number of surrounding mines
* Cells can be selected via terminal input of 0-indexed "x y" pair
* Selecting a cell of value 0, with no adjacent cells containing mines, reveals
all surrounding cells.
* Board state can be printed in the terminal

#### Solver
In Planning Stage

### 3.2 Planned Features
#### Mine Sweeper Game
* Cells may be flagged by the user
* Flagged Mines cannot be selected via terminal input
* Terminal input can be treated differently depending on intended action. (i.e.
  selecting a cell to be revealed vs. flagging a cell)
* Selecting a Cell containing a bomb triggers LOSS state
* Flagging all Cells containing bombs triggers WIN state
* Revealing all cells which do not contain bombs triggers WIN state
* Variable size game boards
* Variable hidden mine amounts

#### Solver
* Still working on the math for this. Check back later.

## 4. Directory and File Descriptions
TODO when directory is set up properly.
