/*
  Timeout solution by brute force
  Time complexity: O(t * n * n!)
*/
#include <bits/stdc++.h>

using namespace std;

bool check(int *arr, int n, int k) {
  int i = 0;
  while (i < n && abs(arr[i] - (i+1)) == k)
    i++;

  return i >= n;
}

// Time complexity: O(n * n!)
int* absolute_permutation(int *arr, int n, int k) {
  int* res = NULL;
  do {
    if (check(arr, n, k)) {
      res = arr;
      break;
    }
  }while(next_permutation(arr, arr+n));
  return res;
}

int main(){
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    int n, k;
    cin >> n >> k;

    int *arr = new int[n];
    for (int i = 0 ; i < n ; ++i)
      arr[i] = i + 1;

    int* result = absolute_permutation(arr, n, k);

    if (result == NULL)
      cout << "-1";
    else {
      for (int i = 0; i < n; i++) {
        cout << result[i] <<' ';
      }
    }


    delete [] arr;

    cout << "\n";
  }

  return 0;
}
