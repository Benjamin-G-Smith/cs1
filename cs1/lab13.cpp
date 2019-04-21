// Ben Smith, Sasank Kanuri
// Lab13.cpp
// 3/6/2017

// PURPOSE: To create a program that reads data from a file and to preform tasks
//  with that data.

// INPUTS: The file given by the instructer

// PROCESSING: Finding the oldest member in the file. Finding the person who drinks
//  the least amount of coffee in the file. Sorts the file in alphabetical order.

// OUTPUTS: The oldest person's record. The person who drinks the least amount of
//  coffee and their record. The original list along with the sorted list.

// EXAMPLES:
// The oldest person in the file is [Tom Smith]
// Record: Name Tom Smith, Age 102, CoffeeIn 1

// The person who drinks the least amount of coffee in the file is [Mary Wells]
// Record: Name Mary Wells, Age 40, CoffeeIn 1

// UNSORTED:
// Tammy 12 1
// Tom 50 6
// Sam 34 4
// Abner 63 5
// Chris 21 3
// Nicole 14 0
// Gwen 17 2
// Sandy 97 6
// Grace 102 3
// April 52 3
// Wendy 42 6
// Debbie 50 8
// David 48 5
// Janice 77 1
// Walter 81 1
// Hugo 20 2
// Michael 65 1
// Eric 35 7
// Jason 40 3
// Teresa 32 3
// Lin 25 1
// Ben 26 2
// Joe 17 7

// *Sorted File*

// SORTED:
// Abner
// 12
// 1
// April
// 50
// 6
// Ben
// 34
// 4
// Chris
// 12
// 1
// David
// 12
// 1
// Debbie
// 14
// 0
// Eric
// 17
// 2
// Grace
// 97
// 6
// Gwen
// 97
// 6
// Hugo
// 50
// 6
// Janice
// 42
// 6
// Jason
// 14
// 0
// Joe
// 12
// 1
// Lin
// 42
// 6
// Michael
// 81
// 1
// Nicole
// 50
// 6
// Sam
// 81
// 1
// Sandy
// 97
// 6
// Tammy
// 50
// 6
// Teresa
// 32
// 3
// Tom
// 42
// 6
// Walter
// 81
// 1
// Wendy
// 42
// 6

#include <iostream>
#include <fstream>

using namespace std;

struct PersonalRecord{
  string name;
  int age;
  int coffeeIn;
};
PersonalRecord peopleData[150];

// This is the file location.
const string FILE_NAME = "/home/fac/lillethd/cpsc1420/lab_input_coffee.dat";

// This function will search through the file and find the oldest person.
// The function returns the index of the oldest person.
// IN: Array that contains the information for everyone in the file, and
// the size of the array.
// OUT: The  name of the oldest person in the file.
int oldestPerson(PersonalRecord data[],int size);
// This function searches through the file and finds the person who drinks
// the least amount of coffee and returns the index of that person.
// IN: The array that contains the information for everyone in the file,
// and the total size of the array.
// OUT: The name of the person who drinks the least amount of coffee.
int leastCoffee(PersonalRecord data[], int size);
// This function sorts the the the contents of the file in alphabatical order.
// IN: The array that contains the information for everyone in the file, and the
// total size of the array.
// OUT: The contents of file sorted alphabetically.
void alphaSort(PersonalRecord data[], int size);

int main(){
  int oldestPersonIndex,leastCoffeeIndex;
  ifstream inputFile;
  int size = 0;
  inputFile.open(FILE_NAME);
  // This if statement checks to see if the file opened properly.
  if(inputFile.fail()){
    cout <<"ERROR, The file did not open properly" <<endl;
  }
  // This loop reads data from the file and stores it in the struct array.
  for(int index = 0; inputFile >> peopleData[index].name; index++){
    inputFile >> peopleData[index].age;
    inputFile >> peopleData[index].coffeeIn;
    size ++;
  }

  // This will print the oldest person in the file along with their record.
  oldestPersonIndex  =  oldestPerson(peopleData,size);
  cout <<"The oldest person is: "<<peopleData[oldestPersonIndex].name << endl;
  cout <<"Record: "<< "Name "<<peopleData[oldestPersonIndex].name
       <<" Age "<<peopleData[oldestPersonIndex].age
       <<" CoffeeIn "<<peopleData[oldestPersonIndex].coffeeIn<< endl;
  leastCoffeeIndex = leastCoffee(peopleData,size);
  // This will print the name of the person who drinks the least amount of coffe along with
  // their record.
  cout <<"The person who drinks the least  is: "<<peopleData[leastCoffeeIndex].name << endl;
  cout <<"Record: "<< "Name "<<peopleData[leastCoffeeIndex].name
       <<" Age "<<peopleData[leastCoffeeIndex].age
       <<" CoffeeIn "<<peopleData[leastCoffeeIndex].coffeeIn<< endl;
  cout << "UNSORTED: " << endl;
  // This loop will print the array that contains the unsorted contents of the file.
  for(int i = 0; i < size; i++){
    cout << peopleData[i].name << endl;
    cout << peopleData[i].age << endl;
    cout << peopleData[i].coffeeIn << endl;
  }
  // This will print the sorted contents of the array.
  cout << "SORTED: " << endl;
  alphaSort(peopleData,size);
  inputFile.close();
}

int oldestPerson(PersonalRecord data[],int size){
  int max = 0;
  int index;
  // This loop will search the file to find the oldest person.
  for(int i = 0; i < size; i++){
    if(data[i].age > max){
      max = data[i].age;
      index = i;
    }
  }
    return index; 
}
int leastCoffee(PersonalRecord data[], int size){
  int least = 100;
  int index;
  // This loop will search the file to find the person who drinks the least amount of coffee.
  for(int i = 0; i < size; i++){
    if(data[i].coffeeIn < least){
      least = data[i].coffeeIn;
      index = i;
    }
  }
  return index;
}
void alphaSort(PersonalRecord data[], int size){
  int minIndex;
  string minValue;

  // This is a selection sort algorithm that will sort the file in alphabateical order.
  for(int i = 0; i < (size-1); i ++){
    minIndex = i;
    minValue = data[i].name;
    for(int j = i + 1; j < size; j++){
      if(data[j].name < minValue){
        minValue = data[j].name;
        minIndex = j;
      }
    }
    data[minIndex] = data[i];
    data[i].name = minValue;
  }
  for(int i = 0; i < size; i++){
    cout << data[i].name << endl;
    cout << data[i].age << endl;
    cout << data[i].coffeeIn << endl;
  }
}

  
  
