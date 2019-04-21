// Ben Smith
// 2/12/2017
// P3.cpp

// PURPOSE: Allows the user to calculate the average review score with a
//  keyword search of a file.

// INPUTS: If the user wishes to continue entering words. Inputs from the
//  the user.

// PROCESSING: Average calculation of scores for each keyword search.
//  Search for a keyword within a file. Search for the score of a movie review.
//  Adding a score to a sum.

// OUTPUTS: If the user would like to do a search of a file. Ask the user for
//  a file. Ask the user for a input word. The average score for that word.

// EXAMPLES:
// Enter a file to search:
// /home/fac/lillethd/cpsc1420/reviewData.txt
// Opening file...
//
// Select from the following:
// 1. Get the score of a word
// 2. Get the average score of a review
// 3. Exit the program
// 1
// Enter a keyword: fantastic
// The average score for [fantastic] is 7.0 positive.
// 1. Get the score of a word
// 2. Get the average score of a review
// 3. Exit the program
// 1
// Enter a keyword: okay
// The average score for [okay] is 1.988 neutral.
// 1. Get the score of a word
// 2. Get the average score of a review
// 3. Exit the program
// 2
// The average score for [userFile] is 1 neutral.
// 1. Get the score of a word
// 2. Get the average score of a review
// 3. Exit the program
// 3
// Closing file...
// Goodbye...


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

double wordScore(ifstream &file,string &word);
void averageReviewScore(ifstream &file);
void wordRating(double average,string word);


int main(){
  int menuChoice;
  string userInput,keyword; 
  ifstream userFile;

  cout << "Enter a file to search" << endl;//Gets the file from the user
  cin >> userInput;
  userFile.open(userInput);

  while(userFile.fail()){ //File open check 
    cout << "Error could not open file..."<< endl;
    cout << "Enter a file to search"<< endl;
    cin >> userInput;
    userFile.open(userInput);
  }
  cout << "Opening file..."<< endl;
  cout << "\nSelect from the following:"<< endl;
  cout << "1. Get the score of a word"<< endl;
  cout << "2. Get the average score of a review"<< endl;
  cout << "3. Exit the program"<< endl;
  cin >> menuChoice;
  while(menuChoice != 3){ //Loop for the user to input menu choices 
    if(menuChoice == 1){
      double average = 0;
      cout << "Enter a word to search for: ";
      cin >> keyword;
      average = wordScore(userFile,keyword);//Gets the wordScore of the user word
      wordRating(average,keyword);//reviews the score of the word
      userFile.close();
    }
    else if(menuChoice == 2){
      averageReviewScore(userFile); //gets the review score of a file
      userFile.close();
    }
    userFile.open(userInput);    //file is still being used
    cout << "Select from the following:"<< endl;
    cout << "1. Get the score of a word"<< endl;
    cout << "2. Get the average score of a review"<< endl;
    cout << "3. Exit the program"<< endl;
    cin >> menuChoice;
  }
  userFile.close(); // makes sure to close the file 
  cout << "Closing file..."<< endl;
  cout << "Goodbye..."<< endl;   
  return 0;
}
void averageReviewScore(ifstream &file){ // takes in the file entered by the user
  string line,word,temp;
  string userFile = "userFile";
  double average;
  int count =0,score =0;
  while(file >> line){//looking through the file 
    word = line; //assigns each word of the line to a word variable
    while(file >> temp){ 
      if(word == temp){ //if the word is found agin in the file
        count ++; //counts the word
        score += count; // ads the count to the total score
      }
    }
    count ++; 
    score += count;
  }
  average = score/count;
  wordRating(average,userFile);
}

double wordScore(ifstream &file,string &word){
  int count=0;
  double score=0,num,average;
  string line,lineWord,temp;
  
  while(getline(file,line)){// looking through each line of the file
    
    string lineString = line;
    istringstream lineStream(lineString);
    
    while(lineStream >> lineWord){ //looking at every word in each line
      if(lineWord == word){ // check to see if any word in the line matches the userword
        count++;
        temp = line[0]; //gets the review number
        num = stoi(temp);// casts it to an int
        score += num;
      }
    }
  }
  average = score/count;
  return average;
}
                 
void wordRating(double average,string word){

  if(average < 1){
    cout << "\nThe average score for ["<<word<<"] is "<<setprecision(4)<<average<<" negative."<< endl;
  }
  else if(average > 1 && average < 3){
    cout <<"\nThe average score for ["<<word<<"] is "<<setprecision(4)<<average<<" neutral."<< endl;
  }
  else if(average > 3){
    cout <<"\nThe average score for ["<<word<<"] is "<<setprecision(4)<<average<<" positive."<< endl;
  }
  else
    cout << "\nThe average score for ["<<word<<"] is "<< "2.000"<<" neutral."<< endl;
}
  
