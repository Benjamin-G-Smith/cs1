// Ben Smith
// p4.cpp
// 2/22/2017

// PURPOSE: Allows two players to play a game of RACK-0 and to play until the
//  game end conditions are met. 

// INPUTS: If the player wants to pick from the discard pile or the draw pile.
//  If the player wants to discard a draw card or put it in their deck. The
//  position the players rack that the player wants to swap a number into. 

// PROCESSING: Shuffling of the deck of cards. The assignment of cards to playe
//  racks. The swapping of deck/discard pile cards with the cards in user racks.
//  Determines which player has won the game. 

// OUTPUTS: The welcome message. Each users rack displaying thier contents. A
//  menue of choices for the user. Also displays a win message with the winner. 

// EXAMPLES:
// *************************************
//*********[WELCOME TO RACK-O]*********
//*************************************
//[PLAYER_1] RACK
//0. 50
//1. 6
//2. 44
//3. 18
//4. 58
//5. 12
//6. 43
//7. 25
//8. 22
//9. 45
//The card in the DISCARD pile is[6]
//1. Draw from [PILE]
//2. Draw from [DISCARD_PILE]
//1
//[DRAW_CARD] = 21
//1. Discard
//2. Put in rack
//1
//The card in the DISCARD pile is[21]
///[PLAYER_2] RACK
//0. 51
//1. 7
//2. 43
//3. 19
//4. 57
//5. 10
//6. 42
//7. 20
//8. 21
//9. 46
///The card in the DISCARD pile is[21]
//1. Draw from [PILE]
//2. Draw from [DISCARD_PILE]
// ///[PLAYER_2] RACK
//0. 6
//1. 7
//2. 15
//3. 19
//4. 23
//5. 24
//6. 30
//7. 35
//8. 40
//9. 56
//[PLAYER_2] has won!
//**************Thanks for playing******************
//
//
//
//
//
//
//

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

void playGame(int player1Rack[],int player2[],int deck[],int size);
// PURPOSE: To run the game of rack-0
// INPUTS: Each player's rack along with the deck and the size of the deck
// OUT: None
void menu();
// PURPOSE: To display the game options to each player
// INPUTS: none
// OUT: The selections for draw from pile/discard pile 
void displayPlayerRack(int playerRack[]);
// PURPOSE: To display the contents of a players rack
// INPUTS: The players rack
// OUT: The numbers stored in the rack along with their rack position 
bool isSorted(int rack[],int size);
// PURPOSE: To determine if the game over condition is meet
// INPUTS: A players rack along with the rack's size
// OUT: If the rack is sorted or not
void drawFromPile(int deck[], int size);
// PURPOSE: To take a card from the deck and resize the deck accordingly
// INPUTS: The deck and the deck size
// OUT: none
void discardAdd(int discardPile[],int discardSize,int cardNumber);
// PURPOSE: To add a card from the discard pile when a user discards a number or swaps 
// INPUTS: The discard pile along with the discard pile size and the card number to be added
// OUT: none

