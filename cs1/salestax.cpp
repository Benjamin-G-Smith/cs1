// Ben Smith
// salestax.cpp
// 1/11/2017

// PURPOSE: calculate the sales tax for state and county

#include <iostream>

using namespace std;

int main(){
  int purchasePrice, stateTotalPrice, countyTotalPrice;
  double stateSalesTax, countySalesTax;

  purchasePrice = 98;
  stateSalesTax = 0.065;
  countySalesTax = 0.02;

  stateTotalPrice = purchasePrice * stateSalesTax + purchasePrice;
  countyTotalPrice = purchasePrice * countySalesTax + purchasePrice;

  cout << "The total amount for the state price is: " << stateTotalPrice << endl;
  cout << "The total amount for the county price is: " << countyTotalPrice << endl;

  return 0; 
}
