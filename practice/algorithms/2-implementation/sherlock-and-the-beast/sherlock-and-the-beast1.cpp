#include <iostream>

using namespace std;
// return negative number if not found 
// otherwise pivot is returned.
// caller can print 5 x pivot + 3 x (n-pivot)
int getPivot(int n) 
{
    while(n > 0 && n % 3 != 0) 
      n -= 5;
    
    return n;
}

int main()
{
  int T;
  cin>>T;
  for (int i = 1 ; i <= T ; ++i)
  {
    int n;
    cin>>n;
    int pivot = getPivot(n);
    if(pivot < 0) 
      cout << "-1\n";
    else 
    {
      int repeat = pivot/3;
      while(repeat--)
	cout << "555";
      repeat = (n-pivot)/5;
      while(repeat--)
	cout << "33333";
      cout << '\n';
    }
  }

  return 0;
}

