/*
Calculate the number of inversion using a Fenwick tree.
Complexity: O(t * N * log max(A[i])) (logarithmic)
*/

#include <bits/stdc++.h>

using namespace std;

int *tree = NULL;
int n;

void update(int i, int value){
  while(i<=n){
    tree[i]+=value;
    i+=(i&-i);
  }
}

int sum(int i){
  int sm=0;
  while(i>0){
    sm+=tree[i];
    i-=(i&-i);
  }
  return sm;
}

int range_sum(int i, int j){
  return sum(j)-sum(i);
}


int* convert(int *A){;
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
        cin >> n;

        int *A = new int[n];
        for (int i = 0; i < n; ++i) {
          cin >> A[i];
        }

        A = convert(A);

        tree = new int[n+1];
        fill_n(tree, n+1, 0);
        int inv_count = 0;

        // O(N * log N)
        for (int i = 0; i < n; ++i) {
          update(A[i], 1);
          inv_count += range_sum(A[i], n);
        }

        inv_count&1?cout<<"NO\n":cout<<"YES\n";

        delete[] A;
        delete[] tree;
    }

    return 0;
}
