#include<bits/stdc++.h>
#include <algorithm> 
#include <vector>

using namespace std;

typedef  unsigned int UI;

int main()
{
  UI T,N;
  cin>>N>>T;
  assert(N >= 2 && N <= 100000);
  assert(T >= 1 && T <= 1000);
  
  vector<UI> widthes;
  for (UI iWidth = 1 ; iWidth <= N ; ++iWidth)
  {
    UI width;
    cin>>width;
    
    assert(width >= 1 && width <= 3);
    
    widthes.push_back(width);
  }

  for (UI caseTest = 1 ; caseTest <= T ; ++caseTest)
  {
    UI entry , exit;
    cin>>entry>>exit;
    
    assert(entry < exit && entry >= 0 && exit < N);
    assert(exit-entry+1 >= 2 && exit-entry+1 <= min(N,(UI)1000));
    
    //vector<UI>::iterator result = min_element(begin(widthes)+entry, begin(widthes)+exit);
    UI theMin = 1000;
    for (vector<UI>::iterator it = begin(widthes)+entry ; it <= begin(widthes)+exit ; ++it)
      if (theMin > *it) theMin = *it;
     cout<<theMin<<'\n';
  }
  
  return 0;
}
   
