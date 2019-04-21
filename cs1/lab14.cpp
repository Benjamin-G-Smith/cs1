// Ben Smith
// lab14.cpp
// 3/8/2017

// PURPOSE: Allows the user to enter a number from 1 to 20, creating an array
//  filled with random numbers filling to that size.

// INPUTS: The size of the array given by the user.

// PROCESSING: Creating random numbers for each position in the user defined
//  array

// OUTPUTS: The array with the numbers that are randomly generated.

// EXAMPLES:

// Enter the size of the array [1-30]
// 31
// Error invalid input...
// Enter the size of the array [1-30]
// 10
// 1. 32
// 2. 23
// 3. 84
// 4. 14
// 5. 76
// 6. 56
// 7. 96
// 8. 43
// 9. 44
// 10. 22
// Sorting...
// 1. 14
// 2. 22
// 3. 23
// 4. 32
// 5. 43
// 6. 44
// 7. 56
// 8. 76
// 9. 84
// 10. 96
// PROGRAM ENDS

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 100; // used for the random number generation 
const int MIN = 1;

void fillArray(int numberArray[],int size);
// Takes in the unfilled array and the size given by the user
// Fills the array with random numbers 
int getSize();
// Gets the size of the array from the user returned as an int
void sort(int randomArray[],int size);
// Takes in the random number array and the size of the array
// uses the selection sort to sort the array in accending order.
int main(){
  int randomNumberArray[30] = {0}; // fills the array with zeros 
  int size = getSize(); // calls get size storing the value the user gives
  unsigned seed = time(0);
  srand(seed);
  fillArray(randomNumberArray,size); // fills the array with random numbers
  for(int i = 0; i < size; i++){ // Prints the unsorted
    cout << i+1 << ". "<< randomNumberArray[i] << endl;
  }
  cout << "Sorting..."<< endl;
  sort(randomNumberArray,size); // Sorts the array
  for(int i = 0; i < size; i++){ // Prints the sorted array
    cout << i+1 <<". "<< randomNumberArray[i]<< endl;
  }  
  return 0;
}
void sort(int randomArray[],int size){
  int minIndex,minValue;
  for(int startScan =0; startScan < (size-1); startScan++){
    minIndex = startScan;
    minValue = randomArray[startScan];
    for(int index = startScan + 1; index < size; index++){
      if(randomArray[index] < minValue){
        minValue = randomArray[index];
        minIndex = index;
      }
    }
    randomArray[minIndex] = randomArray[startScan];
    randomArray[startScan] = minValue;
  }
}
void fillArray(int numberArray[],int size){
  for(int i = 0; i < size; i++){
    numberArray[i] = (rand() %(MAX - MIN + 1)) + MIN; // fills each element with a random number
  }
}
int getSize(){
  int userInput;
  cout << "Enter the size of the array [1-30]" << endl;
  cin >> userInput;
  while(userInput > 30 || userInput < 1){ // makes sure user input is correct
    cout << "Error invalid array size..." << endl;
    cout << "Enter the size of the array [1-30]" << endl;
    cin >> userInput;
  }
  return userInput;
}
