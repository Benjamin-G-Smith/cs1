// Ben Smith
// p2.cpp
// 2/1/2017

// PURPOSE: Allows two players to complete a game of chutes and ladders with
//  a winner being determined.

// INPUTS: Enter command to start the game

// PROCESSING: What the rolls are for each player. If the player lands on a
//  Chute or a ladder, adjust their position accordingly. Checks to see who
//  is the winner.

// OUTPUTS: Which player's turn it is along with their roll and space number.
// Who has won the game.

// EXAMPLES:
// Player 1 rolls: 3
// Player 1 is on space 3
// Player 2 rolls: 6
// Player 2 is on space 6
// Player 1 rolls: 1
// Player 1 is on space 14
// Player 2 rolls: 6
// Player 2 is on space 12
// Player 1 rolls: 6
// Player 1 is on space 20
// Player 2 rolls: 4
// Player 2 is on space 6
// .
// .
// .
// Player 1 rolls: 6
// Player 1 is on space 100
// Player 1 has won!

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_VALUE = 6; // Maximum value for the dice
const int MIN_VALUE =1;  // Minimum value for the dice

int main(){

  unsigned seed = time(0); // Sets the random seed value
  srand(seed);
  
  int p1Roll, // Player one's dice roll
    p2Roll,   // Player two's dice roll
    p1Space = 0, // Which space the player is on
    p2Space = 0;

  while(p1Space < 100 || p2Space < 100){//While both player 1 and 2 have not won
    
    p1Roll = (rand() %(MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE; // Dice roll
    p1Space += p1Roll; // Keeps track of the space the player is on 

    cout << "\nPlayer 1 rolls: " << p1Roll << endl;
    cout << "Player 1 is on space: " << p1Space << endl;

    if(p1Space == 1){//Ladder conditions begin 
      p1Space += 37;
    }
    else if(p1Space == 4){
      p1Space += 10;
    }
    else if(p1Space == 23){
      p1Space += 21;
    }
    else if(p1Space == 36){
      p1Space += 8;
    }
    else if(p1Space == 71){
      p1Space += 19;
    }
    else if(p1Space == 80){//Ladders end
      p1Space += 20;
    }
    else if(p1Space == 16){//Chute conditions begin
      p1Space -= 10;
    }
    else if(p1Space == 48){
      p1Space -= 22;
    }
    else if(p1Space == 56){
      p1Space -= 3;
    }
    else if(p1Space == 64){
      p1Space -= 4;
    }
    else if(p1Space == 95){//Chutes End 
      p1Space -= 20;
    }
    else if(p1Space >= 100){
      cout << "Player 1 has won!"<< endl;
      return 0;
    }

    p2Roll = (rand() %(MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE; // Dice roll
    p2Space += p2Roll; // Tracking player space

    cout << "\nPlayer 2 rolls: " << p2Roll << endl;
    cout << "Player 2 is on space: " << p2Space << endl;

    if(p2Space == 1){//Ladder conditions begin 
      p2Space += 37;
    }
    else if(p2Space == 4){
      p2Space += 10;
    }
    else if(p2Space == 23){
      p2Space += 21;
    }
    else if(p2Space == 36){
      p2Space += 8;
    }
    else if(p2Space == 71){
      p2Space += 19;
    }
    else if(p2Space == 80){//Ladders end
      p2Space += 20;
    }
    else if(p2Space == 16){//Chute conditions begin
      p2Space -= 10;
    }
    else if(p2Space == 48){
      p2Space -= 22;
    }
    else if(p2Space == 56){
      p2Space -= 3;
    }
    else if(p2Space == 64){
      p2Space -= 4;
    }
    else if(p2Space == 95){//Chutes End
      p2Space -= 20;
    }
    else if(p2Space >= 100){
      cout << "Player 2 has won!"<< endl;
      return 0;
    }
  }
  return 0;
}
