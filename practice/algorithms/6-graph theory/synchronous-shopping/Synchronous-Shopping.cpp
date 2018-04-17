#include <bits/stdc++.h>

using namespace std;

const int INF = 1e+9;
const int MAX_NODES = 1000 + 10; 
int n, m, k;

int **dist = NULL;
int *masks = NULL;
vector<pair<int, int> > *adj = NULL;

void createAdjList(void) {
  for (int edge = 0 ; edge < m ; ++edge) {
    int x , y , z;
    cin >> x >> y >> z;
    x--;
    y--;
    adj[x].push_back(make_pair(y, z));
    adj[y].push_back(make_pair(x, z));
  }
}


void dijkstra(int start) {
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < (1 << k); ++j)
      dist[i][j] = INF;

  dist[start][masks[start]] = 0;

  priority_queue<pair<int, pair<int, int> >,
    vector<pair<int, pair<int, int> > >,
    greater<pair<int, pair<int, int> > > > q;

  q.push({dist[start][masks[start]], {start, masks[start]}});
  while (!q.empty()){
    int current = q.top().second.first;
    int currentMask = q.top().second.second;

    q.pop();

    for (auto neighbors: adj[current]) {
      int v = neighbors.first;
      int w = neighbors.second;
      if (dist[v][currentMask | masks[v]] > dist[current][currentMask] + w ) {
        dist[v][currentMask | masks[v]] = dist[current][currentMask] + w;
        q.push( {dist[v][currentMask | masks[v]], {v, currentMask | masks[v]}} );

      }

    }

  }
}

int main () {
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> k;
  
  dist = new int*[n];
  for (int i = 0 ; i < n ; ++i)
    dist[i] = new int[1 << k];

  adj = new vector<pair<int, int> >[n];
  masks = new int[n];

  for(int i = 0; i < n; ++i) {
    int ti;
    cin >> ti;

    for(int j = 1; j <= ti; ++j) {
      int ai;
      cin >> ai;

      masks[i] |= (1 << (ai - 1));
    }
  }

  createAdjList();

 
  dijkstra(0);

  int ans = INF;
  for(int i = 0; i < (1 << k); ++i)
    for(int j = i; j < (1 << k); ++j)
      if ((i | j) == ((1 << k) - 1))
        ans = min(ans, max(dist[n-1][i], dist[n-1][j]));

  cout << ans << endl;
  
  return 0;
}

