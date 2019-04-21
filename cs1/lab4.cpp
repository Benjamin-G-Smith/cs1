// Ben Smith, Sasank Kanuri, Casey Willard
// lab4.cpp
// 1/23/2017

// PURPOSE: To create a program that allows the player and the computer to
//  to play a game of dice guessing. Guessing until they run out of points.

// INPUT: Integer between 1-6.

// PROCESSING: The random function to determine what the hidden values are.
//  Point total for the user and the computer.

// OUTPUT: If the number is guessed correctly. Points gained for the user
//  and points gained or lost by the computer.

// EXAMPLES:
// Enter a number between 1-6:
// 7
// ERROR: number invalid you lose
// Enter a number between 1-6:
// 4
// Correct 100pts
// The roll is an odd number
// The computer loses 50 points
// The user is the winner
//
// The computer gets a 100 points
// The computer wins

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_VALUE = 1; // This is the minimum value for the two dice
const int MAX_VALUE = 6; // This is the maximum value for the two dice
int main()
{  
  unsigned seed = time(0);
  srand(seed);
  
  
  int diceOne, diceTwo, userGuess, computerGuess, userPoints, computerPoints,
    greaterInt, smallerInt ;
  diceOne = (rand() %(MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE; // Dice randomization
  diceTwo = (rand() %(MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE; // Dice randomization

    userPoints = 100; // Initial value of points for the user 
    computerPoints = 100; // Initial value of points for the computer

    // The values of the dice are determined which will be compared to the user's input
  if(diceOne>diceTwo){
    greaterInt = diceOne;
    smallerInt = diceTwo;
    }
  else{
    smallerInt = diceOne;
    greaterInt = diceTwo;
    }
	
  cout<<"You have 100 points" <<endl;
  cout<<"Enter a integer between 1 and 6"<< endl;
  cin>>userGuess;
  cout <<"The numbers are " <<greaterInt <<" " <<smallerInt <<endl;
  if(userGuess < MIN_VALUE || userGuess > MAX_VALUE)
    {
     cout <<"ERROR: number invalid you lose" << endl;
     return 0; // This ends the game
    }
  else if(smallerInt < userGuess && userGuess < greaterInt){

   cout<<"Your guess is between the two numbers. "<<endl;
   userPoints += 100;
 }
  // This calculates the computer's guess and the points assigned to the computer
  else{
    computerGuess = (rand() %(MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    
    if(computerGuess == 2 || computerGuess == 4){ // Computer's guess is 2 or 4
      computerPoints += 100; // Adds 100 points
        }
    else if (computerGuess == 6){ // Computer's guess is 6
      computerPoints += 200; // Adds 200 points
        }
    else if (computerGuess % 2 == 1){ // Computer guess is odd
      computerPoints -= 50; // Subtracts 50 points
    }
    else
      cout << "Computer guessed wrong"<< endl;
  }

  if(userPoints < computerPoints){
        cout<<"The computer wins with: " << computerPoints << endl;
  }
  else{
    cout << "You have: " << userPoints << "pts"<< endl;
    cout << "The Computer has: " << computerPoints << endl;
    cout << "You win" << endl;
  }
}





