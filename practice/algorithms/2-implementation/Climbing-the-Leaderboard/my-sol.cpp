/*
Successful
O(alice_count * log rank_size)
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
  // (1): Build the rank
  vector<int> score_rank = build_rank(scores);

  // (2): For each alice's score compute her rank:
      // By searching the last value in the rank array, which is greater or eqaul to the alice's score.
      // To do that: we use:
            // upper_bound function (http://www.cplusplus.com/reference/algorithm/upper_bound/)
            //  greater_equal<int>() binary function object class (http://www.cplusplus.com/reference/functional/greater_equal/)
  // Complexity: O(alice_count * log rank_size)
  vector<int> result;
  int rank_size = score_rank.size();
  for (auto alice_score: alice)
    result.push_back(upper_bound(score_rank.begin(),score_rank.end(),alice_score, greater_equal<int>()) - score_rank.begin() + 1);


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
