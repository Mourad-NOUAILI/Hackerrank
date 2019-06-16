/*
* Dynamic programming approach: O(t * r*R*C)
* Accepted
*/
#include <bits/stdc++.h>

using namespace std;



string grid_search(vector<string> G, vector<string> P, int R, int C, int r, int c) {
  // Declare the r x R matrix
  vector<vector<pair<bool, vector<int>>>> dp(r, vector<pair<bool, vector<int>>>(R));

  // Fill it
  for (int i = 0 ; i < r ; ++i){
    vector<vector<int>> tmp(R);
    for (int j = 0 ; j < R ; ++j){
      size_t p = G[j].find(P[i]);
      while (p != string::npos){
        tmp[j].push_back(p);
        dp[i][j] = {true, tmp[j]};
        p = G[j].find(P[i], p + 1);
      }
    }
  }

  // Run over all diagonals
  for (int d = 0 ; d < R-r+1 ; ++d){

    // hash map to compute the number of occurence of each position
    map<int, int> occ;

    // Run over diagonal (d)
    for (int i = 0 ; i < r ; ++i){
      if (dp[i][i+d].first){
        // Compute the number of occurence of the position (p) in (d)
        for (auto p: dp[i][i+d].second)
          occ[p]++;
      }
      else
        break;
    }

    for (auto cnt: occ)
      // If #occurence of a position is equal to (r), (P) exists in (G)
      if (cnt.second == r) return "YES";
  }

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
