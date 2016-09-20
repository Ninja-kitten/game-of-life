#include "GameofLife.h"
GameofLife::GameofLife(){
}

GameofLife::~GameofLife(){
}

GameofLife::nextGen(){
  for(int i = 1; i<=oldBoard.getRows(); ++i){
    for(int j = 1; j<=oldBoard.getColumns();++j){
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
        newBoard.setCell(i,j,oldBoard.getCell(i,j))
      }
    }
  }
}
