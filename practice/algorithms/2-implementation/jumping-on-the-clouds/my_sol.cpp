#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int min_jumps(vector<int> arr, int n) {
  vector<int> jumps(n);
  jumps[0] = 0;
  for (int i = 1 ; i < n ; ++i) {
    jumps[i] = INF;
  }
  for (int end = 1 ; end < n ; ++end){
    for (int start = 0 ; start < end ; ++start){
      if (end <= start + arr[start])
        jumps[end] = min(jumps[end], jumps[start] + 1);
    }
  }
/*  for (int i = 0 ; i < n ; ++i) {
    cout << jumps[i] << ' ';
  }
  cout << '\n';*/
  return jumps[n-1];
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0 ; i < n ; ++i){
    int ci;
    cin >> ci;
    arr[i] = ci == 0 ? 2 : 0;
  }

  cout << min_jumps(arr, n) << '\n';

  return 0;
}
