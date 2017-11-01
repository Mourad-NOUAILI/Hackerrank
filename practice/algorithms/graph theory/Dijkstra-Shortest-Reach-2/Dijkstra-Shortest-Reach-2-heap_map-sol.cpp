#include <bits/stdc++.h>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 1e9;

class Edge {
  public:
    pair<int, int> edge;
  public:
    Edge(pair<int, int> e) {
      edge = e;
    }
};

void createAdjList(vector<list<Edge>> & adjList , int nbEdges) {
  for (int edge = 0 ; edge < nbEdges ; ++edge) {
    int vertex1 , vertex2 , weight;
    scanf("%d%d%d", &vertex1, &vertex2, &weight);
    vertex1--;
    vertex2--;
    Edge e1({vertex2, weight});
    Edge e2({vertex1, weight});
    adjList[vertex1].push_back(e1);
    adjList[vertex2].push_back(e2);
  
  }
}

void initHeap(map<int, int> & h , int nbVertices) {
  for (int i = 0 ; i < nbVertices ; ++i)
    h.insert(pair<int, int>(i, INF));
}

template <typename T>
typename T::iterator min_map_element(T& m) {
  return min_element(m.begin(), m.end(), [](typename T::value_type& l, typename T::value_type& r) -> bool {
     return l.second < r.second; 
     });
}

void shorestDistances(int *dist, 
    vector<list<Edge>> & adjList,
    map<int,int> h) {

  while(!h.empty()) {
    int current = min_map_element(h)->first;
    dist[current] = h[current];
    h.erase (current);

    for (auto it: adjList[current]){
      pair<int, int> e = it.edge;
      int v = e.first;
      int w = e.second;

      map<int, int>::iterator it1 = h.find(v);
      if (it1 == h.end()) continue;

      if (h[v] > dist[current] + w) {
        h[v] = dist[current] + w;
      }
    }
  }
}

int main() {
  int testCases;
  scanf("%d", &testCases);
  while (testCases--) {
    int nbVertices , nbEdges;
    scanf("%d%d", &nbVertices, &nbEdges);

    vector<list<Edge>> adjList(nbVertices);
    createAdjList(adjList, nbEdges);
    
    /*int i = -1;
    for (auto it1: adjList) {
    list<Edge> l = it1;
    i++;
    cout << i << " ==> ";
    for (auto it2: l)
      cout << it2.edge.first << "/" << it2.edge.second << ' ' ;
    cout << '\n';
  }*/

    int start;
    scanf("%d", &start);

    start--;

    map<int,int> heapMap;

    initHeap(heapMap, nbVertices);

    heapMap[start] = 0;

     
  /*for (auto it: heapMap)
    printf("%d ==> %d\n", it.first, it.second);*/

    int *dist = new int[nbVertices];
    shorestDistances(dist, adjList, heapMap);

    for (int i = 0 ; i < nbVertices ; ++i) {
      if (i == start) continue;
      printf("%d ", dist[i] != INF ? dist[i] : -1);
    }

    delete dist;
    
    printf("\n");
  } 


  return 0;
}
