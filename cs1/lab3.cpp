// Ben Smith
// lab3.cpp
// 1/18/2017

// PURPOSE: Allows the user to compare two integers.

// INPUT: Any two integers.

// PROCESSING: Compares the two given integers. Determines which integer is
//  greater. Calculates the difference between the two integers.

// OUTPUT: The greater integer and the difference.

// EXAMPLES:
// Enter first INTEGER: 
// 5
// Enter second INTEGER: 
// 20
// Greater: 20
// Defference: 15
// Enter first INTEGER:
// -10
// Enter second INTEGER:
// 5
// Greater: -10
// Difference: 15

#include <iostream>

using namespace std;

int main(){

  int input1, input2, greater, difference;   
  // The first integer the user inputs
  // The second integer the user inputs
  // The greater of the two values
  // The difference of the two values
  cout << "Enter first INTEGER: " << endl;
  cin >> input1;
  cout << "Enter second INTEGER: " << endl;
  cin >> input2;

  if(input1 > input2)
    {
      greater = input1;                // Assigns the larger value to greater
      difference = input1 - (input2);  
    }
  else
    {
    greater = input2;
    difference = input2 - (input1);
    }

  cout << "Greater: " << greater << endl;
  cout << "Difference: " << difference << endl;

  
  return 0;  
}
