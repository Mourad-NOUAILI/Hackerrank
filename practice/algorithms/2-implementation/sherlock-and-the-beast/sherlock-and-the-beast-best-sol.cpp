#include <iostream>

using namespace std;

int main()
{
  int T;
  cin>>T;
  for (int i = 1 ; i <= T ; ++i)
  {
    int n;
    cin>>n;
    int c = 5*(2*n%3);
    if (c > n)
        cout<<-1<<'\n';
    else
        cout<< string(n-c, '5')<<string(c, '3')<<'\n';
  }

  return 0;
}
