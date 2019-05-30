/*
Calculate the number of inversion using a .
Complexity: O(t * N²)
*/

#include <bits/stdc++.h>

using namespace std;

int *A_sum = NULL;

int range_sum(int x, int end){
  int s = 0;
  for (int i = x+1 ; i <= end ; ++i)
    s += A_sum[i];
  return s;
}


int* convert(int *A, int n){;
  int *temp = new int[n];
  for (int i=0; i<n; i++)
    temp[i] = A[i];
    
  sort(temp, temp+n);

  map<int, int> A1;
  for (int i = 0; i < n; ++i)
    A1.insert({temp[i], i + 1});

  for (int i=0; i<n; i++)
    A[i] = A1[A[i]];

  return A;
}

int main(){
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int *A = new int[n];
        for (int i = 0; i < n; ++i) {
          cin >> A[i];
        }

        A = convert(A, n);


        A_sum = new int[n+1];
        fill_n(A_sum, n+1, 0);
        int inv_count = 0;
        for (int i = 0; i < n; ++i) {
          A_sum[A[i]] = 1;
          inv_count += range_sum(A[i], n);
        }

        inv_count % 2 != 0 ? cout<<"NO\n" : cout<<"YES\n";

        delete[] A;
        delete[] A_sum;
    }

    return 0;
}
