#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ULLI;

ULLI vpc;
bool *visited = NULL;

void createAdjList(vector<ULLI> *adjList , ULLI nbEdges) {
  for (ULLI edge = 0 ; edge < nbEdges ; ++edge) {
    ULLI vertex1 , vertex2;
    cin >> vertex1 >> vertex2;
    vertex1--;
    vertex2--;
    adjList[vertex1].push_back(vertex2);
    adjList[vertex2].push_back(vertex1);
  }
}

void dfs_visit(vector<ULLI> *adjList, ULLI s){
  vector <ULLI> l = adjList[s];
  for (auto it: l){
    ULLI v = it;

    if (visited[v]) continue;
    visited[v] = true;

    vpc++;
    dfs_visit(adjList, v);
  }
  
}

ULLI dfs(ULLI V, vector<ULLI> *adjList, ULLI cLib, ULLI cRoad){
  ULLI roadsCoast = 0;
  ULLI libsCoast = 0;
  for (ULLI s = 0 ; s < V ; ++s){
    if (visited[s]) continue;
    visited[s] = true;
    vpc = 0;
    vpc++;

    dfs_visit(adjList, s);
   

    roadsCoast += (vpc - 1) * cRoad; 
    libsCoast += cLib; 
  }

 return roadsCoast + libsCoast; 
}


int main() {
  ULLI q;

  scanf("%llu", &q);

  for (ULLI i = 1 ; i <= q ; ++i){

    ULLI n, m, cLib, cRoad;

    scanf("%llu%llu%llu%llu", &n, &m, &cLib, &cRoad);

    vector<ULLI> *adjList = new vector<ULLI>[n];
    createAdjList(adjList, m);

    if (cRoad >= cLib) 
      printf("%llu\n", n * cLib);
    else {
      visited = new bool[n];
      fill(visited, visited + n , false);

      printf("%llu\n", dfs(n, adjList, cLib, cRoad));
    }

  }

  return 0;
}

