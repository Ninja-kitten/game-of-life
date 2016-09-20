class GameBoard{
public:
GameBoard(int,int);
~GameBoard();

/*bool isNeighbor(Cell,Cell);
bool isEdge(Cell);
bool isCorner(Cell);
bool isEmpty(Cell);
bool isFull(Cell);
bool setMode();*/
int countNeighbors(int , int );
/*int cornerCount();
int edgeCount();*/
int getRows();
int getColumns();
char getCell(int , int );
void setCell(int , int, char);

private:
int rows;
int columns;
char ** board;

  
}
