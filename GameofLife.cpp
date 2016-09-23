#include "GameofLife.h"
#include "GameBoard.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <fstream>
using namespace std;
GameofLife::GameofLife(){
	cout<<"I have literally no idea what you expect me to do..."<<endl;
	throw;
}
GameofLife::GameofLife(int bound, int disp, int r, int c, float d){
    oldBoard.setParam(r,c);
    newBoard.setParam(r,c);
    boundary = bound;
    display = disp;
    switch(bound){
      case 1:
            classicFill();
        break;
      case 2:  
        break;
      case 3:  
	mirrorFill();
        break;
      default: cout<<"The value you input is not 1,2 or 3."<<endl;
    }
    
    int count = r*c*d;
    int random;
    while(count>0){
        random = rand()%10+1;
        for(int i =1; i <= c; ++i){
            for(int j=1; j <=r; ++j){
                if(random > 5){
                    oldBoard.setCell(i,j,'X');
                newBoard.setCell(i,j,'X');    
		count--;
                }
            }
        }
    }
    if(boundary == 2){
    	doughnutFill();
    }
    copyBoard();
}

GameofLife::GameofLife(int bound, int disp, string file){
    boundary = bound;
    display = disp;
    switch(bound){
      case 1:
            classicFill();
        break;
      case 2:  
	break;
      case 3:  
	mirrorFill();
        break;
      default: cout<<"The value you input is not 1,2 or 3."<<endl;
    }
    filename = file;
    ifstream readfile(filename.c_str());
    string r;
    string c;
    getline(readfile,r);
    //get the first line from the file which is the number of rows
    row = std::stoi(r,nullptr);
    //convert to integer
    getline(readfile,c);
    //read the second line which is the number of columns
    column = std::stoi(c,nullptr);
    //convert to integer
    oldBoard.setParam(row,column);
    newBoard.setParam(row,column);
    string str;
    int i = 1;
    char d = ' ';
    while(getline(readfile,str))
    {
	    for( int j = 1; j<column+1;++j)
	    {
	        d = str[j-1];
		oldBoard.setCell(i,j,d);
		newBoard.setCell(i,j,d);
	    }
	    i++;
    }
	copyBoard();
	if(boundary == 2){
		doughnutFill();
	}
}

GameofLife::~GameofLife(){
    delete &oldBoard;
    delete &newBoard;
}
void GameofLife::nextGen(){
  for(int i = 1; i<=row; ++i){
    for(int j = 1; j<=column;++j){
      if (oldBoard.countNeighbors(i,j)<=1)
      {
        newBoard.setCell(i,j,'-');
      }
      else if(oldBoard.countNeighbors(i,j)==3)
      {
        newBoard.setCell(i,j,'X');
      }
      else if (oldBoard.countNeighbors(i,j)>=4)
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
  if(boundary==2){
    doughnutFill();
  }
  copyBoard();
}

void playGame(){
	int generation = 0;
	//PrintBoard
	while(!oldBoard.isEqual(newBoard)){
		nextGen();
		generation++;

		 switch(display){
		      case 1:
		      	cout<<"Generation #:\t"<<generation<<endl;
		      	printBoard();
		      	sleep(5);
		      //give 5 sec between
		      //Sakthi
		      break;
		      
		      case 2:
		      	//Print board
		      	cout<<"Generation #:\t"<<generation<<endl;
		      	printBoard();
		      	cout<<"Press any key to continue:"<<endl;
		      	cin.ignore();
		      	cin.get();
		      //wait for cue
		      //Tristan
		      	break;
		      
		      case 3:
		      	appendFile();
		      //append to file.
		      //whoever draws a short straw....
		      	if(generation > 1000)
		      	{
		      		return;
		      	}
		      	break;
		      default: "The value you input is not 1,2 or 3."
    		}
    		if(newBoard.isEmpty()){break;}
	}
}

//fill the buffer zone for mirror mode
void GameofLife::mirrorFill(){
for(int i = 0; i<row; ++i){
  oldBoard.setCell(i,0,'X');
  oldBoard.setCell(i,column+1,'X');
  newBoard.setCell(i,0,'X');
  newBoard.setCell(i,column+1,'X');
}
  for(int j = 0; j<column;++j)
  {
    oldBoard.setCell(0,j,'X');
    oldBoard.setCell(row+1,j,'X');
    newBoard.setCell(0,j,'X');
    newBoard.setCell(row+1,j,'X');
  }
}

//fills the buffer zone for classic mode
void GameofLife::classicFill(){
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
void GameofLife::doughnutFill(){
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

void GameofLife::copyBoard(){
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

string genString(int r){
	string str;
	for(int j = 1; j<=column; ++j)
	{
		str+= oldBoard.getCell(r,j);
	}
	return str;
}
void appendFile(){
	ofstream fileoutput(filename, std::ofstream::app);
	string str;
	for(int i = 1; i<=row; ++i){
		str = genString(i);
		fileoutput<<str<<endl;
	}
	fileoutput.close();
}
void printBoard(){
	string str;
	for(int i = 1; i<=row; ++i){
		str = genString(i);
		cout<<str<<endl;
	}
}
