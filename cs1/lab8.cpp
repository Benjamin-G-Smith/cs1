// Ben Smith
// Lab8.cpp
// 2/10/2017

// PURPOSE: Allows the user to sum input values entered into the program.

// INPUTS: Integer values from the user (5-25).If the user wants to continue
//  entering values.

// PROCESSING: Validating user input. Computing the sum of 1 to X numbers given
//  by the user.

// OUTPUTS: Printing the sum of all numbers from 1 to X numbers given by the
//  user. A welcome message. A goodbye message. Asks to see if the user wants
//  to continue entering values.

// EXAMPLES:

// Would you like to enter a number 'y'/'n'
// y
// Welcome!
// Enter a number (5-25): 5
// 15
// Would you like to enter a number 'y'/'n'
// y
// Welcome!
// Enter a number (5-25): 26
// Error invalid input...
// Enter a number (5-25): 2
// 3
// Would you like to enter a number 'y'/'n'
// n
// Goodbye... 

#include <iostream>

using namespace std;

void welcome(); // Function decleration 
void goodbye();
void input();
int summation(int userInput);


int main(){
  char no = 'n',userIn; 


  cout << "Would you like to enter a number 'y'/'n'"<< endl;
  cin >> userIn;

  while(userIn != no){ // Asks the user if they want to continue entering values
    welcome();
    input();
    cout << "Would you like to enter a number 'y'/'n'" << endl;
    cin >> userIn;
  }
  goodbye();
  return 0;
}
void welcome(){
  cout << "Welcome!"<< endl;
}
int summation(int number){
  
  int sum = 0; // Sum of all numbers from 1 to number given by user
  
  for(int i = 0; i <= number; i++){ // While i is less than the number add i to sum 
    sum += i;
  }
  return sum;
}
void input(){
  
  int userInput,sum;
  
  cout << "Enter a number (5-25): ";
  cin >> userInput;
  
  while(userInput < 5 || userInput > 25){ // Validats user input 
    cout << "Error invalid input..." << endl;
    cout << "Enter a number (5-25): ";
    cin >> userInput;
  }

  sum = summation(userInput);// Passes what the user gives to the summation
  cout << sum << endl; // Prints the sum 
}
void goodbye(){
  cout << "Goodbye..."<< endl;
}
  
