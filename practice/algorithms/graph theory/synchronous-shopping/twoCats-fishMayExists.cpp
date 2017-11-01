#include <bits/stdc++.h>


using namespace std;

const int INF = 1e9;

int n, m;

int **dist = NULL;
vector<pair<int, int>> *adj = NULL;
bool *masks = NULL;

void createAdjList(void) {
  for (int edge = 0 ; edge < m ; ++edge) {
    int x , y , z;
    cin >> x >> y >> z;

    x--;
    y--;

    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }
}


void dijkstra (int start) {
  for (int i = 0 ; i < n ; ++i)
    for (int j = 0 ; j < 2 ; ++j)
      dist[i][j] = INF;

  dist[start][masks[start]] = 0;
  
  priority_queue<pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> q;

  q.push({dist[start][masks[start]], {start, masks[start]}});

  while (!q.empty()) {
    int current = q.top().second.first;
    int currentMask = q.top().second.second;
    q.pop();
       
    for (auto it: adj[current]) {
      int v = it.first;
      int w = it.second;
      if (dist[v][currentMask || masks[v]] > dist[current][currentMask] + w ) {
        dist[v][currentMask || masks[v]] = dist[current][currentMask] + w;
        q.push({dist[v][currentMask || masks[v]], {v, currentMask || masks[v]}});
      }
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  adj= new vector<pair<int, int>>[n];
  masks = new bool[n];

  dist = new int*[n];
  for (int i = 0 ; i < n ; ++i)
    dist[i] = new int [2];
  
  
  for (int i = 0 ; i < n ; ++i) {
    int ti;
    cin >> ti;
    assert(ti == 0 | ti == 1);
    masks[i] = ti;
  } 
  

  createAdjList();


  dijkstra(0);
  
  int ans = INF;
  for (int i = 0 ; i < 2 ; ++i)
    for (int j = i ; j < 2 ; ++j)
      if (i || j == true) 
        ans = min(ans, max(dist[n-1][i], dist[n-1][j]));

  cout << ans << '\n';
  return 0;
}

