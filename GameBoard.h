#ifndef GAMEBOARD_H
#define GAMEBOARD_H
class GameBoard{
public:
GameBoard();//Default constructor
GameBoard(int,int); //Overloaded constructor that takes in integer parameters to specify the gameboard size
~GameBoard();


int countNeighbors(int , int );
//Accessors
int getRows();
int getColumns();
char getCell(int , int );
//Mutators
void setCell(int , int, char);
void setParam(int, int);
//Fills the entire board with '-'
void fillBlank();
//Checks equivalence of two GameBoards
bool isEqual(GameBoard);
//Checks if a board is empty
bool isEmpty();

private:
int rows;
int columns;
char ** board;

};
#endif
