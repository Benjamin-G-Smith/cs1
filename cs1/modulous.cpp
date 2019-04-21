// Ben Smith
// modulous.cpp
// 1/16/2017

// PURPOSE: Working with the modulous operator


#include <iostream>
using namespace std;

int main()
{
  int  finalPrice;
  double tax, price; 

  price = 27.0; 
  tax = 0.06;

  finalPrice = ( price % tax ) + ( price/100);

  cout << "The final price is: \n" << finalPrice << endl;

  return 0;   
}
