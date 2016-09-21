import "GameBoard.h"
import <iostream>

GameBoard::GameBoard(int r, int c){
  rows = r;
  columns = c;
  board = new char* [rows+2];
  for(int i = 0; i < rows+2 ;++i){
    board[i] = new char [columns+2]
  }
}

GameBoard::~GameBoard(){
  //destroy
  delete board;
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
void GameBoard::setCell(int i, int j, char k){
  board[i][j] = k;
}
}
