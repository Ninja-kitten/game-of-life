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
  if(BoundaryMode::DOUGHNUT==boundary){
    doughnutFill();
  }
}

//fill the buffer zone for mirror mode
GameofLife::mirrorFill(){
for(int i = 0; i<oldBoard.getRows; ++i){
  oldBoard.setCell(i,0,'X')
  oldBoard.setCell(i,columns+1,'X')
  newBoard.setCell(i,0,'X')
  newBoard.setCell(i,columns+1,'X')
}
  for(int j = 0; j<oldBoard.getColumns;++j)
  {
    oldBoard.setCell(0,j,'X')
    oldBoard.setCell(rows+1,j,'X')
    newBoard.setCell(0,j,'X')
    newBoard.setCell(rows+1,j,'X')
  }
}

//fills the buffer zone for classic mode
GameofLife::classicFill(){
  for(int i = 0; i<2+oldBoard.getRows; ++i)
  {
    oldBoard.setCell(i,0,'-')
    oldBoard.setCell(i,columns+1,'-')
    newBoard.setCell(i,0,'-')
    newBoard.setCell(i,columns+1,'-')
  }
for(int j = 0; j<2+oldBoard.getColumns;++j)
  {
    oldBoard.setCell(0,j,'-')
    oldBoard.setCell(rows+1,j,'-')
    newBoard.setCell(0,j,'-')
    newBoard.setCell(rows+1,j,'-')
  }
}

//fills the buffer zone for doughnut mode
GameofLife::doughnutFill(){
  for(int i=1; i<1+newBoard.getRows();++i)
  {
    newBoard.setcell(i,0,newBoard.getCell(i,columns))
    newBoard.setcell(i,newBoard.getColumns(),newBoard.getCell(i,columns))
  }
    for(int j=1, j<1+newBoard.getColumns();++i)
  {
    newBoard.setcell(0,j,newBoard.getCell(i,columns))
    newBoard.setcell(newBoard.getRows+1,j,newBoard.getCell(i,columns))
  }
}  
