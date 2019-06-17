#include <iostream>

using namespace std;

int main()
{
  unsigned int nbTestCases;
  cin>>nbTestCases;
  
  while (nbTestCases--)
  {
    unsigned int nbStones;
    cin>>nbStones;
    
    unsigned int a;
    cin>>a;
    
    unsigned int b;
    cin>>b;
    
    if ( a < b)
      for (unsigned int i = 0 ; i <= nbStones - 1 ; ++i)
	cout<< (nbStones -1 - i ) * a + i * b <<' ';
    else if (a == b) cout<< (nbStones -1) * a <<' ';
    else
      for (unsigned int i = 0 ; i <= nbStones - 1 ; ++i)
	cout<< (nbStones -1 - i ) * b + i * a <<' ';
    cout<<'\n';
  }
  
  return 0;
}
