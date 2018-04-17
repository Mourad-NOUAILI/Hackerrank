#include <bits/stdc++.h>


using namespace std;

const int INF = 1e9;

class Edge{
  public:
    pair<int, int> edge;
  public:
    Edge(pair<int, int> e ) {
      edge = e;
  }
};

void createAdjList(vector<list<Edge> > & adjList , int nbEdges) {
  for (int edge = 0 ; edge < nbEdges ; ++edge) {
    int vertex1 , vertex2 , weight;
    scanf("%d%d%d", &vertex1, &vertex2, &weight);
    Edge e1(make_pair(vertex2-1,weight));
    Edge e2(make_pair(vertex1-1,weight));
    adjList[vertex1-1].push_back(e1);
    adjList[vertex2-1].push_back(e2);
  }
}

void bfs (int start , vector<list<Edge> >  adjList , int nbVertices , int *dist) {
  bool visited[nbVertices];
  fill(visited, visited + nbVertices, false);

  dist[start] = 0;
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, start});

  while (!q.empty()) {
    int current = q.top().second;
    q.pop();

    if (visited[current]) continue;

    visited[current] = true;
       
    for (auto it: adjList[current]) {
      pair<int, int> e = it.edge;
      int v = e.first;
      int w = e.second;
      if (dist[v] > dist[current] + w ) {
        dist[v] = dist[current] + w;
        q.push({dist[v], v});
      }
    }
  }
}

void displayDistances(int *dist , int nbVertices , int start) {
  for (int i = 0 ; i < nbVertices ; ++i) {
    if (i == start) continue;
    printf("%d ", (dist[i] != INF ? dist[i] : -1));
  }
}


int main() {
  int testCases;
  scanf("%d", &testCases);

  while (testCases--) {
    int nbVertices , nbEdges;
    scanf("%d%d", &nbVertices, &nbEdges);

    vector<list<Edge> > adjList(nbVertices);
    createAdjList(adjList, nbEdges);

    int start;
    scanf("%d", &start);

    int *dist = new int[nbVertices];
    fill(dist, dist + nbVertices, INF);

    bfs(start-1, adjList, nbVertices, dist);

    displayDistances(dist, nbVertices, start-1);

    cout << '\n';
  }

  return 0;
}

