#ifndef GAMEBOARD_H
#define GAMEBOARD_H
class GameBoard{
public:
GameBoard();
GameBoard(int,int);
~GameBoard();


int countNeighbors(int , int );
int getRows();
int getColumns();
char getCell(int , int );
void setCell(int , int, char);
void setParam(int, int)

bool isEqual(GameBoard);
bool isEmpty();

private:
int rows;
int columns;
char ** board;

};
#endif
