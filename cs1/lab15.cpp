// Ben Smith, Sasank kanuri
// lab15.cpp
// 3/13/2017

// PURPOSE: A program that checks to see if a string is a panandrome. Entered
//  by the user.

// INPUTS: The phrase from the user to check to see if it is a palandrome.

// PROCESSING: The program will go through th user string and determine if
//  the string is a palandrome.

// OUTPUTS: Weather the user input is a palandrome or not.

// EXAMPLES:
// Enter the phrase you want to check:
// A Man, A Plan, A Canal-Panama!
// Your phrase is a palandrome.
// PROGRAM EXITS
// Enter the phrase you want to check:
// Sasank
// Your phrase is not a palandrome.

#include <iostream>
#include <ctype.h>
#include <string.h>


using namespace std;

// This function will take the user's input and remove all of the whitespaces
// and punctuation. It will return a string with the user's input that has no spaces or punctuation.
// IN: This function will take in the user's input which is stored in an array.
string removePunctuation(char letters[]);

// This function will determine if the phrase entered by the user is a palindrome or not
// and will return a boolean value.
// IN: This function will take in the user's input with no spaces or punctuation.
bool isPalindrome(string cleanString);

int main(){
  char userLetters[256];
  string finalOutput;
  cout <<"Enter a string" <<endl;
  cin.getline(userLetters,256);

  finalOutput = removePunctuation(userLetters);
  isPalindrome(finalOutput);  
  return 0;
}
bool isPalindrome(string cleanString){
  bool palindrome = false;
  char cleanLetters[256]; // This array will contain the user's input as a char array. 
  char backwardsLetters[256]; // This array will store the user's input backwarads.
  int size = 0;

  strncpy(cleanLetters, cleanString.c_str(), 256);

  // This loop will keep track of the total size of the char array.
  for(int i = 0; cleanLetters[i] != '\0'; i++){ 
    size++;
  }
  int temp = cleanString.length(); // This variable stores the length of user's input without punctuation.
  int counter = 0;

  // This loop reverses the contents of the first array and puts them in the backwardsLetters array.
  for( int i = temp - 1; i >= 0; i --){
    backwardsLetters[counter] = cleanLetters[i];
    counter++;
  }

  // This loop checks to see if the user's input backwards is the same as forward.
  if(strncmp(cleanLetters,backwardsLetters,size)==0){
    palindrome = true;
    cout << "Your phrase is a palindrome" << endl;
    for(int i = 0; i < size; i++){
      cout << backwardsLetters[i];
    }
  }
  else
    cout << "Your phrase is not a palindrome" << endl;
  
  return palindrome;
}
string removePunctuation(char letters[]){
  string cleanString = "";

  // This loop removes punctuation and whitespaces from the user's input.
  for(int i = 0; letters[i] != '\0'; i++){
    if(isalpha(letters[i])){
      cleanString += tolower(letters[i]);
    }
  }
  return cleanString;
  
}       
          


            
  

  
          
