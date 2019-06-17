#include <bits/stdc++.h>

using namespace std;

const int INF = 1e+9;

bool is_magic_square(vector<int> v){
  int a[3][3];
  for (int i = 0 ;  i < 3 ; ++i)
    for (int j = 0 ; j < 3 ; ++j)
      a[i][j] = v[3 * i + j];

  int s = 0;
  for (int i = 0 ; i < 3 ; ++i)
    s += a[0][i];


  // Check if the sum of each row is the same
  for (int i = 0 ; i < 3 ; ++i){
    int s_tmp = 0;
    for (int j = 0 ; j < 3 ; ++j){
      s_tmp += a[i][j];
    }
    if (s_tmp != s) return false;
  }

  // Check if the sum of each column is the same
  for (int i = 0 ; i < 3 ; ++i){
    int s_tmp = 0;
    for (int j = 0 ; j < 3 ; ++j){
      s_tmp += a[j][i];
    }
    if (s_tmp != s) return false;
  }

  // Check if the sum of diagonal #1 is the same
  int s_tmp = 0;
  for (int i = 0 ; i < 3 ; ++i){
    s_tmp += a[i][i];
  }
 if (s_tmp != s) return false;

  // Check if the sum of diagonal #2 is the same
  s_tmp = 0;
  for (int i = 0 ; i < 3 ; ++i){
    s_tmp += a[i][2-i];
  }
 if (s_tmp != s) return false;

 return true;

}

void generating_all_magic_squares(vector<vector<int>> & magic_squares){
  vector<int> v(9);
  for (int i = 0 ; i < 9 ; ++i)
    v[i] = i + 1;

  do {
    if (is_magic_square(v)) magic_squares.push_back(v);
  } while ( next_permutation( v.begin(), v.end() ) );

}

int diff (vector<int> a, vector<int> b) {
  int d = 0;
  for (int i = 0 ; i < 9 ; ++i)
    d += abs(a[i] - b[i]);

  return d;
}

// Complete the formingMagicSquare function below.
int forming_magic_square(vector<vector<int>> s) {
  vector<int>a(9);
  for (int i = 0 ;  i < 3 ; ++i)
    for (int j = 0 ; j < 3 ; ++j)
      a[ 3 * i + j] = s[i][j];

  vector<vector<int> > magic_squares;
  generating_all_magic_squares(magic_squares);

  /*for (int i = 0 ;  i < magic_squares.size() ; ++i) {
    vector<int> m = magic_squares[i];
    for (int l = 0 ;  l < 3 ; ++l) {
      for (int c = 0 ; c < 3 ; ++c) {
        cout << m[3 * l + c] << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
  }*/


  int res = INF;
  for (int i = 0 ;  i < magic_squares.size() ; ++i){
    res = min(res, diff(magic_squares[i], a));
  }

  return res;
}

int main(){
  vector<vector<int>> s(3);
  for (int i = 0; i < 3; i++) {
      s[i].resize(3);

      for (int j = 0; j < 3; j++) {
          cin >> s[i][j];
      }


  }

  int result = forming_magic_square(s);

  cout << result << "\n";

  return 0;
}
