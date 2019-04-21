// Ben Smith, Casey Willard, Sasank Kanuri
// lab6.cpp
// 1/30/2017

// PURPOSE: A progeam that allows the user to input a value and then create
//  a multiple number designs with that input.

// INPUT: user input (2-9).

// PROCESSING: Generates multiple number sequences/patterns. Also validates
//  the user input.

// OUTPUT: Prints four number patterns generated with the input value from
// the user.

// EXAMPLES:
// Enter a value (2-9):
// 5
// 5 copies of 5 on one line:
// 55555
// 5 lines with a single 1 on each line:
// 1
// 1
// 1
// 1
// 1
//3. Multiplication table to 5:
// 1  2  3  4  5
// 2  4  6  8 10
// 3  6  9 12 15
// 4  8 12 16 20
// 5 10 15 20 25
//4. 5 lines with with 1 ones on the first line, 2 twos on the second,etc: 
//  1
//  2 2
//  3 3 3
//  4 4 4 4
//  5 5 5 5 5
// PROGRAM EXITS
//
// Enter a value (2-9):
// 1
// Invalid Input
// Enter a value (2-9):

#include <iostream>
#include <iomanip>
using namespace std;

// These two constants adefine the range of values the user can choose from
const int MAX_VALUE = 9;
const int MIN_VALUE = 2;

int main(){

  int userInput;
  
  cout<< "Enter a value (2-9): ";
  cin >> userInput;

  //Checks for invalid input
  while (userInput < MIN_VALUE || userInput > MAX_VALUE){
    cout << "Error Invalid Input\n";
    cout << "Enter a value (2-9): ";
    cin >> userInput;
  }
  
  cout << userInput << " copies of " << userInput << " on one line:" <<endl;
  for(int i = 0; i < userInput; i++){
    cout<<" "<<userInput;
  }
  cout<<""<<endl;
  cout <<" "<< userInput <<" lines with a single 1 on each line:" <<endl;
  for(int i = 0; i < userInput; i++){
    int num = 1;
    cout <<" "<< num <<endl;
  }
  cout <<"Multiplication table to: " <<userInput <<endl;
  for(int col = 1; col <= userInput; col++){
    for(int row = 1; row <= userInput; row++){  //Multiplies row by column until each row is filled
        cout <<setw(2)  <<(col * row)<<" ";      
      }
    cout <<endl;
  }
  
  cout <<userInput<< " lines with 1 ones on the first line, 2 twos on the second, etc. to "
       <<userInput<< "s:"<<endl;
  
  for(int col = 1; col <= userInput; col++){
    for(int row = 1; row <= col; row++){
      cout <<" "<<setw(1)<<col<< " ";
    }
    cout << endl;
  }
  return 0;
}