int main(){
  int size = 60;
  int shuffledDeck[60];
  int player1Rack[10];
  int player2Rack[10];
  unsigned seed = time(0);
  srand(seed);
  // set up maybe move it into a function ? 
  
  for(int i = 1; i <= size; i++){ // Make the deck
    shuffledDeck[i] = i;
  }
  random_shuffle(&shuffledDeck[1],&shuffledDeck[60]); // Shuffle the deck
  
  for(int i =0; i < 10; i++){  // player 1 rack
    int pos = rand() % size + 1;
    player1Rack[i] = shuffledDeck[pos];
    for(int i = pos+1; i < size; i++){
      shuffledDeck[i-1] = shuffledDeck[i];
    }
    size--;
  }
  for(int i = 0; i < 10; i++){ // player 2 rack
    int pos = rand() % size + 1;
    player2Rack[i] = shuffledDeck[pos];
    for(int i =pos +1; i <size; i++){
      shuffledDeck[i-1] = shuffledDeck[i];
    }
    size--;
  }
  cout <<"*************************************\n" // Game welcome message
       <<"*********[WELCOME TO RACK-O]*********"
       <<"\n*************************************"<< endl;
  playGame(player1Rack,player2Rack,shuffledDeck,size); 
  cout << "*********[THANKS FOR PLAYING!]*********" << endl;
  return 0;
}
void playGame(int player1Rack[],int player2Rack[],int deck[],int size){
  bool gameOver = false; // game condition
  int discardPile[60] = {0}; // fills an array with 60 zeros
  int disPos = 0; //Discard pile position
  int input,cardChoice,rackSize = 10; //userInput, Selected card, how big the user rack is
  int rackPosition,discardSize=60;//Discard pile size
  
  discardPile[0] = deck[0]; // gets the first card from the deck for the discard pile
  disPos ++;
  drawFromPile(deck,size);// Makes sure that a card has been removed from the deck
  
  while(gameOver != true){ // Some how move all of the actions into a function
    
    cout << "[PLAYER_1] RACK" << endl; // pass the array in by reference
    displayPlayerRack(player1Rack);
    cout << "The card in the DISCARD pile is" <<"["<<discardPile[0]<<"]"<< endl;
    menu(); // calls to display choices for the user
    cin >> input;
    
    if(input == 1){// player wants to draw from pile 
      cout << "[DRAW_CARD] = "<< deck[0] << endl; // Card in the deck
      cout << "1. Discard\n" << "2. Put in rack" << endl;
      cin >> cardChoice;// what the player wants to do with the card
      if(cardChoice == 1){
        discardAdd(discardPile,discardSize,deck[0]);// passes to the discard function 
      }
      else if(cardChoice == 2){// player wants the discard the card
        cout << "Enter the position to place your card: ";
        cin >> rackPosition;
        int temp = player1Rack[rackPosition];//keeps track of the number in the player's slot
        swap(deck[0],player1Rack[rackPosition]);// swaps
        discardAdd(discardPile,discardSize,temp);//adds the user number to the discard function
      }
      drawFromPile(deck,size);// decreases the size of the deck
    }
    else if(input == 2){// player takes from discard pile 
      cout << "[DISCARD_PILE] = "<< discardPile[0] << endl;
      cout << "Enter the position to place your card: ";
      cin >> rackPosition;
      int temp = player1Rack[rackPosition];// Same process as adding the user number to the discard pile
      swap(discardPile[0],player1Rack[rackPosition]);
      //DICARD ADD
      discardAdd(discardPile,discardSize,temp);
    }
    cout << "[PLAYER_1] RACK" << endl;
    displayPlayerRack(player1Rack);// Shows the players rack to the players
    gameOver = isSorted(player1Rack,rackSize);//game over condition check
    if(gameOver == true){
      cout << "[PLAYER_1] has won!" << endl;
      break;
    }
    if(size == 0){// tie condition
      gameOver = true;
      cout << "TIE" << endl;
      break;
    }
    //***************************************************************************
    //***************************************************************************
    // Process below is similar to above (should be a function)

    cout << "[PLAYER_2] RACK" << endl; // pass the array in by reference
    displayPlayerRack(player2Rack);
    cout << "The card in the DISCARD pile is" <<"["<<discardPile[0]<<"]"<< endl;
    menu();
    cin >> input;

    if(input == 1){
      cout << "[DRAW_CARD] = "<< deck[0] << endl;
      cout << "1. Discard\n" << "2. Put in rack" << endl;
      cin >> cardChoice;
      if(cardChoice == 1){
        discardAdd(discardPile,discardSize,deck[0]);
      }
      else if(cardChoice == 2){
        cout << "Enter the position to place your card: ";
        cin >> rackPosition;
        
        int temp = player2Rack[rackPosition];
        swap(deck[0],player2Rack[rackPosition]);
        discardAdd(discardPile,discardSize,temp);
      }
      drawFromPile(deck,size);
    }
    else if(input == 2){
      cout << "[DISCARD_PILE] = "<< discardPile[0] << endl;
      cout << "Enter the position to place your card: ";
      cin >> rackPosition;
      int temp = player2Rack[rackPosition];
      swap(discardPile[0],player2Rack[rackPosition]);
      discardAdd(discardPile, discardSize,temp);
    }
    cout << "[PLAYER_2] RACK" << endl;
    displayPlayerRack(player2Rack);
    gameOver = isSorted(player2Rack,rackSize);
    if(gameOver == true){
      cout << "[PLAYER_2] has wond!" << endl;
      break;
    }
    if(size == 0){
      gameOver = true;
      cout << "TIE" << endl;
      break;
    }
  }
}

void discardAdd(int discardPile[],int discardSize,int cardNumber){
  for(int i = 0; i < discardSize -1; i++){
    discardPile[i+1] = discardPile[i];
  }
  discardPile[0] = cardNumber; 
}
void drawFromPile(int deck[],int size){
  for(int i =1; i < size; i++){
    deck[i-1] = deck[i];
  }
  size--;
}
void menu(){
  cout << "1. Draw from [PILE] " << endl;
  cout << "2. Draw from [DISCARD_PILE] " << endl;
}
void displayPlayerRack(int playerRack[]){
  int cardPosition = 0;
  for(int i = 0; i < 10; i++){
    cout << cardPosition <<". " << playerRack[i] << endl;
    cardPosition ++;
  } 
}
bool isSorted(int rack[],int size){
  bool sorted = true;
  for(int i = 0; i < size-1; i++){
    if(rack[i] > rack[i+1]){
        sorted = false;
      }
  }
  return sorted;
}

      
  
