#include <bits/stdc++.h>

using namespace std;

pair<int,int> operator+(const pair<int, int>& x, const pair<int, int>& y) {
    return make_pair(x.first+y.first, x.second+y.second);
}

void ucs (int r,
  int c,
  pair<int, int> start,
  pair<int, int> end,
  vector<char> *grid,
  vector<pair<int, int>> & expandedNodes,
  vector<pair<int, int>> & path) {
    vector<pair<int, int>> tempPath;

    map<pair<int, int>, bool> visited;

    queue<pair<int, int>> q;

    q.push(start);

    queue<vector<pair<int, int>>> queuePath;
    queuePath.push(vector<pair<int, int>>());

    pair<int, int> neighbors[4] = {{-1, 0}, {0, -1},{0, 1},{1, 0}};

  while (!q.empty()) {
    pair<int, int> current = q.front();
    q.pop();

    vector<pair<int, int>> tmpPath = queuePath.front();
    queuePath.pop();

    tmpPath.push_back(current);

    visited.insert(make_pair(current, true));

    expandedNodes.push_back(current);

    if (current == end){
      if (path.size() == 0) {
        path = tmpPath;
        break;
      }
    }

    vector<pair<pair<int, int>, int>> possibleMoves;
    for (auto cn: neighbors) {
      pair<int, int> neighbor = {current + cn};

      if (neighbor.first < 0 || neighbor.first >= r || neighbor.second < 0 && neighbor.second >= r)
        continue;

      if (grid[neighbor.first][neighbor.second] == '-' || grid[neighbor.first][neighbor.second] == '.') {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          if (grid[neighbor.first][neighbor.second] == '.')
            possibleMoves.push_back({neighbor, 0});
          else
            possibleMoves.push_back({neighbor, 1});
        }
      }
    }

    sort(possibleMoves.begin(), possibleMoves.end(),
      [](const pair<pair<int, int>,int> &left, const pair<pair<int, int>,int> &right) {
        return left.second < right.second;
      });
    for(auto move: possibleMoves) {
      q.push(move.first);
      queuePath.push(tmpPath);
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
    ucs(r, c, start, end, pacManGrid, expandedNodes, path);

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
