#include "MineSweeperSolver.h"

// Private Methods
void Grid::InitializeBoard(){
    for(int i = 0; i < board_x; i++){
        for(int j = 0; j < board_y; j++){
            board[i][j].setPosX(i);
            board[i][j].setPosY(j);
            board[i][j].setMineState(false);
            //board[i][j].setHiddenState(false);
        }
    }
}

void Grid::PlaceMines(int n){
    //srand(time(NULL));
    int i,j;
    while(n){
        i = rand() % board_x;
        j = rand() % board_y;

        if(board[i][j].isMine()){
            continue;
        }

        board[i][j].setMineState(true);
        mine_cells.push_back(board[i][j]);
        n--;
    }
}

void Grid::AssignValues(){
    if(mine_cells.size() == 0){
        std::cerr << "Mines not placed" << std::endl;
    }

    for(Cell c : mine_cells){
        // Calculate Values for Cells Surrounding Mines
        for(int i = c.getPosX() - 1; i <= c.getPosX() + 1; i++){
            for(int j = c.getPosY() - 1; j <= c.getPosY() + 1; j++){
                // Check Bounds
                if(i < 0 || i >= board_x)
                    continue;
                if(j < 0 || j >= board_y)
                    continue;
                // Skip Cell Containing Mine being focused on
                if(i == c.getPosX() && j == c.getPosY())
                    continue;

                if(!board[i][j].isMine())
                    board[i][j].incrementValue();
            }
        }
    }
}


// Public Methods
Grid::Grid(int size_x, int size_y){
    board_x = size_x;
    board_y = size_y;
    board = new Cell*[board_x];

    for(int i = 0; i < board_x; i++){
        board[i] = new Cell[board_y];
    }
    InitializeBoard();
    PlaceMines(99);
    AssignValues();
}

Grid::~Grid(){
    for(int i = 0; i < board_x; i++){
        delete[] board[i];
    }
    delete[] board;
}

void Grid::PrintBoard(){
    for(int i = 0; i < board_x; i++){
        for(int j = 0; j < board_y; j++){
            board[i][j].Display();
            //DEBUG
            //std::cout << board[i][j].getValue();

            std::cout << spacing;
        }
        std::cout << std::endl;
    }
}


// Getters
int Grid::getBoardSizeX(){
    return board_x;
}

int Grid::getBoardSizeY(){
    return board_y;
}

std::set<Cell*> Grid::getCellNeighbors(int x, int y){
    Cell *c = &board[x][y];
    std::set<Cell*> NeighborSet;

    //Bounds Checking
    if( x < 0 || x >= this->getBoardSizeX())
        return NeighborSet;
    if( y < 0 || y >= this->getBoardSizeY())
        return NeighborSet;

    // Add all neighbors to return set
    for(int i = c->getPosX() - 1; i <= c->getPosX() + 1; i++){
        for(int j = c->getPosY() - 1; j <= c->getPosY() + 1; j++){
            // Check Bounds
            if(i < 0 || i >= this->getBoardSizeX())
                continue;
            if(j < 0 || j >= this->getBoardSizeY())
                continue;
            // Skip Cell being focused on
            if(i == c->getPosX() && j == c->getPosY())
                continue;

            NeighborSet.insert(&board[i][j]);
        }
    }
    return NeighborSet;

}

//Game Input
void Grid::SelectCell(int x, int y){
    // Bounds Checking
    if( x >= this->getBoardSizeX() || y >= this->getBoardSizeY()){
        std::cerr << "Cell Coordinates Out of Bounds" << std::endl;
        return;
    }

    if( !board[x][y].isHidden() )
        return;

    // Reveal Selected Cell
    board[x][y].setHiddenState(false);

    // Check if Mine


    // Reveal other cells if necessary
    std::set<Cell*> Neighbors = getCellNeighbors(x, y);
    if(board[x][y].getValue() == 0){
        for(Cell *c : Neighbors)
            SelectCell(c->getPosX(), c->getPosY());
    }

}
