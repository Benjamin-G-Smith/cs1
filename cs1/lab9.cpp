// Ben Smith Sasank Kanuri
// Lab9.cpp
// 2/13/2017

// PURPOSE: Allows the user to calculate the distance between two points.

// INPUTS: Coordinate points entered by the user.

// PROCESSING: Calculate the horizontal and vertical distance. Calculates
//  the hypotenuse of the points given.

// OUTPUTS: The distance of the trip. A prompt telling the user to enter
//  points.

// EXAMPLES:
// Enter 2 coordinate points(x y x y)
// 2 2 4 4
// Distance of trip: 2.8
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double hypotenuse(int x1, int y1, int x2, int y2);
// Takes in four points. Returning The hypotenuse.
double distance(double inOne, double inTwo, double inThree, double inFour);
// Takes in four points given by the user. Passing the values to hypotenuse.
//  Returning the distance calculated in the hypotenuse function. 


int main(){
  double in1,in2,in3,in4; // Each point given by the user
  cout << "Welcome to the distance calculator!"<<endl;
  cout << "Enter 2 coordinate points" << endl;
  cout << "Enter your first X coordinate: ";
  cin >> in1;
  cout << "Enter your first Y coordinate: ";
  cin >> in2;
  cout << "Enter your second X coordinate: ";
  cin >> in3;
  cout << "Enter your second Y coordinate: ";
  cin >> in4;
  cout << setprecision(2); // Sets the decimal precision 
  cout << "Your distance is :" << distance(in1,in2,in3,in4)<<endl;

  return 0;
}
double hypotenuse(double x1, double y1, double x2, double y2){
  double width = x2 - x1;
  double height = y2 - y1;
  double hypotenuse = sqrt(pow(width, 2) + pow(height, 2));
  return hypotenuse;                        
}
double distance (double inOne, double inTwo, double inThree, double inFour){
  double userDistance = 0;
  return userDistance = hypotenuse(inOne, inTwo, inThree, inFour);
}
 
  
