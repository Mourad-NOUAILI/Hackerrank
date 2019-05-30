/*
Calculate the number of inversion using a BST.
Complexity: O(t * N * log N)
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    int inv_count;
    Node *left, *right;
};

Node* new_node( int data )  {
    Node* temp = new Node();
    temp->data = data;
    temp->inv_count = 0;
    temp->left = temp->right = NULL;
    return temp;
}

vector<string> split_string(string);

/*Node* build_bst(vector<int> A) {
  Node *root = new_node(A[0]);
  int n = A.size();
  for (int i = 1 ; i < n ; ++i) {
    Node *node = new_node(A[i]);
    Node *parent = NULL, *current = root;
    while (current != NULL) {
      parent = current;
      if (current->data <= A[i])
        current = current->right;
      else
        current = current->left;
    }

    if (parent->data <= A[i])
      parent->right = node;
    else {
      parent->left = node;
    }

  }

  return root;
}*/


/*Node* build_bst(vector<int> A) {
  stack<Node*> s;
  Node *root = new_node(A[0]);
  s.push(root);
  int n = A.size();
  for (int i = 1 ; i < n ; ++i) {
    Node *temp = NULL;
    while (!s.empty() && A[i] > s.top()->data) {
      temp = s.top();
      s.pop();
    }

    if (temp != NULL) {
      temp->right = new_node(A[i]);
      s.push(temp->right);
    }
    else {
      s.top()->left = new_node(A[i]);
      s.push(s.top()->left);
    }

  }

  return root;
}*/

Node* insert(Node *node, int data){
  if (node == NULL) return new_node(data);

  if (data < node->data) {
    node->left = insert(node->left, data);
    node->inv_count++;
  }
  else
    node->right = insert(node->right, data);

  return node;
}

Node* build_bst(vector<int> A) {
  Node *root = NULL;
  root = insert(root, A[0]);
  int n = A.size();
  for (int i = 1 ; i < n ; ++i)
    insert(root, A[i]);
  return root;
}

void printInorder (Node* node)
{
    if (node == NULL)
        return;
    cout<<node->data<< "/" << node->inv_count << " ";
    printInorder(node->left);
    printInorder(node->right);
}

int number_of_inversions(Node *root) {
  if (root == NULL)
      return 0;
  return number_of_inversions(root->left) + number_of_inversions(root->right) + root->inv_count;
}

// Complete the larrysArray function below.
string larrysArray(Node *root) {
  int inv_count = number_of_inversions(root);

  return (inv_count % 2 == 0) ? "YES" : "NO";
}

int main(){

  /*vector<int> pre = {1, 3, 4, 2};

    Node *root = build_bst(pre);

    cout<<"Inorder traversal of the constructed tree: \n";
    printInorder(root);
    cout << '\n';
    cout << number_of_inversions(root)<< '\n';*/
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        cout << result << "\n";
    }

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
