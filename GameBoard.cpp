#include "GameBoard.h"
#include <iostream>
using namespace std;

GameBoard::GameBoard(){}
GameBoard::GameBoard(int r, int c){
  rows = r;
  columns = c;
  board = new char* [rows+2];
  for(int i = 0; i < rows+2 ;++i){
    board[i] = new char [columns+2];
  }
}
GameBoard::setParam(int r, int c){
  rows = r;
  columns = c;
  board = new char* [rows+2];
  for(int i = 0; i < rows+2 ;++i){
    board[i] = new char [columns+2];
  }
}
GameBoard::~GameBoard(){
  //destroy
  delete board;
}

int GameBoard::countNeighbors(int i, int j){
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

bool GameBoard::isEqual(GameBoard g){
  if(rows != g.getRows()|| columns != g.getColumns()){
    for(int i = 0; i<1000; ++i){
      cout<<"YOU FUCKING IDIOT!!! THEY'RE NOT EVEN THE SAME SIZE"<<endl;
      cout<<"idiot"<<endl;
    }
    return false;
  }
  char c;
  for(int i = 1; i<rows+1;++i){
    for(int j = 1; j <columns+1; ++j){
      c = g.getCell(i,j);
      if(board[i][j] != c)
        return false;
    }
  }
  return true;
}

bool GameBoard::isEmpty()
{
  char c = '-';
  for(int i = 1; i<rows+1;++i){
    for(int j = 1; j <columns+1; ++j){
      if(board[i][j] != c)
        return false;
    }
  }
  return true;
}
