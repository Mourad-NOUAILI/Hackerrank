#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ULLI;

map<ULLI, ULLI> parent;

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
  ULLI len = l.size();
  for (ULLI i = 0 ; i < len ; ++i){
    ULLI v = l[i];
    map<ULLI, ULLI>::iterator it1 = parent.find(v);
    if (it1 == parent.end()){
      parent[v] = s;
      dfs_visit(adjList, v);
    }
  }
}

void dfs(ULLI V, vector<ULLI> *adjList){
  for (ULLI s = 0 ; s < V ; ++s){
    cout << "Vertex #" << s+1 <<":\n";
    parent.clear();
    map<ULLI, ULLI>::iterator it1 = parent.find(s);
    if (it1 == parent.end()){
      parent[s] = NAN;
      dfs_visit(adjList, s);
    }
    for (auto it: parent)
        cout << it.first + 1 << ": " << it.second + 1 << '\n';
    cout << "***********\n";
  } 
}

void displayAdjList(vector<ULLI> *adjList , ULLI nbVertices) {
  for (ULLI vertex = 0 ; vertex < nbVertices ; ++vertex) {
    cout << vertex+1 <<"-->";
    vector<ULLI>::iterator it;
    for (it = adjList[vertex].begin() ; it != adjList[vertex].end() ; ++it)
      cout << *it+1 << ' ';
    cout << '\n';
  }
}


int main() {
  ULLI q;

  scanf("%llu", &q);

  for (ULLI i = 1 ; i <= q ; ++i){

    ULLI n, m, cLib, cRoad;

    scanf("%llu%llu%llu%llu", &n, &m, &cLib, &cRoad);

    vector<ULLI> *adjList = new vector<ULLI>[n];

    createAdjList(adjList, m);


    dfs(n, adjList);

    //displayAdjList(adjList, n);

    //delete adjList;
  }

  return 0;
}

