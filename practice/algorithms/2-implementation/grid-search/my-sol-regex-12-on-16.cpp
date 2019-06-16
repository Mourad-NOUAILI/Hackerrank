/*
 Solution succed only on 21 / 25 tests (4 tests with wrong answer)
 O(t *  R * c² )
*/
#include <bits/stdc++.h>

using namespace std;


string grid_search(vector<string> G, vector<string> P, int R, int C, int r) {
  // Extract the 1st line of the pattern P
  string P_line1 = P[0];

  // TODO; Store all positions of line_1 in the grid G
  string grid_as_string;
  vector<pair<int, int>> shifts;
  for (int i = 0 ; i < R ; ++i) {
    grid_as_string.append(G[i] + '\n');
    size_t p = G[i].find(P_line1);
    while ( p != string::npos) {
      shifts.push_back({p, C-p-P_line1.size()});
      p = G[i].find(P_line1, p + P_line1.size());
    }
  }

  if (shifts.empty()) return "NO";

  for (auto s: shifts) {
    string left_shift = to_string(s.first);
    string right_shift = to_string(s.second);
    string pattern;
    if (pattern.size() > 0) pattern.clear();
    for(int i = 0 ; i < r ; ++i){
      string P_line = P[i];
      pattern += "\\d{" + left_shift + "}" + P_line + "\\d{" + right_shift + "}\\s?";
    }
    regex reg(pattern);
    //cout << pattern << '\n';
  //  cout << grid_as_string << '\n';

    smatch sm;
    if (regex_search(grid_as_string, sm, reg)) return "YES";
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

     string result = grid_search(G, P, R, C, r);

    cout << result << "\n";
  }

  return 0;
}
