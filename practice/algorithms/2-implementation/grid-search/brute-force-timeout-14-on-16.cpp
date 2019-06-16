/*
* Brute force approach: O(t * R*C*r*c)
* Terminated due to timeout
*/
#include <bits/stdc++.h>

using namespace std;

bool check_match (vector<string> G, vector<string> P, int r, int c, int rg, int cg){
  for (int rp = 0 ; rp < r ; ++rp)
    for (int cp = 0 ; cp < c ; ++cp)
      if (P[rp][cp] != G[rg + rp][cg + cp]) return false;
  return true;
}

string grid_search(vector<string> G, vector<string> P, int R, int C, int r, int c) {
  for (int rg = 0 ; rg < R-r+1 ; ++rg)
    for (int cg = 0 ; cg < C-c+1 ; ++cg)
      if (check_match(G, P, r, c, rg, cg)) return "YES";

  return "NO";
}



int main(){
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    int R, C;
    cin >> R >> C;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> G(R);
    for (int i = 0; i < R; i++) {
      string G_item;
      getline(cin, G_item);
      G[i] = G_item;
    }

    int r, c;
    cin >> r >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> P(r);
    for (int i = 0; i < r; i++) {
      string P_item;
      getline(cin, P_item);
      P[i] = P_item;
    }

     string result = grid_search(G, P, R, C, r, c);

    cout << result << "\n";
  }

  return 0;
}
