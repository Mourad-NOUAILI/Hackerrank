#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0 ; i < n ; ++i)
    cin >> c[i];

  int i = 0, ans = 0;
  cout << i << ' ';
  while (i < n - 1){
    if (i + 2 >= n || c[i+2] == 1) {
      i++;
    }
    else {
      i += 2;
    }
    cout << i << ' ';
    ans++;
  }
  cout << '\n';
  cout << ans << '\n';
  return 0;
}
