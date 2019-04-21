// Ben Smith
// resturantbill.cpp
// 1/11/2017

// PURPOSE: allows the user to calculate the total bill including tax and tip

#include <iostream>

using namespace std;

int main(){

  double mealCharge, tax, tip, totalBill, totalTax;

  mealCharge = 44.50;
  tax = 0.0675;
  tip = 0.15;

  totalTax = mealCharge * tax + mealCharge;
  totalBill = totalTax * tip + totalTax;

  cout << "The bill including tax is: " << totalTax << endl;
  cout << "the bill including tax and tip is: " << totalBill << endl;

  return 0;  
}
