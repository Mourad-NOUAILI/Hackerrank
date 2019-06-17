#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    unsigned long long int A,B;
    cin>>A>>B;
    cout<<(unsigned long long int) (floor(sqrt(B)) - ceil(sqrt(A))+1)<<'\n';
  }
  
  return 0;
}
