#include "GameofLife.h"
#include "GameBoard.h"
#include "BoundaryMode.h"
#include "DisplayMode.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;
GameofLife::GameofLife(){
}

GameofLife::~GameofLife(int bound, int disp, std::string file){
  
}

GameofLife::nextGen(){
  for(int i = 1; i<=row; ++i){
    for(int j = 1; j<=oldBoard.column;++j){
      if (oldBoard.countNeighbors(i,j)<=1)
      {
        newBoard.setCell(i,j,'-');
      }
      else if(oldBoard.countNeighbors(i,j)==3)
      {
        newBoard.setCell(i,j,'X');
      }
      else if (oldboard.countNeighbors(i,j)>=4)
      {
        newBoard.setCell(i,j,'-');
      }
      else
      {
        char c = oldBoard.getCell(i,j);
        newBoard.setCell(i,j,c)
      }
    }
  }
  if(BoundaryMode::DOUGHNUT==boundary){
    doughnutFill();
  }
}

//fill the buffer zone for mirror mode
GameofLife::mirrorFill(){
for(int i = 0; i<row; ++i){
  oldBoard.setCell(i,0,'X');
  oldBoard.setCell(i,columns+1,'X');
  newBoard.setCell(i,0,'X');
  newBoard.setCell(i,columns+1,'X');
}
  for(int j = 0; j<column;++j)
  {
    oldBoard.setCell(0,j,'X');
    oldBoard.setCell(rows+1,j,'X');
    newBoard.setCell(0,j,'X');
    newBoard.setCell(rows+1,j,'X');
  }
}

//fills the buffer zone for classic mode
GameofLife::classicFill(){
  for(int i = 0; i<2+row; ++i)
  {
    oldBoard.setCell(i,0,'-');
    oldBoard.setCell(i,column+1,'-');
    newBoard.setCell(i,0,'-');
    newBoard.setCell(i,column+1,'-');
  }
for(int j = 0; j<2+column;++j)
  {
    oldBoard.setCell(0,j,'-');
    oldBoard.setCell(row+1,j,'-');
    newBoard.setCell(0,j,'-');
    newBoard.setCell(row+1,j,'-');
  }
}

//fills the buffer zone for doughnut mode
GameofLife::doughnutFill(){
  char c = ' ';
  for(int i=1; i<1+row;++i)
  {
    c =  newBoard.getCell(i,column);
    newBoard.setcell(i,0,c);
    c =  newBoard.getCell(i,1);
    newBoard.setcell(i,column+1,c);
  }
    for(int j=1, j<1+column;++j)
  {
    c =  newBoard.getCell(1,j);
    newBoard.setcell(row+1,j,c);
    c =  newBoard.getCell(row,j);
    newBoard.setcell(0,j,c);
  }
}  
