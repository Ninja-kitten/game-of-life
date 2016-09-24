#include "GameBoard.h"
#include <iostream>
using namespace std;

GameBoard::GameBoard(){}//default constructor
GameBoard::GameBoard(int r, int c){//overloaded constructor to get the gameboard size. We make the board one row and column bigger than
                                  //specified for some clever purposes.
  rows = r;
  columns = c;
  board = new char* [rows+2];
  for(int i = 0; i < rows+2 ;++i){
    board[i] = new char [columns+2];
  }
  fillBlank();
}
void GameBoard::setParam(int r, int c){//A function that acts a "reconstructor". Idea came from stack exchange.
  rows = r;
  columns = c;
  board = new char* [rows+2];
  for(int i = 0; i < rows+2 ;++i){
    board[i] = new char [columns+2];
  }
  fillBlank();
}

void GameBoard::fillBlank(){
  for(int i = 0; i<rows+2; ++i){
    for(int j = 0; j<columns+2; ++j){
      setCell(i,j,'-');
    }
  }
}
GameBoard::~GameBoard(){//destructor
  //destroy
  for (int i = 0;i<rows+2;++i){
    for(int j = 0; j<columns+2;++j){
      delete board[i][j];}
      delete[] board[i];
  }
  delete[] board;
}

int GameBoard::countNeighbors(int i, int j){//Function to count the live neighbors around the cell that is specified
    int count;
    for(int k=i-1; k<=i+1; ++k)//nested forloop to check the surrounding 8 neighbors
     {
      for(int l=j-1; l<=j+1; ++l)
          {
            if(board[k][l] == 'X')
              { ++count;}
          }
      }
      return count;
}

int GameBoard::getRows(){//gets the number of rows
  return rows;
  //want this functionality. need to refine
}

int GameBoard::getColumns(){//gets the number of columns
    return columns;
}
char GameBoard::getCell(int i, int j){//gets the value in the specified cell
  return board[i][j];
}
void GameBoard::setCell(int i, int j, char k){//sets the value of the specified sell to the character specified by k.
  board[i][j]=k;
}


bool GameBoard::isEqual(GameBoard g){//checks if the gameboards are equal in size and character
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

bool GameBoard::isEmpty()//Checking if the specified cell is empty
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
