#include "MineSweeperSolver.h"

Cell::Cell(){
    pos_x = 0;
    pos_y = 0;
    contains_mine = false;
    hidden = true;
}

Cell::Cell(int x, int y, bool mine){
    pos_x = x;
    pos_y = y;
    contains_mine = mine;
    value = 0;
}

Cell::~Cell(){}

// Position Access 
int Cell::getPosX(){
    return pos_x;
}

void Cell::setPosX(int x){
    pos_x = x;
}

int Cell::getPosY(){
    return pos_y;
}

void Cell::setPosY(int y){
    pos_y = y;
}

// Mine State Access
void Cell::setMineState(bool mine){
    if(mine)
        value = 9;
    else
        value = 0;
    contains_mine = mine;
}

// Cell Value Access
bool Cell::isMine(){
    return contains_mine;
}

int Cell::getValue(){
    return value;
}

void Cell::incrementValue(){
    value++;
}


// Cell Game State Access
void Cell::setValue(int newValue){
    value = newValue;
}

bool Cell::isHidden(){
    return hidden;
}

void Cell::setHiddenState(bool state){
    hidden = state;
}


void Cell::Display(){
    if(this->isHidden()){
        std::cout << "H";
    } else if (this->isMine()){
        std::cout << " ";
    } else {
        std::cout << this->getValue();
    }
}
