#include <iostream>

using namespace std;

unsigned long long int getDigits (unsigned long long int n)
{
  unsigned long long int n1 = n;
  unsigned long long int nb = 0;
  while (n != 0)
  {
    if (n % 10 != 0 && n1 % (n%10) == 0) nb++;
    n = n / 10;
  }
  return nb;
}

int main ()
{
  int T;
  cin>>T;
  for (int i = 1 ; i <= T ; ++i)
  {
    unsigned long long int N;
    cin>>N;
    cout<<getDigits(N)<<'\n';
  }
  
  return 0;
}
