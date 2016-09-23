#ifndef GAMEBOARD_H
#define GAMEBOARD_H
class GameBoard{
public:
GameBoard();//Default constructor
GameBoard(int,int); //Overloaded constructor that takes in integer parameters to specify the gameboard size
~GameBoard();


int countNeighbors(int , int );
int getRows();
int getColumns();
char getCell(int , int );
void setCell(int , int, char);
void setParam(int, int);

bool isEqual(GameBoard);
bool isEmpty();

private:
int rows;
int columns;
char ** board;

};
#endif
