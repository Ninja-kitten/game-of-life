#include "GameBoard.h"
#include "BoundaryMode.h"
#include "PauseMode.h"
#include <string>
class GameofLife{
public:
GameofLife(BoundaryMode,PauseMode, int, int);
//Constructor for random configuration

GameofLife(BoundaryMode,PauseMode, std::string);
//constructor for uploaded map with std::string type argument for filename

~GameofLife();
//destructor
void nextGen();
//Moves the gameboard over to the next generation

private:
BoundaryMode boundary();
//chooses the boundary taurus 
pausemode pause();
//
GameBoard oldBoard();
//Gameboard before the generation change
GameBoard newBoard();
//GameBoard after the generation shifts
}
int row;
int column;

