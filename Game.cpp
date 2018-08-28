#include "MineSweeperSolver.h"

using namespace std;

int main(int argc, char **argv){
    int x, y;
    Grid *grid = new Grid(16, 30);

    grid->PrintBoard();
    //while(true){
        cout << endl;
        cin >> x >> y;
        cout << endl;
        grid->SelectCell(x, y);
        grid->PrintBoard();
        cout << endl;
    //}
    return 0;
}
