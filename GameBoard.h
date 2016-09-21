class GameBoard{
public:
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
