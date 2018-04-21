#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vii;
typedef pair<int, int> pii;

class puzzle {
  public:
    vii grid;
    int x_empty_tile;
    int y_empty_tile;
    int step_from_start;
    int misplaced_tiles;
    int coast;
    string move;

  public:
    puzzle(vii grid,
          int x_empty_tile,
          int y_empty_tile,
          int step_from_start,
          int misplaced_tiles,
          int coast,
          string move) {

      this->grid = grid;
      this->x_empty_tile = x_empty_tile;
      this->y_empty_tile = y_empty_tile;
      this->step_from_start = step_from_start;
      this->misplaced_tiles = misplaced_tiles;
      this->coast = coast;
      this->move = move;
  }
};

typedef pair<int, puzzle*> pqt;

int heuristic(int k, vii p1, vii p2){
  int h = 0;
  int tile = 0;
  for (int i = 0 ; i < k ; ++i){
      for (int j = 0 ; j < k ; ++j){
        if (p1[i][j] != tile) h++;
        tile++;
      }
  }
  return h;
}

//Compute the number of all moved puzzle using A*
void a_star(int k, puzzle *start, puzzle *goal, map<vii, pair<vii, string>> & pi){

  priority_queue<pqt, vector<pqt>, greater<pqt>> q;
  q.push({start->coast, start});

  map<vii, bool> visited;

  while (!q.empty()){
    puzzle *current_puzzle = q.top().second;
    q.pop();

    vii current_grid = current_puzzle->grid;

    if (visited[current_grid]) continue;
    visited[current_grid] = true;

    if (current_puzzle->misplaced_tiles == 0) break;

    //Do the four moves (when is possible)
    map<pii, string> moves;
    moves.insert({{-1, 0}, "UP"});
    moves.insert({{0, -1}, "LEFT"});
    moves.insert({{0, 1}, "RIGHT"});
    moves.insert({{1, 0}, "DOWN"});

    for (auto move: moves){
      int x = current_puzzle->x_empty_tile + move.first.first;
      int y = current_puzzle->y_empty_tile + move.first.second;

      if ( x < 0 || x >= k || y < 0 || y >= k) continue;

      vii next_grid = current_grid;
      int tmp = next_grid[x][y];
      next_grid[x][y] = 0;
      next_grid[current_puzzle->x_empty_tile][current_puzzle->y_empty_tile] = tmp;

      if (!visited[next_grid]){
        int f = current_puzzle->step_from_start + 1;
        int h = heuristic(k, next_grid, goal->grid);
        int coast = f + h;

        puzzle *next_puzzle = new puzzle(next_grid, x, y, f, h, coast, move.second);

        pi[next_grid] = {current_grid, move.second};

        q.push({coast, next_puzzle});
      }

    }
  }
}

void display_grid(int k, vii grid){
  for (int i = 0 ; i < k ; ++i){
    for (auto tile: grid[i])
      cout << tile << ' ';
    cout << '\n';
  }
}

void rebuild_path(int k, map<vii, pair<vii, string>> pi, vii start_grid, vii goal_grid, vector<string> & path){
  if (!pi.empty()) {
    vii p = pi[goal_grid].first;
    path.push_back(pi[goal_grid].second);
    path.push_back(pi[p].second);
    while (p != start_grid){
      p = pi[p].first;
      if (!pi[p].second.empty())
        path.push_back(pi[p].second);
    }
  }
}

//TODO: check if N-puzzle is solvable.
bool is_solvable(int k, vector<int> arr){
  int less = 0;
  for (int i = 0 ; i < k * k ; ++i){
    for(int j = i + 1 ; j < k * k ; ++j ){
      if (arr[j] != 0 && arr[j] < arr[i]) less++;
    }
  }

  return less % 2 == 0;
}

int main() {
  ios::basic_ios::sync_with_stdio(false);
  int k;
  cin >> k;

  vii goal_p (k, vector<int> (k));
  int tile = 0;
  for (int i = 0 ; i < k ; ++i){
    for (int j = 0 ; j < k ; ++j) {
      goal_p[i][j] = tile++;
    }
  }
  puzzle *goal_puzzle = new puzzle(goal_p, 0, 0, 0, 0, 0, "NONE");

  vii start_p (k, vector<int> (k));
  vector<int> arr;
  int x_empty_tile = 0, y_empty_tile = 0;
  for (int i = 0 ; i < k ; ++i){
    for (int j = 0 ; j < k ; ++j) {
      int tile;
      cin >> tile;
      if (tile == 0){
        x_empty_tile = i;
        y_empty_tile = j;
      }
      else
        arr.push_back(tile);

      start_p [i][j] = tile;
    }
  }

  if (!is_solvable(k, arr)) {
    cout << "0\n";
    return 0;
  }
  //else return 0;


  int h0 = heuristic(k, start_p, goal_p);
  puzzle *start_puzzle = new puzzle(start_p, x_empty_tile, y_empty_tile, 0, h0, 0 + h0, "NONE");

  map<vii, pair<vii, string>> pi;
  a_star(k, start_puzzle, goal_puzzle, pi);

  vector<string> path;
  rebuild_path(k, pi, start_puzzle->grid, goal_puzzle->grid, path);

  cout << path.size() << '\n';
  if (!path.empty())
    for (auto it = path.crbegin() ; it != path.crend() ; ++it)
      cout << *it << '\n';

  return 0;
}
