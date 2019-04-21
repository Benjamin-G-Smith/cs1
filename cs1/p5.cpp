// Ben Smith
// p5.cpp
// 3/13/2017

// PURPOSE: Allows two to six people to play the game of SU monopoly.  

// INPUTS: The contents of the board data file. Containing each spaces space
//  data.The number of players who want to play the game. The names of the
//  players who are playing the game. On a player's turn they can choose to buy
//  a tile or not. If the players want to play the game again. 

// PROCESSING: The contents of the file are read into each element in the
//  struct array. The creation of a player struct array with the number of people
//  playing the game. On each player's turn the game will roll the dice on their
//  turn determining where they will move to on the board. If the player chooses
//  to buy a tile the cost is deducted from their balance. Also deducting fees
//  if players land on particular locations on the board. 

// OUTPUTS: The contents of the board data file upon game setup. Prompts for the
//  users upon their turn. The balance of a player of that information is needed.
//  When the player lands on a board space the game prints out the information
//  for that particular board space. Also the winner with their player balance.


// EXAMPLES:
//Do you want to play? 'y'/'n'?
//y
//Enter the number of players [2-6]
//2
//*********BOARD_DATA*********
//Go
//-1
//0
//0
//Connolly Center
//0
//300
//30
//Administration Building
//0
//150
//15
//Fees
//-1
//0
//400
//Engineering Building
//0
//300
//30
//Arrupe Jesuit Residence
//0
//350
//35
//James Tower
//0
//500
//50
//Chance
//-1
//0
//0
//Campion Residence Hall
//0
//400
//40
//Student Center
//0
//300
//30
//Bannan Engineering Building
//0
//300
//30
//Casey Building
//0
//400
//40
//Xavier Residence Hall
//0
//300
//30
//Chance
//-1
//0
//0
//Fine Arts Building
//0
//200
//20
//Broadway Building
//0
//100
//10
//Dean Jacob Diaz Office
//-1
//0
//0
//Teilhard de Chardin Hall
//0
//300
//10
//Hunthausen Hall
//0
//200
//20
//Chapel of St. Ignatius
//-1
//0
//0
//Garrand Building
//0
//150
//15
//Lynn Building
//0
//150
//15
//Pigott Building
//0
//200
//20
//Lemieux Library and Learning Commons
//0
//500
//50
//New Science Building
//0
//1500
//150
//Income Tax
//-1
//0
//200
//Loyola Hall
//0
//250
//25
//Rianna Building
//0
//300
//30
//Bellarmine Residence Hall
//0
//200
//20
//Sullivan Hall
//0
//400
//40
//Columbia Building
//0
//200
//10
//Archbishop Murphy Apartments
//0
//400
//20
//Casey Building
//0
//300
//10
//Bannan Science Building
//0
//400
//30
//Kolvenbach Homes
//0
//1200
//100
//****************************
//Board setup complete...
//PLAYER_1 Enter your name:Bob
//PLAYER_2 Enter your name:Billy
//Player_1 is Bob
//Player_2 is Billy
//
//***********************************************
//************WELCOME_TO_SU_MONOPOLY_!***********
//***********************************************
//[Bob] has rolled 8
//Current space: [8]
//Campion Residence Hall
//Owner: 0
//Price: 400
//Rent:  40
//Current Balance: $1500
//[Do you want to buy Campion Residence Hall'y'/'n'?]
//y
//Current Balance: $1000
//-------------------------------------------------
//[Billy] has rolled 7
//Current space: [7]
//Chance
//Owner: -1
//Price: 0
//Rent:  0
//You have gained $50!
//Balance: 1550
//-------------------------------------------------
//[Bob] has rolled 4
//Current space: [10]
//Bannan Engineering Building
//Owner: 0
//Price: 300
//Rent:  30
//Current Balance: $1000
//[Do you want to buy Bannan Engineering Building'y'/'n'?]
//y
//Current Balance: $700
//-------------------------------------------------
//[PASSED GO GAIN $200]
//[Billy] has rolled 5
//Current space: [1]
//Connolly Center
//Owner: 1
//Price: 300
//Rent:  30
//Billy pays $30
//Bob recieves $30
//-------------------------------------------------
//[Bob] has rolled 4
//Current space: [10]
//Bannan Engineering Building
//Owner: 0
//Price: 300
//Rent:  30
//Current Balance: $200
//[Do you want to buy Bannan Engineering Building'y'/'n'?]
//y
//Insufficient funds cannot buy
//------------------------------------------------- 
//[Billy] has rolled 6
//Current space: [8]
//Campion Residence Hall
//Owner: 0
//Price: 400
//Rent:  40
//Current Balance: $400
//[Do you want to buy Campion Residence Hall'y'/'n'?]
//y
//Current Balance: $0
//-------------------------------------------------
//Billy
//Balance :0
//Winner is Bob
//Balance: 150
//Do you want to play again 'y'/'n'?
//n
//Thank you for playing goodbye...



