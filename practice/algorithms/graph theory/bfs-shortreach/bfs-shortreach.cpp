#include <bits/stdc++.h>


using namespace std;

void createAdjList(vector<list<int> > & adjList , int nbEdges) {
  for (int edge = 0 ; edge < nbEdges ; ++edge) {
    int vertex1 , vertex2;
    cin >> vertex1 >> vertex2;
    adjList[vertex1-1].push_back(vertex2-1);
    adjList[vertex2-1].push_back(vertex1-1);
  }
}

void bfs (int start , vector<list<int> >  adjList , int nbVertices , vector<int> & dist) {
  vector<bool> visited(nbVertices);
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    for (list<int>::iterator it = adjList[current].begin() ; it != adjList[current].end() ; ++it) {
      if (!visited[*it]) {
        visited[*it] = true;
        q.push(*it);
        dist[*it] = dist[current] + 1;
      }
    }
  }
}

void displayDistances(vector<int> & dist , int nbVertices , int start) {
  for (int i = 0 ; i < nbVertices ; ++i)
    if (i != start-1) {
      if (dist[i] != 0)
        cout << 6 * dist[i] << ' ' ;
      else
        cout << "-1 ";
    }
}

int main() {
  int testCases;
  cin >> testCases;

  while (testCases--) {
    int nbVertices , nbEdges;
    cin >> nbVertices >> nbEdges;

    vector<list<int> > adjList(nbVertices);
    createAdjList(adjList,nbEdges);

    int start;
    cin >> start;

    vector<int> dist(nbVertices);

    bfs(start-1,adjList,nbVertices,dist);

    displayDistances(dist,nbVertices,start);
    cout << '\n';
  }

  return 0;
}


