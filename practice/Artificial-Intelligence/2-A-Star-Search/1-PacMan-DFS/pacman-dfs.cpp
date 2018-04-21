#include <bits/stdc++.h>

using namespace std;

pair<int,int> operator+(const pair<int, int>& x, const pair<int, int>& y) {
    return make_pair(x.first+y.first, x.second+y.second);
}

void dfs (int r,
  int c,
  pair<int, int> start,
  pair<int, int> end,
  vector<char> *grid,
  vector<pair<int, int>> & expandedNodes,
  vector<pair<int, int>> & path) {
    vector<pair<int, int>> tempPath;

    map<pair<int, int>, bool> visited;

    stack<pair<int, int>> s;
    s.push(start);

    stack<vector<pair<int, int>>> stackPath;
    stackPath.push(vector<pair<int, int>>());

    pair<int, int> neighbors[4] = {{-1, 0}, {0, -1},{0, 1},{1, 0}};

  while (!s.empty()) {
    pair<int, int> current = s.top();
    s.pop();

    vector<pair<int, int>> tmpPath = stackPath.top();
    stackPath.pop();

    tmpPath.push_back(current);

    visited.insert(make_pair(current, true));

    expandedNodes.push_back(current);

    if (current == end){
      if (path.size() == 0) {
        path = tmpPath;
        break;
      }
    }

    for (auto cn: neighbors) {
      pair<int, int> neighbor = {current + cn};

      if (neighbor.first < 0 || neighbor.first >= r || neighbor.second < 0 && neighbor.second >= r)
        continue;

      if (grid[neighbor.first][neighbor.second] == '-' || grid[neighbor.first][neighbor.second] == '.') {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          s.push(neighbor);
          stackPath.push(tmpPath);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int pr, pc;
  cin >> pr >> pc;

  pair<int, int> start = {pr, pc};

  int fr, fc;
  cin >> fr >> fc;

  int r, c;
  cin >> r >> c;

  pair<int, int> end = {fr, fc};

  vector<char> *pacManGrid = new vector<char>[c];
  for (int ri = 0 ; ri < r ; ++ri)
    for (int ci = 0 ; ci < c ; ++ci) {
      char node;
      cin >> node;
      pacManGrid[ri].push_back(node);
    }

    vector<pair<int, int>> expandedNodes;
    vector<pair<int, int>> path;
    dfs(r, c, start, end, pacManGrid, expandedNodes, path);

    cout << expandedNodes.size() << '\n';
    for (auto node: expandedNodes)
      cout << node.first << ' ' << node.second << '\n';

    cout << path.size() - 1 << '\n';
    for (auto node: path)
      cout << node.first << ' ' << node.second << '\n';

    /*for (int ri = 0 ; ri < r ; ++ri){
      for (int ci = 0 ; ci < c ; ++ci)
        cout << pacManGrid[ri][ci] << ' ';
      cout << '\n';
    }*/

    return 0;

}
