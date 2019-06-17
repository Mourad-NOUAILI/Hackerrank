#include <iostream>

using namespace std;

int main()
{
  int T;
  cin>>T;
  
  for (int iT = 0 ; iT < T ; ++iT)
  {
    int N,K;
    cin>>N>>K;
    int s = 0;
    for (int iTime = 0 ; iTime < N ; ++iTime)
    {
      int ai;
      cin>>ai;
      if (ai <= 0) s++;
    }
    (s < K) ? cout<<"YES\n" : cout<<"NO\n";
  }
  
  return 0;
}
