#include "GameofLife.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

int main(int argc, char** argv){


cout << "Welcome to the Game of Life!" << endl;
cout << "Would you like to start by providing a (f)ile to run the simulation or would you like a (r)andom assignment?"<< endl;
cout << "Please enter 'file' or 'random' to start the setup." << endl;
string answer;
cin >> answer;
while(answer != "file"&& answer != "f" && answer != "F" && answer != "random"&& answer != "r"&& answer != "R"){
  cout<< "Invalid argument! Please try again!"<<endl;
  cout << "Would you like to start by providing a (f)ile to run the simulation or would you like a (r)andom assignment?"<< endl;
  cout << "Please enter 'file' or 'random' to start the setup." << endl;
  cin >> answer;
}
if(answer == "file"||answer == "f"||answer == "F")
{
  
  cout << "To determine the type of boundary, please enter: (1) for Classic, (2) for Doughnut or (3) for Mirror."<< endl;
  int boundary;
  cin >> boundary;
  while(boundary != 1 || boundary != 2 || boundary != 3){
    cout << "Invalid argument \n To determine the type of boundary, please enter: (1) for Classic, (2) for Doughnut or (3) for Mirror."<< endl;  
    cin >> boundary;
  }
  
  cout<< "To determine the type of display, please enter: (1) for Pause, (2) for Enter or (3) for File." << endl;
  int mode;
  cin >> mode;
  while(mode != 1 || mode != 2 || mode != 3){
    cout << "Invalid argument \n To determine the type of display, please enter: (1) for Pause, (2) for Enter or (3) for File." << endl;
    cin >> mode;
  }
  
  string filename;
  cout << "Please enter the name of the file: " << endl;
  cin >> filename;
  GameofLife gL(boundary,mode, filename);
  gL.playGame()
}
else if(answer == "random"||answer == "r"||answer == "R")
{
  cout << "Please enter the number of rows you'd like in your grid: "<<endl;
  int numRow;
  cin >> numRow;
  while(numRow>100|| numRow == 0){
    cout<<"Tha'ts too big! Please enter a number between 1 and 100"<<endl;
    cin>> numRow;
  }
  
  cout << "Please enter the number of columns you'd like in your grid: "<<endl;
  int numCol;
  cin >> numCol;  
  while(numCol >100 || numCol == 0){
    cout<<"Tha'ts too big! Please enter a number between 1 and 100"<<endl;
    cin>> numCol;
  }
  
  cout << "Please enter a number and number between 0 and 1 to represent the density of filled spaces in your grid: "<< endl;
  float density;
  cin >> density;
  while(density<=0||density>=1)
  {
    cout<<" INVALID ARGUMENT!!! Please enter a number between the values 0 and 1."<<endl;
    cin >> density;
  }
  
  cout << "To determine the type of boundary, please enter: (1) for Classic, (2) for Doughnut or (3) for Mirror."<< endl;
  int boundary;
  cin >> boundary;
  while(boundary != 1 || boundary != 2 || boundary != 3){
    cout << "Invalid argument \n To determine the type of boundary, please enter: (1) for Classic, (2) for Doughnut or (3) for Mirror."<< endl;  
    cin >> boundary;
  }
  
  cout<< "To determine the type of display, please enter: (1) for Pause, (2) for Enter or (3) for File." << endl;
  int mode;
  cin >> mode;
  while(mode != 1 || mode != 2 || mode != 3){
    cout << "Invalid argument \n To determine the type of display, please enter: (1) for Pause, (2) for Enter or (3) for File." << endl;
    cin >> mode;
  }
  
    GameofLife gL(boundary,mode,numRow,numCol,density);
    gL.playGame();
} 
else{
 throw invalid_argument("Please enter file or random"); 
  }
}
