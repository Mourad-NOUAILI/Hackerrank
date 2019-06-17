/*
Terminated due to timeout
O(alice_count x rank_list_size) -> quadratic
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> build_rank(vector<int> scores){
  vector<int> score_rank;
  int scores_size = scores.size();
  for (int i = 0 ; i < scores_size - 1 ; ++i)
    if (scores[i] != scores[i+1]) score_rank.push_back(scores[i]);
  score_rank.push_back(scores[scores_size-1]);
  return score_rank;
}

// Complete the climbingLeaderboard function below.
vector<int> climbing_leaderboard(vector<int> scores, vector<int> alice) {
  // (1): Compute initial rank
  vector<int> score_rank = build_rank(scores);

  // (2): For each alice's score compute her rank
  // Complexity: O(alice_count x rank_list_size)
  vector<int> result;
  int rank_size = score_rank.size();
  for (auto alice_score: alice){
    int j = 0;
    while (j < rank_size && alice_score < score_rank[j])
      j++;

    result.push_back(j + 1);
  }

  return result;
}


int main(){
    int scores_count;
    cin >> scores_count;


    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++)
      cin >> scores[i];


    int alice_count;
    cin >> alice_count;

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++)
      cin >> alice[i];


    vector<int> result = climbing_leaderboard(scores, alice);

   for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
