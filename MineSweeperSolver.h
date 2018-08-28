#ifndef MINESWEEPERSOLVER_H
#define MINESWEEPERSOLVER_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>

class Cell{
private:
    int pos_x;
    int pos_y;
    bool contains_mine;
    int value;
    bool hidden;

public:
    Cell();
    Cell(int x, int y, bool mine);
    ~Cell();

    int getPosX();
    void setPosX(int x);

    int getPosY();
    void setPosY(int y);

    bool isMine();
    void setMineState(bool mine);

    int getValue();
    void incrementValue();
    void setValue(int newValue);

    bool isHidden();
    void setHiddenState(bool state);



    void Display();
};

class Grid{
private:
    Cell **board;
    std::vector<Cell> mine_cells;
    int board_x;
    int board_y;
    char spacing[3] = "  ";

    void InitializeBoard();
    void PlaceMines(int n);
    void AssignValues();

public:
    Grid(int size_x, int size_y);
    ~Grid();

    void PrintBoard();

    // Getters
    int getBoardSizeX();
    int getBoardSizeY();

    std::set<Cell*> getCellNeighbors(int x, int y);
    
    // Game Input
    void SelectCell(int x, int y);


};

#endif
