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
GameofLife::GameofLife(){//Default constructor. If no parameters are specified.
	cout<<"I have literally no idea what you expect me to do..."<<endl;
	throw;
}
GameofLife::GameofLife(int bound, int disp, int r, int c, float d){//Overloaded constructor to start setting up the game if user
								   //specifies that they want random generations instead of using a file.
    oldBoard.setParam(r,c);//Setting the sizes of the old and new boards. 2 boards used for creating new generations.
    newBoard.setParam(rdough,c);
    boundary = bound;
    display = disp;
    switch(bound){//Figuring out what boundaries the user would like to see
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
    
    int count = (float)r*(float)c*d;//Area of the board times the density gives the number of possible X's available to use
    int random;
    cout<<"count is\t"<<count<<endl;
    while(count>0){//As long as the count is more than zero, this loop will fill the board as pseudorandomly as possible
        random = rand()%10+1;
	cout<<"random var generated"<<endl;
        for(int i =1; i <= c; ++i){
            for(int j=1; j <=r; ++j){
                if(random > 5){//When the random number generated is greater than 5 we fill that cell 
                    oldBoard.setCell(i,j,'X');
                    newBoard.setCell(i,j,'X');
                    count--;//decrement the count value till 0
                    break;
                }
            }
            break;
        }
    }
    if(boundary == 2){//Outside of the switch statement because needed to fill the board before we could wrap it
    	doughnutFill();
    	cout<<"doughnut filled"<<endl;
    }
    copyBoard();
    cout<<"jelly"<<endl;
}

GameofLife::GameofLife(int bound, int disp, string file){//Constructor for if the user specifies a file to read. They still specify
							// the boundary mode and display settings
    boundary = bound;
    display = disp;
    switch(bound){//User specifies the boundary mode
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
    ifstream readfile(filename.c_str());//ifstream to read the file as input
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
    oldBoard.setParam(row,column);//setting the old and new boards up.
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
        newBoard.setCell(i,j,c);
      }
    }
  }
  if(boundary==2){
    doughnutFill();
  }
  copyBoard();
}

void GameofLife::playGame(){
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
		      default: cout<<"The value you input is not 1,2 or 3."<<endl;
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
  char c;
  //take care of all the corners
  c = newBoard.getCell(1,1);
  cout<<"got cell (1,1)"<<endl;
  cout<<row+1<<endl;
  cout<<column+1<<endl;
  newBoard.setCell(row+1,column+1,c);
  cout<<"set cell 6,6"<<endl;
  c= newBoard.getCell(1,column);
  newBoard.setCell(row+1,0,c);
  cout<<"set cell 6,0"<<endl;
  c= newBoard.getCell(row,1);
  newBoard.setCell(0,column+1,c);
  c = newBoard.getCell(row,column);
  newBoard.setCell(0,0,c);
 
  for(int i=1; i<1+row;++i)
 //goest through each row in the interior
  {
    c =  newBoard.getCell(i,column);
    //grabs the right edge
    newBoard.setCell(i,0,c);
    //sets the value to the left buffer
    c =  newBoard.getCell(i,1);
    //grabs the left edge of interior
    newBoard.setCell(i,column+1,c);
    //sets it to right edge of the buffer
  }
    for(int j=1; j<1+column;++j)
    //goes through each column in the interior
  {
    c =  newBoard.getCell(1,j);
    //grabs the value of the top edge interior
    newBoard.setCell(row+1,j,c);
    //sets it to the bottom buffer
    c =  newBoard.getCell(row,j);
    //grabs the bottom edge interior
    newBoard.setCell(0,j,c);
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

string GameofLife::genString(int r){
	string str;
	for(int j = 1; j<=column; ++j)
	{
		str+= oldBoard.getCell(r,j);
	}
	return str;
}
void GameofLife::appendFile(){
	ofstream fileoutput(filename, std::ofstream::app);
	string str;
	for(int i = 1; i<=row; ++i){
		str = genString(i);
		fileoutput<<str<<endl;
	}
	fileoutput.close();
}
void GameofLife::printBoard(){
	string str;
	for(int i = 1; i<=row; ++i){
		str = genString(i);
		cout<<str<<endl;
	}
}
