#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  unsigned int nbTestCases;
  cin>>nbTestCases;
  
  assert(nbTestCases >= 1 && nbTestCases <= 1000);
  
  for (unsigned int idCase = 1 ; idCase <= nbTestCases ; ++idCase)
  {
    unsigned long int money,cost,nbWrappers;
    cin>>money>>cost>>nbWrappers;
    
    assert(money >= 2 && money <= 100000);
    assert(cost >= 1 && cost <= money);
    assert(nbWrappers >= 2 && nbWrappers <= money);
    
    money = money / cost;
    
    cout<< money + (money - 1) / (nbWrappers - 1)<<'\n';
  }
  
  return 0;
}
