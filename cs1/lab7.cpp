// Ben Smith
// lab7.cpp
// 2/1/2017

// PURPOSE: Allows the user to input a filename and then computes the average
//  for the numbers within the file.

// INPUTS: Filenames from the user. Contents of the file. A file with a series
//  of numbers on each line.

// PROCESSING: The program reads the file contents. Computes the average of
//  the numbers in the file.

// OUTPUTS: If the file opened successfuly or not. The average of the numbers
//  in the file.

// EXAMPLES:
// Enter a filename:
// lab7input1.dat
// File opened successfuly...
// Average: 56
// PROGRAM ENDS
// Enter a filename:
// lab7inpt1.dat
// Cannot openfile...
// Enter a filename:



#include <iostream>
#include <fstream>

using namespace std; 

int main(){

  string userInput; //Filename from the user
  int totalAmountOfNumbers,num,average, sum = 0;
  // Keeps track of the total amount of items
  // placeholder variable to read the file
  // average of the numbers
  // sum of the numbers in the file

  ifstream inputFile; 

  cout << "Enter a filename: " << endl; // Takes userInput
  cin >> userInput;

  inputFile.open(userInput);

  while(inputFile.fail()){ // Checks to see if the filename is valid
    cout << "Cannot open file..." << endl;
    cout << "Enter a filename... " << endl;
    cin >> userInput;
    inputFile.open(userInput);
  }
  
  cout << "Successfuly opened file..." << endl;
  while(inputFile >> num){ // Number from each line of the file added to the sum
    sum += num;
    totalAmountOfNumbers ++; //Total number of items
  }
  
  average = sum / totalAmountOfNumbers; //calculates the average

  cout << "Average: " << average << endl; 

  inputFile.close();  
  return 0;
}


