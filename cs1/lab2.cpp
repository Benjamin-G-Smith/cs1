// Ben Smith
// lab2.cpp
// 1/11/17

// Pretentds that the user is giving input.

// PURPOSE: Allows the user to calculate the area of a circle.

// INPUT: Radius of the cirlce.

// PROCESSING: Multiplies the given radious by pi.

// OUTPUT: The area of the circle.

// EXAMPLES:
//  The radius of the circle is 5
//  The area of the circle is 78.5

#include <iostream>

using namespace std; 

const double PI = 3.14;         // constant PI  

int main(){
  int radius = 5;               // radius of the cirlce
  double area;                  // area of the cirlce

  area = radius * radius * PI;  // preforms the calculation for the area
  cout << "The radius of the cirlce is " << radius << endl;
  cout << "The area of the circle is " << area << endl; 
  return 0;  
}
