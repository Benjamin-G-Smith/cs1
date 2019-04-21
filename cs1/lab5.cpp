// Ben Smith
// lab5.cpp
// 1/25/2017

// PURPOSE: Allows the user to find the first power of two for a given integer.

// INPUTS: A positive integer that is greater than 1.

// PROCESSING: The program checks to see if the integer entered it a power of
//  two. If the input is not a power of two, the program finds the next greatest
//  power of two.

// OUTPUTS: The next value that is a power of two or the value entered if the
//  user enters a power of two.

// EXAMPLES:
// Please enter a number greater than 1:
// 2
// The first power is: 2
// Please enter a number greater than 1:
// 3
// The first power is: 4
// Please enter a number greater than 1:
// -1
// Error Invalid number
// Please enter a number greater than 1:

#include <iostream>
#include <cmath>

using namespace std;

const int MIN_VALUE = 2; // constant the number cannot be smaller than

int main(){
  int userInput, powerOut; 
  powerOut = 2; // Base power of two
 
  cout << "\nPlease enter a number greater than 1: ";
  cin >> userInput;

  while(userInput < MIN_VALUE ){ // Checks to see if the input is greater than 2
    cout << "Error Invalid number" << endl;
    cout << "Please enter a number greater than 1: ";
    cin >> userInput; 
  }
  while(powerOut < userInput){ // Checks to see if the power is 2 
    powerOut = powerOut * 2;   // if the userinput is greater squares the powerOut     
  }                            // until the next power is found
  cout << "The first power is: " << powerOut << endl; // prints the next power

  return 0; 
}