#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;
// Information for each board space
struct Space{
  string name;
  int owner;
  int price;
  int rent;
};
// Information for each player 
struct Player{
  int balance = 1500;
  string name;
  int space = 0;
  int playerNumber;
};

Space boardSpaces[45];
void playerTurn(Space boardSpaces[], Player *players, int playerNumber);
// playerTurn Takes in the board data,the player data, and the current player number.
// This function preforms all of the actions that cold happen on a player's turn.  
void getNames(Player *players);
// getNames gets the names of the players playing the game. Taking in the player data
// array to assign name values.
void assignSpaces();
// assignSpaces reads the data in the board data file to assign the file data to the
// board data struct.
int getNumberOfPlayers();
// getNumberOfPlayers asks the users how many players are playing the game. With this
// information a player array is created to the size of the number entered.
int highestBalance(Player *players);
// higestBalance takes in the players array data to find the player with the most money
// when the game is over in order to find a winner. 
int rollDice();
// Preforms the actions of the dice roll for each player on their turn. Rolling two
// dice and then adding the result to be the roll. 
bool isPlayerOutOfMoney(int playerNumber, Player *players);
// isPlayerOutOfMoney check to see if after a player's turn has elapsed does their money
// zero. It takes in the current player number along with the player data array. if the
// player is out of money then the bool returns true and false otherwise.

const string BOARD_DATA = "/home/fac/lillethd/cpsc1420/monopoly_board.dat";
const int MAX_DICE_VALUE = 6;
const int MIN_DICE_VALUE = 1;
int numberOfSpaces; // can change but is a set number every game
int NUM_PLAYERS;

