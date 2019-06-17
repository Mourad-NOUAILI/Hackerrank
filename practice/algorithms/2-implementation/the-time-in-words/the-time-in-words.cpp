#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string t[60] = {" o' clock",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		"ten",
		"eleven",
		"twleve",
		"thirteen",
		"fourteen",
		"quarter",
		"sixteen",
		"seventeen",
		"eighteen",
		"nineteen",
		"twenty",
		"twenty one",
		"twenty two",
		"twenty three",
		"twenty four",
		"twenty five",
		"twenty six",
		"twenty seven",
		"twenty eight",
		"twenty nine",
		"half"
};

int main()
{
  unsigned short int H,M;
  cin>>H;
  assert(H >= 1 && H <= 12);
  cin>>M;
  assert(M >= 0 && M <= 59);
  
  if (M == 0) cout<<t[H]<<t[0]<<'\n';
  else if (M >= 1 && M <= 14) cout<<t[M]<<" minutes past "<<t[H]<<'\n';
  else if (M == 15) cout<<t[M]<<" past "<<t[H]<<'\n';
  else if (M >= 16 && M <= 19) cout<<t[M]<<" minutes past "<<t[H]<<'\n';
  else if (M >= 20 && M <= 29) cout<<t[M]<<" minutes past "<<t[H]<<'\n';
  else if (M == 30) cout<<t[M]<<" past "<<t[H]<<'\n';
  else if (M >= 31) 
  {
    if (60 - M == 15)  cout<<t[60-M]<<" to "<<t[H+1]<<'\n';
    else cout<<t[60-M]<<" minutes to "<<t[H+1]<<'\n';
  }
  return 0;
}
