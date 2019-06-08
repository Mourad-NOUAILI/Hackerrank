#include <bits/stdc++.h>

using namespace std;


double compute_distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
}

void manage_obstacles(int x, int y, int xo, int yo, int i, vector<pair<bool, pair<int, int>>> & nearest_obstacle){

  double d_qo = compute_distance(x, y, xo, yo);
  double d_q_no = compute_distance(nearest_obstacle[i].second.first, nearest_obstacle[i].second.second, xo, yo);
  if (d_qo < d_q_no) {
    nearest_obstacle[i].first = true;
    nearest_obstacle[i].second = {xo, yo};
  }
}

int queens_attack(int n, int k, int x, int y, vector<pair<int, int>> obstacles) {
  // ***********************1- Compute the points' coordinates of all segemnts*************************************************************

  // --Segment EF---------------
  // Point E
  int xe = x;
  int ye = n;

  // Point F
  int xf = x;
  int yf = 0;
  // ---------------------------

  //--Segment GH---------------
  // Point G
  int xg = 0;
  int yg = y;

  // Point H
  int xh = n;
  int yh = y;
  // ---------------------------

  // --Segment AB (diagonal)----
  // Compute equation for AB ( y = ax + b )
  int a_ab = 1;
  int b_ab = y - x;

  // Point A
  int xa = 0;
  int ya = b_ab;
  if (ya < 0) {
    ya = 0;
    xa = -b_ab/a_ab;
  }

  // Point B
  int xb = n;
  int yb = a_ab * xb + b_ab;
  if (yb > n) {
    yb = n;
    xb = (yb-b_ab) / a_ab;
  }
  // ---------------------------


  // --------Segment CD (diagonal)----
  // Compute equation for CD ( y = ax + b )
  int a_cd = -1;
  int b_cd = y + x;

  // Point C
  int yc = n;
  int xc = (yc-b_cd) / a_cd;
  if (xc < 0) {
    xc = 0;
    yc = b_cd;
  }
  if (xc > n) {
    xc = n;
    yc = a_cd * xc + b_cd;
  }

  // Point D
  int yd = 0;
  int xd = b_cd;
  if (xd > n) {
    xd = n;
    yd = a_cd * xd + b_cd;
  }


  // ---------------------------
  // *******************************************************************************************************************************************

  // *************************2- For k = 0, Compute number of squares that the queen can attack from position (rq, cq)**************************
  int ans = abs(ye-yf) + abs(xg-xh) + abs(xc-xd) + abs(xa-xb);
  // *******************************************************************************************************************************************


  // *************************3- For each obstacle: ********************************************************************************************
  // ******************************* - Determine in which segment is it*************************************************************************
  // ******************************* - Determne in which part of the segment is it**************************************************************
  // ******************************* - In each segment, compute the nearest obstacle to the queen***********************************************
  vector<pair<bool, pair<int, int>>> nearest_obstacle(8, make_pair(false, make_pair(1E+9, 1E+9)));
  for (int i = 0 ; i < k ; ++i){
    int xo = obstacles[i].first;
    int yo = obstacles[i].second;

    // obstacle on EF (same x)
    if (xo == xe) {
      // E side
      if (yo > y)
        manage_obstacles(x, y, xo, yo, 0, nearest_obstacle);
      // F side
      else
        manage_obstacles(x, y, xo, yo, 1, nearest_obstacle);
    }

    // obstacles on GH (same y)
    if (yo == yg) {
      // H side
      if (xo > x)
        manage_obstacles(x, y, xo, yo, 3, nearest_obstacle);
      // G side
      else
        manage_obstacles(x, y, xo, yo, 2, nearest_obstacle);
    }

    // obstacles on AB
    int x_tmp = (yo - b_ab) / a_ab;
    if (x_tmp == xo) {
      // B side
      if (yo > y)
        manage_obstacles(x, y, xo, yo, 5, nearest_obstacle);
      // A side
      else
        manage_obstacles(x, y, xo, yo, 4, nearest_obstacle);
    }

    // obstacles on CD
    x_tmp = (yo - b_cd) / a_cd;
    if (x_tmp == xo) {
      // C side
      if (yo > y)
        manage_obstacles(x, y, xo, yo, 6, nearest_obstacle);
        // D side
      else
        manage_obstacles(x, y, xo, yo, 7, nearest_obstacle);
    }
  }

  // Reduce from the number of squares the number of non reachable squares
  if (nearest_obstacle[0].first) ans -= (abs(ye-nearest_obstacle[0].second.second) + 1);
  if (nearest_obstacle[1].first) ans -= (abs(yf-nearest_obstacle[1].second.second) + 1);
  if (nearest_obstacle[2].first) ans -= (abs(xg-nearest_obstacle[2].second.first) + 1);
  if (nearest_obstacle[3].first) ans -= (abs(xh-nearest_obstacle[3].second.first) + 1);
  if (nearest_obstacle[4].first) ans -= (abs(xa-nearest_obstacle[4].second.first) + 1);
  if (nearest_obstacle[5].first) ans -= (abs(xb-nearest_obstacle[5].second.first) + 1);
  if (nearest_obstacle[6].first) ans -= (abs(xc-nearest_obstacle[6].second.first) + 1);
  if (nearest_obstacle[7].first) ans -= (abs(xd-nearest_obstacle[7].second.first) + 1);

  return ans;
}

int main(){
  int n, k;
  cin >> n >> k;

  int rq, cq;
  cin >> rq >> cq;

  int x = --rq;
  int y = --cq;
  n--;


  vector<pair<int, int>> obstacles;
  for (int i = 0; i < k; i++) {
    int ro, co;
    cin >> ro >> co;
    ro--;
    co--;
    obstacles.push_back({ro, co});
  }

  int result = queens_attack(n, k, x, y, obstacles);

  cout << result << "\n";

  return 0;
}
