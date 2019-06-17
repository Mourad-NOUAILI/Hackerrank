#include <bits/stdc++.h>

using namespace std;

int main () {
  //n: The number of chapters.
  //k: the number of maximum problems per chapter.
  int n , k;
  cin >> n >> k;

  int numPage = 1 ;
  int nbSpecial = 0;
  for (int i = 1 ; i <= n ; ++i) {
    int ti;
    cin >> ti;

    int numProb = 0;
    for (int ii = 1 ; ii <= ti ; ++ii) {
      numProb++;
      if (numProb == numPage)
        nbSpecial++;
      if (numProb % k == 0 && ii < ti || ii == ti)
        numPage++;
    }
  }
  cout << nbSpecial << '\n';
  return 0;
}
