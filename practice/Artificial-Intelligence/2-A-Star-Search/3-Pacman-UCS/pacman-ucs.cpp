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
            list<pair<int, int>> & path) {

  map<pair<int, int>, pair<int, int>> pi;
  map<pair<int, int>, bool> visited;

  priority_queue<pair<int, pair<int, int>>,
                  vector<pair<int, pair<int, int>>>,
                  greater<pair<int, pair<int, int>>>> q;

  q.push({0, start});

  pair<int, int> neighbors[4] = {{-1, 0}, {0, -1},{0, 1},{1, 0}};

  while (!q.empty()) {
    pair<int, pair<int, int>> p = q.top();
    q.pop();

    pair<int ,int> current = p.second;
    int d_current = p.first;

    visited.insert(make_pair(current, true));

    if (current == end)
      break;

    for (auto cn: neighbors) {
      pair<int, int> neighbor = {current + cn};

      if (neighbor.first < 0 || neighbor.first >= r || neighbor.second < 0 && neighbor.second >= r)
        continue;

      if (grid[neighbor.first][neighbor.second] == '-' || grid[neighbor.first][neighbor.second] == '.') {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push({d_current + 1, neighbor});
          pi[neighbor] = current;
        }
      }
    }
  }

  //Buid the shortest path
  pair<int, int> node = end;
  while (true) {
    if (node == start) {
      path.push_front(start);
      break;
    }
    path.push_front(node);
    node = pi[node];
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


    list<pair<int, int>> path;
    map<pair<int, int>, pair<int, int>> pi;

    ucs(r, c, start, end, pacManGrid, path);

    cout << path.size() - 1 << '\n';
    for (auto node: path)
      cout << node.first << ' ' << node.second << '\n';

    return 0;

}
