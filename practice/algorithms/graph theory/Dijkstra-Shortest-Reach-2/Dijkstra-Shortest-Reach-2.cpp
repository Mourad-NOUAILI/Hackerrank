#include <bits/stdc++.h>


using namespace std;

class Edge{
  public:
    int vertex;
    int weight;
  public:
    Edge(int v , int w) {
    vertex = v;
    weight = w;
  }
};

void createAdjList(vector<list<Edge> > & adjList , int nbEdges) {
  for (int edge = 0 ; edge < nbEdges ; ++edge) {
    int vertex1 , vertex2 , weight;
    cin >> vertex1 >> vertex2 >> weight;
    Edge e1(vertex2-1,weight);
    Edge e2(vertex1-1,weight);
    adjList[vertex1-1].push_back(e1);
    adjList[vertex2-1].push_back(e2);
  }
}

void bfs (int start , vector<list<Edge> >  adjList , int nbVertices , vector<int> & dist) {
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    for (list<Edge>::iterator it = adjList[current].begin() ; it != adjList[current].end() ; ++it) {
      int v = it->vertex;
      int w = it->weight;
      if (dist[v] > dist[current] + w ) {
        q.push(v);
        dist[v] = dist[current] + w;
      }
    }
  }
}

void displayDistances(vector<int> & dist , int nbVertices , int start) {
  for (int i = 0 ; i < nbVertices ; ++i)
    if (i != start-1) {
      if (dist[i] != 1000000)
        cout << dist[i] << ' ' ;
      else
        cout << "-1 ";
    }
}

void initDistances(vector<int> & dist , int nbVertices) {
  for (int i = 0 ; i < nbVertices ; ++i)
    dist[i] = 1000000;
}

int main() {
  int testCases;
  cin >> testCases;

  while (testCases--) {
    int nbVertices , nbEdges;
    cin >> nbVertices >> nbEdges;

    vector<list<Edge> > adjList(nbVertices);
    createAdjList(adjList,nbEdges);

    int start;
    cin >> start;

    vector<int> dist(nbVertices);

    initDistances(dist,nbVertices);

    bfs(start-1,adjList,nbVertices,dist);

    displayDistances(dist,nbVertices,start);
    cout << '\n';
  }

  return 0;
}
