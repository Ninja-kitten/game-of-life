import "GameBoard.h"
import <iostream>

GameBoard::GameBoard(int i, int j){
  char board[i+2][j+2];
  rows = i;
  columns = j;
}
GameBoard::~GameBoard(){
  //destroy
}
int GameBoard::countNeighbor(int i, int j){
    int count;
    for(int k=i-1; k<=i+1; ++k)
     {
      for(int l=j-1; l<=j+1; ++l)
          {
            if(board[k][l] == 'X')
              { ++count;}
          }
      }
}
int GameBoard::getRows(){
  return rows;
  //want this functionality. need to refine
}
int GameBoard::getColumns(){
 return columns;
}
char GameBoard::getCell(int i, int j){
  return board[i][j];
}
char GameBoard::setCell(int i, int j, char k){
  return board[i][j] = k;
}
}
