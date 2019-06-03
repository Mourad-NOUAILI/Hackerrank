/*
  Optimized solution
  Time complexity: O(t * n)
*/
#include <bits/stdc++.h>

using namespace std;

// Time complexity for the function: O(n)
int* absolute_permutation(int n, int k) {
  bool *visited = new bool[n];
  fill_n(visited, n, false);
  bool check = (k != 0) ? (n % (2*k) == 0) : true;
  if (!check) return NULL;
  int* res = new int[n];
  for (int i = 1 ; i <= n  ; ++i){
    if (!visited[i-1]) {
      visited[i-1] = true;
      visited[i+k-1] = true;
      res[i-1] = i + k;
      res[i+k-1] = i;
    }
  }
  return res;
}

int main(){
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    int n, k;
    cin >> n >> k;

    /*int *arr = new int[n];
    for (int i = 0 ; i < n ; ++i)
      arr[i] = i + 1;*/

    int* result = absolute_permutation(n, k);

    if (result == NULL)
      cout << "-1";
    else {
      for (int i = 0; i < n; i++) {
        cout << result[i] <<' ';
      }
    }
    cout << "\n";
  }

  return 0;
}
