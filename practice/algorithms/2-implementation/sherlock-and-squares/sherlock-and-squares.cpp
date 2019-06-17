#include <iostream>
#include <cmath>

using namespace std;

unsigned long long int countSquareNumbers (unsigned long long int a , unsigned long long int b)
{
  unsigned long long int nb = 0;
  for (unsigned long long int n = a ; n <= b ; ++n)
  {
    double squareRoot = sqrt(n);
    double intPart , fracPart;
    fracPart = modf (squareRoot , &intPart);
    if (fracPart == 0.0) nb++;
  }
  return nb;
}
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    unsigned long long int A,B;
    cin>>A>>B;
    cout<<countSquareNumbers(A,B)<<'\n';
  }
  
  return 0;
}
