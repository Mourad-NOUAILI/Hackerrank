/*
Terminated due to timeout
O(alice_count²) -> quadratic
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> compute_initial_rank(vector<int> scores){
  vector<int> score_rank;
  int scores_size = scores.size();
  for (int i = 0 ; i < scores_size - 1 ; ++i)
    if (scores[i] != scores[i+1]) score_rank.push_back(scores[i]);
  score_rank.push_back(scores[scores_size-1]);
  return score_rank;
}

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
  // (1): Compute initial rank
  vector<int> score_rank = compute_initial_rank(scores);

  /*int r = 1;
  for (auto p: score_rank) {
    cout << p <<'/'<< r++ << '\n';
  }*/

  // (2): For each alice's score compute her rank
  // Complexity: O(alice_count²)
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

   for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
