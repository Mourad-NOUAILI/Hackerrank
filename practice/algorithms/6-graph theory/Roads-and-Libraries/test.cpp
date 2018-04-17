#include <bits/stdc++.h>

using namespace std;

const unsigned long long int INF = 1e15;

int main() {
  int i = 10, j = 10;
  ifstream fin("input04.txt");
  unsigned long long int  q;

  fin >> q;

  for (unsigned long long int i = 1 ; i <= q ; ++i){

    unsigned long long int n, m, cLib, cRoad;

    fin >> n >> m >> cLib >> cRoad;

    for (unsigned long long int j = 1 ; j <= m ; ++j) {
      unsigned long long int v1, v2;
      fin >> v1 >> v2;
    }

    unsigned long long int minCoast;
    int t = 1;
    for (unsigned long long int j = n ; j >= 1 && n - j <= m; --j){
     /* unsigned long long int nc = j;
      unsigned long long int nr = n - j;
      if (nr > m)
        nr = m;*/

      unsigned long long int  c = j * cLib + (n - j) * cRoad;
      if (t == 1){
        minCoast = c;
        t++;
      }
      else
        minCoast = min(minCoast, c);
    }

    printf("%llu\n", minCoast);
  }

  return 0;
}



