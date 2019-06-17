/*
Successful
O(alice_count * log alice_count)
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> build_rank(vector<int> scores){
  vector<int> score_rank;
  int scores_size = scores.size();
  for (int i = 0 ; i < scores_size - 1 ; ++i)
    if (scores[i] != scores[i+1]) score_rank.push_back(scores[i]);
  score_rank.push_back(scores[scores_size-1]);
  return score_rank;
}

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
  // (1): Build the rank
  vector<int> score_rank = build_rank(scores);

  // (2): For each alice's score compute her rank:
      // By searching the last value in the rank array, which is greater or eqaul to the alice's score.
      // To do that: we use:
            // upper_bound function (http://www.cplusplus.com/reference/algorithm/upper_bound/)
            //  greater_equal<int>() binary function object class (http://www.cplusplus.com/reference/functional/greater_equal/)
  // Complexity: O(alice_count * log alice_count)
  vector<int> result;
  int rank_size = score_rank.size();
  for (auto alice_score: alice)
    result.push_back(upper_bound(score_rank.begin(),score_rank.end(),alice_score, greater_equal<int>()) - score_rank.begin() + 1);


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
