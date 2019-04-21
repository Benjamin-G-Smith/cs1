// Ben Smith
// p1Test.cpp
// 1/22/2017

// PURPOSE: To create a program that allows the user to attempt to guess the
//  randomly genereated numebr by the program.


#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  int randomGen;// userGuess, numberAttempts;

  randomGen = rand() % 100 + 1;

  cout << randomGen << endl;

  return 0; 
}
