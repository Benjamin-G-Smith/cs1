// Ben Smith
// Lab10.cpp
// 2/15/2017

// PURPOSE: Allows the user to enter a file and sort the positive and negative
//  integers within that file.

// INPUTS: A file from the user.

// PROCESSING: Sorting the positive and negative integers into arrays.

// OUTPUTS: The sorted arrays not including unassigned spaces.

// Examples:

// Positive integers are: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// Negative integers are: -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 -11 -12 -13 -14 -15
// PROGRAM ENDS
// Positive integers are: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// Negative integers are: -21 -22 -23 -24 -25 -26 -27 -28 -29 -30
// PROGRAM ENDS

#include <iostream>
#include <fstream>

using namespace std;

const string FILENAME = "/home/fac/lillethd/cpsc1420/lab_input_array_distribution.dat";

int main(){
  int positive[30]; //Positive and negative arrrays
  int negative[30];
  int fileData;
  int positiveSize = 0, negativeSize = 0;//File size trackers

  ifstream inputFile;

  inputFile.open(FILENAME); // Opens file and tests for failure
  if(inputFile.fail()){
    cout << "Error opening file" << endl;
  }
  while(inputFile >> fileData){ //Reads the file 
    if(fileData > 0){
      positive[positiveSize] = fileData; // Adds apprpreate data
      positiveSize++; // Tracks the size
    }
    else if (fileData < 0){
      negative[negativeSize] = fileData;
      negativeSize++;
    }
  }
  inputFile.close(); // Makes sure file is closed 
  cout << "Positive integers: ";
  for(int count = 0; count < positiveSize; count++){
    cout << positive[count] << " "; //For every element in the Positive print
  }                                 // each element
  cout << endl;

  cout << "Negative integers: ";
  for(int count = 0; count < negativeSize; count++){
    cout << negative[count] << " ";
  }
  cout << endl; 
  return 0;
}
      

  
