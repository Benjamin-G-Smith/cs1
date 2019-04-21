// Ben Smith
// Lab11.cpp
// 2/22/2017

// PURPOSE: Allows the user to search a string file for a particular word and
//  printing the location of the string in the array.

// INPUTS: String the user wants to search for.

// PROCESSING: The program searches the file for the location of the string.
//  Storing the index of the string. Stores the elements in the file in an
//  array to be searched.

// OUTPUTS: The index of the array in which the string is stored. If it is not
//  found in the file print the error to the user.

// EXAMPLES:
// Enter a word to search for
// day
// Index of day in the file is 5
// PROGRAM EXITS
// Enter a word to search for
// world
// world does not exitst in the file
// PROGRAM EXITS

#include <iostream>
#include <fstream>

using namespace std;

const string FILE_NAME = "/home/fac/lillethd/cpsc1420/lab_input_find_it.dat";

int indexSearch(string word,string fileString[],int size); 
int main(){
  ifstream userFile;
  string userWord,word; //user input and a temp word used to read the file
  string wordArray[75];
  int indexOfArray,i=0,size =0;

  userFile.open(FILE_NAME);
  
  if(userFile.fail()){ // Ensures that the file is not broken
    cout << "Error could not open file.."<< endl;
    return 0;
  }
  while(userFile >> word){ 
    wordArray[i] = word; // Adds each of the words within the file to an array to be searched
    i++; // Element position in the wordArray
    size ++; // used to keep track of exactly how many word are in the file
  }
  cout << "Enter a word to search for" << endl;
  cin >> userWord; //Getting the user word that is needed to search for
  indexOfArray = indexSearch(userWord,wordArray,size);
  if(indexOfArray >= 0 && indexOfArray < 75){ // Makes sure that there can be no index larger than 75
    cout << "Index of "<< userWord <<" is "<< indexOfArray<< endl;
  }
  else
    cout << userWord << " does not exist in the file" << endl;
  userFile.close();
  return 0;
}

int indexSearch(string word,string fileString[],int size){
  int position,index =0;
  bool found = false;
  while(index < size && !found){ //While looking through the wordarray
    if(fileString[index] == word){ // the word matches the userword
      position = index;//keeps track of the index of that word
      found = true;
    }
    index++;
  }
  return position; // return that position in the wordarray 
}

