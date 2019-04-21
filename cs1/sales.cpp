// Ben Smith
// sales.cpp
// 1/11/17

// PURPOSE: taking 58 percent of $8.5 million (8,500,000)

#include <iostream>

using namespace std;

int main(){

  int profit, totalProfit;  
  double percent = 0.42;
    
  profit = 85000000;
  totalProfit = profit * percent;

  cout << "The company will generate " << totalProfit << " of " << profit << endl;
  
  return 0; 
}
