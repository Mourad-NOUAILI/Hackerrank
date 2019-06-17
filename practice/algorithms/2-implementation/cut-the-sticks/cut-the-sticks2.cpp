#include <iostream>
#include <list>
#include<bits/stdc++.h>
#include <algorithm>

using namespace std;

bool nonZero (int i) { return i != 0; }
void diff (int i) { cout<<i<<' '; }

int main()
{
  unsigned int nbSticks;
  cin>>nbSticks;
  
  assert(nbSticks >= 1 && nbSticks <= 1000);
  
  list<unsigned int>  sticksLengths;
  
  for (unsigned int i = 0 ; i < nbSticks ; ++i)
  {
    unsigned int len;
    cin>>len;
    
    assert(len >= 1 && len <= 1000);
    
    sticksLengths.push_back(len);
  }
  
  unsigned int myCount = count_if (sticksLengths.begin(), sticksLengths.end(), nonZero);
  
  while (myCount != 0)
  {
    sticksLengths.sort();
    sticksLengths.remove(0);
    myCount = count_if (sticksLengths.begin(), sticksLengths.end(), nonZero);
    unsigned int cutLen = sticksLengths.front();
    if (myCount != 0) cout<<myCount<<'\n';
    transform(sticksLengths.begin(), sticksLengths.end(), sticksLengths.begin(), [cutLen](unsigned int d) -> unsigned int { return d - cutLen; });
  }
  
  return 0;
}
   
