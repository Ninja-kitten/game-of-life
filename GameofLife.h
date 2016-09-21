#include "GameBoard.h"
#include "BoundaryMode.h"
#include "DisplayMode.h"
#include <string>
class GameofLife{
public:
GameofLife();
GameofLife(int bound,int disp, int r, int c, float d);
//Constructor for random configuration

GameofLife(int bound,int disp, std::string file);
//constructor for uploaded map with std::string type argument for filename

~GameofLife();
//destructor
void nextGen();
//Moves the gameboard over to the next generation

void playGame();
//starts the game of life and keeps on going until it's either empty or stable

void mirrorFill();
//fills the buffer region with X for mirror mode upon creation of the board

void classicFill();
//fills the buffer region with - for the mirror upon creation of the Board

void doughnutFill();
//fills the buffer zone at the end of every generation.

void copyBoard();
//copies a board to make it another one.

void pausePlay();
void enterPlay();
void filePlay();

private:

GameBoard(int,int);
~GameBoard();


int countNeighbors(int , int );
int getRows();
int getColumns();
char getCell(int , int );
void setCell(int , int, char);

bool isEqual(GameBoard);
bool isEmpty();

private:
int rows;
int columns;
char ** board;

};
BoundaryMode boundary;
//chooses the boundary taurus 
DisplayMode display;
//
GameBoard oldBoard;
//Gameboard before the generation change
GameBoard newBoard;
//GameBoard after the generation shifts
}
int row;
int column;

