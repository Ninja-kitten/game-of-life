#include "GameofLife.h"
#include "GameBoard.h"
#include "BoundaryMode.h"
#include "DisplayMode.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;
GameofLife::GameofLife(){
	cout<<"I have literally no idea what you expect me to do..."<<endl;
	throw;
}
GameofLife::GameofLife(int bound, int disp, int r, int c, float d){
    oldBoard = new GameBoard(r,c);
    switch(bound){
      case 1: boundarymode= CLASSIC;
            classicFill();
        break;
      case 2: boudnarymode = DOUGHNUT; 
        break;
      case 3: boundarymode = MIRROR; 
	mirrorFill();
        break;
      default: "The value you input is not 1,2 or 3."
    }
    switch(disp){
      case 1: boundarymode= Pause;
        break;
      case 2: boundarymode = Enter; 
        break;
      case 3: boundarymode = File; 
        break;
      default: "The value you input is not 1,2 or 3."
    }
    count = r*c*d;
    while(count>0){
        random = rand()%10+1;
        for(int i =1; i <= c; ++i){
            for(int j=1; j <=r; ++j){
                if(random > 5){
                    oldBoard.setCell(i,j,'X');
                    count--;
                }
            }
        }
    }
  
  
}

GameofLife::GameofLife(int bound, int disp, std::string file){
   switch(bound){
      case 1: boundarymode= CLASSIC;
            oldBoard.classicFill();
            newBoard.classicFill();
        break;
      case 2: boudnarymode = DOUGHNUT; 
        break;
      case 3: boundarymode = MIRROR; 
            oldBoard.mirrorFill();
            newBoard.mirrorFill();
        break;
      default: "The value you input is not 1,2 or 3."
    }
    switch(disp){
      case 1: boundarymode= Pause;
        break;
      case 2: boundarymode = Enter; 
        break;
      case 3: boundarymode = File; 
        break;
      default: "The value you input is not 1,2 or 3."
    }
    ifstream readfile(file);
    str r;
    str c;
    getline(readfile,r)
    //get the first line from the file which is the number of rows
    row = stoi(r,nullptr)
    //convert to integer
    getline(readfile,c)
    //read the second line which is the number of columns
    column = stoi(c,nullptr)
    //convert to integer
    oldBoard = new GameBoard(row,column);
    newBoard = new GameBoard(row,column);
    string str;
    int i = 1;
    char c = ' ';
    while(getline(readfile,str))
    {
	    for( int j = 1; j<column+1;++j)
	    {
	        c = str[j-1];
		    oldBoard.setCell(i,j,c);
	    }
    }
}

GameofLife::~GameofLife(){
    delete oldBoard;
    delete newBoard;
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
  copyBoard();
}

void playGame(){
	while(!oldBoard.isEqual(newBoard)){
		//System pause stuff here i guess...
		//Let's do it in another function...
		 switch(display){
		      case PAUSE:
		      	sleep(5);
		      //give 5 sec between
		      //Sakthi
		      break;
		      
		      case ENTER:
		      	enterPlay();
		      //wait for cue
		      //Tristan
		      	break;
		      
		      case FILE:
		      	filePlay();
		      //output a file
		      	break;
		      default: "The value you input is not 1,2 or 3."
    		}
    		if(newBoard.isEmpty()){break;}
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
  //take care of all the corners
  c = newBoard.getCell(1,1);
  newBoard.setCell(row+1,column+1);
  c= newBoard.getCell(1,column);
  newBoard.setCell(row+1,0);
  c= newBoard.getCell(row,1);
  newBoard.setCell(0,column+1);
  c = newBoard.getCell(row,column);
  newBoard.setCell(0,0);
 
  for(int i=1; i<1+row;++i)
 //goest through each row in the interior
  {
    c =  newBoard.getCell(i,column);
    //grabs the right edge
    newBoard.setcell(i,0,c);
    //sets the value to the left buffer
    c =  newBoard.getCell(i,1);
    //grabs the left edge of interior
    newBoard.setcell(i,column+1,c);
    sets it to right edge of the buffer
  }
    for(int j=1, j<1+column;++j)
    //goes through each column in the interior
  {
    c =  newBoard.getCell(1,j);
    //grabs the value of the top edge interior
    newBoard.setcell(row+1,j,c);
    //sets it to the bottom buffer
    c =  newBoard.getCell(row,j);
    //grabs the bottom edge interior
    newBoard.setcell(0,j,c);
    //sets it to the top buffer
  }
  
} 

GameofLife::copyBoard(){
	char c;
	for(int i = 0; i<row+2;++i){
		for(int j = 0; j< column+2; ++j){
			c = newBoard.getCell(i,j);
			//takes cell value from new
			oldBoard.setCell(i,j,c);
			//sets it to the old
		}
	}
}