int main(){
  unsigned seed = time(0);// for the dice roll function 
  srand(seed);
  string userInput;
  
  cout << "Do you want to play? 'y'/'n'?" << endl;
  cin >> userInput;
  
  while(userInput == "y"){
    NUM_PLAYERS = getNumberOfPlayers(); 
    Player *players = new Player[NUM_PLAYERS]; //Creates a dynamic array for the number of players in the game
    bool gameOver = false;
  
    assignSpaces(); 
    cout << "*********BOARD_DATA*********" << endl;
    for(int i = 0; i < numberOfSpaces; i++){ //Prints the board data 
      cout << boardSpaces[i].name << endl;
      cout << boardSpaces[i].owner << endl;
      cout << boardSpaces[i].price << endl;
      cout << boardSpaces[i].rent << endl;
    }
    cout << "****************************" << endl;
    cout << "Board setup complete..." << endl;
  
    getNames(players);
  
    for(int i = 0; i < NUM_PLAYERS; i++){
      cout <<"Player_"<< players[i].playerNumber << " is "<< players[i].name << endl;
    }
    cout << "\n***********************************************" << endl;
    cout << "************WELCOME_TO_SU_MONOPOLY_!***********" << endl;
    cout << "***********************************************" << endl;
    
    int player = 0;
    while(!gameOver){ // Loop to take each player's turn 
      if(player > (NUM_PLAYERS-1)){
        player = 0;
      }
      playerTurn(boardSpaces,players,player);
      cout << "-------------------------------------------------" << endl;
      player++;
      gameOver = isPlayerOutOfMoney(player,players);
    }
    
    int winner = highestBalance(players);
    cout << "Winner is " << players[winner].name << endl; // Winner is determined
    cout << "Balance: " << players[winner].balance << endl;
    cout << "Do you want to play again 'y'/'n'?" << endl; // asks to play again
    cin >> userInput;
  }
  cout << "Thanks for playing goodbye..."<< endl;
}
void playerTurn(Space boardSpaces[], Player *players, int playerNumber){
  int space = rollDice(); // gets teh dice roll for the player
  players[playerNumber].space += space;
  
  if(players[playerNumber].space >= numberOfSpaces){   // Check to see if the player has passed go
    if(players[playerNumber].space == numberOfSpaces){
      cout << "[PASSED GO GAIN $200]" << endl;
      players[playerNumber].balance += 200;
      players[playerNumber].space = 0;
    }
    else{
      cout << "[PASSED GO GAIN $200]" << endl;
      players[playerNumber].balance += 200;
      players[playerNumber].space -= (numberOfSpaces+1);
    }
  }
  cout <<"["<<players[playerNumber].name <<"]"<<" has rolled " << space << endl;
  
  int boardSpace = players[playerNumber].space; // keeps track of the space on the board
  cout <<"Current space: "<< "[" << players[playerNumber].space << "]" << endl; // Displays the space information
  cout << boardSpaces[boardSpace].name << endl;
  cout <<"Owner: "<< boardSpaces[boardSpace].owner << endl;
  cout <<"Price: "<< boardSpaces[boardSpace].price << endl;
  cout <<"Rent:  "<< boardSpaces[boardSpace].rent << endl;
  
  if(boardSpaces[boardSpace].name == "Fees"){ // Special space conditions
    cout << "$400 has been deducted" << endl;
    players[playerNumber].balance -= 400;
    cout <<"Balance: $"<< players[playerNumber].balance << endl;
  }
  else if(boardSpaces[boardSpace].name == "Income Tax"){
    cout << "$200 has been deducted" << endl;
    players[playerNumber].balance -= 200;
    cout <<"Balance: $"<< players[playerNumber].balance << endl;
  }
  else if(boardSpaces[boardSpace].name == "Chance"){
    int chanceRoll = (rand() %(MAX_DICE_VALUE - MIN_DICE_VALUE + 1)) + MIN_DICE_VALUE;
    if(chanceRoll == 1|| chanceRoll == 2 || chanceRoll == 3){
      cout << "You have gained $50! " << endl;
      players[playerNumber].balance += 50;
      cout << "Balance: "<< players[playerNumber].balance << endl;
    }
    else{
      players[playerNumber].space = 19;
      cout << "Have a nice rest" << endl;
    }
  }   
  else if(boardSpaces[boardSpace].name == "Chapel of St. Ignatius"){
    cout << "You are at the Chapel of St. Ignatius" << endl;
  }
  // If the space is not a special space
  // Prompts to buy or not
  // Or to pay rent 
  else if(boardSpaces[boardSpace].owner > 0 && boardSpaces[boardSpace].owner != players[playerNumber].playerNumber){
    
    cout << players[playerNumber].name << " pays $"<< boardSpaces[boardSpace].rent << endl;
    players[playerNumber].balance -= boardSpaces[boardSpace].rent;
    int owner = boardSpaces[boardSpace].owner-1;
    players[owner].balance += boardSpaces[boardSpace].rent;
    
    cout << players[owner].name << " recieves $"<< boardSpaces[boardSpace].rent << endl;
  }
  else if(boardSpaces[boardSpace].owner < 0){
    cout << "Nothing to do. Have some Tea." << endl;
  }
  else if(boardSpaces[boardSpace].owner == 0){
    char userInput;
    cout << "Current Balance: $"<< players[playerNumber].balance << endl;
    cout << "[Do you want to buy "<<boardSpaces[boardSpace].name
         <<"'y'/'n'?]"<< endl;
    cin >> userInput;
    if(userInput == 'y'){
      if(players[playerNumber].balance - boardSpaces[boardSpace].price < 0){
        cout << "Cannot purchase insufficient funds" << endl;
      }
      else{
        boardSpaces[boardSpace].owner = players[playerNumber].playerNumber;
        players[playerNumber].balance -= boardSpaces[boardSpace].price;
        cout << "Current Balance: $" << players[playerNumber].balance << endl;
      }
    }
    else if(userInput == 'n'){
      cout << "Player has chosen not to buy" << endl;
    }
  }
  else
    cout << "You have nothing to do. Drink some Tea." << endl;
  // If none of the conditions are meet then they do nothing
}
int highestBalance(Player *players){
  int playerWithMax = 0; // Sorts to find the highest balance
  for(int i = 0; i < NUM_PLAYERS; i++){
    if(players[i].balance > players[playerWithMax].balance){
      playerWithMax = i;
    }
  }
  return playerWithMax;// Returns that player's index
}
bool isPlayerOutOfMoney(int playerNumber,Player *players){
  for(int i = 0; i < NUM_PLAYERS; i ++){
    if(players[i].balance <= 0){
      cout << players[i].name << endl; // Determines if a player has run out of money
      cout << "Balance :" << players[i].balance << endl;
      return true;
    }
  }
  return false;  
}
int rollDice(){ // Rolls the dice
  int roll;  
  int  diceOne = (rand() %(MAX_DICE_VALUE - MIN_DICE_VALUE + 1)) + MIN_DICE_VALUE; 
  int diceTwo = (rand() %(MAX_DICE_VALUE - MIN_DICE_VALUE + 1)) + MIN_DICE_VALUE;
  roll = diceOne + diceTwo;
  return roll;  
}
void getNames(Player *players){
  int num = 1;
  for(int i = 0; i < NUM_PLAYERS; i++){
    cout << "PLAYER_"<< num <<" Enter your name:";
    cin >> players[i].name;
    players[i].playerNumber = num; // assigns the player number
    num ++;
  }
}
int getNumberOfPlayers(){ // gets the number of players
  int numPlayers;
  cout << "Enter the number of players [2-6]" << endl;
  cin >> numPlayers;
  while(numPlayers < 2 || numPlayers > 6){
    cout << "Error invalid player count..." << endl;
    cout << "Enter the number of players [2-6]" << endl;
    cin >> numPlayers;
  }
  return numPlayers;
}
void assignSpaces(){
  ifstream file; // Assigns the spaces with data from the file 
  string temp;
  numberOfSpaces = 0;
  file.open(BOARD_DATA);
  if(file.fail()){
    cout << "File ERROR" << endl;
  }    
  for(int i = 0; getline(file,boardSpaces[i].name); i++){
    file >> boardSpaces[i].owner;
    file >> boardSpaces[i].price;
    file >> boardSpaces[i].rent;
    file.ignore();
    numberOfSpaces ++;    
  }
  file.close();
}

