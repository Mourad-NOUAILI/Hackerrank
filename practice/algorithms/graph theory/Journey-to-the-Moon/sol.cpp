#include <bits/stdc++.h>

using namespace std;

int V, E;

list<int> *adjList = NULL;

bool *visited = NULL;

int cnt;

void createAdjList(int nbEdges) {
  for (int edge = 0 ; edge < nbEdges ; ++edge) {
    int vertex1 , vertex2;
    cin >> vertex1 >> vertex2;
 
    adjList[vertex1].push_back(vertex2);
    adjList[vertex2].push_back(vertex1);
  }
}


void dfs_visit(int v, bool visited[]){
  visited[v] = true;
  
  //Compute the number of elements of each set.
  cnt++;
  
  list<int>::iterator i;
  
  for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
    if (!visited[*i])
      dfs_visit(*i, visited);
}

void dfs(int v){
  cnt = 0;
  dfs_visit(v, visited);
}

int main() {
  
  cin >> V >> E;
  
  adjList = new list<int>[V];

  createAdjList(E);

  visited = new bool[V];
        
  for (int i = 0; i < V; ++i)
    visited[i] = false;
  
  
  long long int ans = 0;
  long long int s = 0;
  for (int i = 0 ; i < V ; ++i) {
    if (visited[i]) continue;
    visited[i] = true;
    dfs(i);
    ans += s * cnt;
    s += cnt;
  }

  printf("%lld\n", ans);

  return 0;
}
