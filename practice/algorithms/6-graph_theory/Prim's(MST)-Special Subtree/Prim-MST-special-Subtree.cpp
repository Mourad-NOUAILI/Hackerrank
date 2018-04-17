#include <bits/stdc++.h>
#include <map>
#include <algorithm>

using namespace std;

class Edge {
  public:
    int vertex1;
    int vertex2;
  public:
    Edge(int v1 , int v2) {
      vertex1 = v1;
      vertex2 = v2;
    }
};

class EdgeWeight {
  public:
    int vertex;
    int weight;
  public:
    EdgeWeight(int v , int w) {
      vertex = v;
      weight = w;
    }
};

void createAdjList(vector<list<EdgeWeight> > & adjList , int nbEdges) {
  for (int edge = 0 ; edge < nbEdges ; ++edge) {
    int vertex1 , vertex2 , weight;
    cin >> vertex1 >> vertex2 >> weight;
    EdgeWeight e1(vertex2-1,weight);
    EdgeWeight e2(vertex1-1,weight);
    adjList[vertex1-1].push_back(e1);
    adjList[vertex2-1].push_back(e2);
  }
}

void initHeap(map<int,int> & h , int nbVertices) {
  for (int i = 0 ; i < nbVertices ; ++i)
    h[i] = 100000;
}

template <typename T>
typename T::iterator min_map_element(T& m) {
    return min_element(m.begin(), m.end(), [](typename T::value_type& l, typename T::value_type& r) -> bool { return l.second < r.second; });
}

/*template <typename T>
void displayMap(T m) {
  for (typename T::iterator it = m.begin() ; it != m.end() ; ++it)
    cout <<it->first << "->" << it->second;
  cout << '\n';
}*/

/*void displayMap(map<int,Edge> & vertexEdge) {
  for (map<int,Edge>::iterator it = vertexEdge.begin() ; it != vertexEdge.end() ; ++it)
    cout <<it->first << "->(" << it->second.vertex1 <<',' <<it->second.vertex2 <<")";
  cout << '\n';
}

void displayMap1(map<int,int> & heapMap) {
  for (map<int,int>::iterator it = heapMap.begin() ; it != heapMap.end() ; ++it)
    cout <<it->first << "->(" << it->second  << ")";
  cout << '\n';
}*/

int  primSubTree(vector<list<EdgeWeight> > & adjList , int start , map<int,int> & heapMap , map<int,Edge> & vertexEdge) {
  int minWeight = 0;
  while(!heapMap.empty()) {
    heapMap.erase(start);
    list<EdgeWeight> neighbours = adjList[start];
    for(list<EdgeWeight>::iterator it = neighbours.begin() ; it != neighbours.end() ; ++it) {
      map<int,int>::iterator itSearch = heapMap.find(it->vertex);
      if (itSearch != heapMap.end())
        heapMap[it->vertex] = min(heapMap[it->vertex],it->weight);
    }
    int prevStart = start;
    map<int, int>::iterator minPair = min_map_element(heapMap);
    start = minPair->first;
    minWeight += minPair->second;

    Edge edge(prevStart,start);
    vertexEdge.insert(make_pair(start,edge));
  }
  return minWeight;
}

int main() {
  int nbVertices , nbEdges , weight;
  cin >> nbVertices >> nbEdges;

  vector<list<EdgeWeight> > adjList(nbVertices);
  createAdjList(adjList,nbEdges);

  int start;
  cin >> start;

  map<int,Edge> vertexEdge;
  map<int,int> heapMap;

  initHeap(heapMap,nbVertices);
  heapMap[start-1] = 0;

  cout << primSubTree(adjList,start-1,heapMap,vertexEdge) << '\n';
  //displayMap(vertexEdge);

  return 0;
}
