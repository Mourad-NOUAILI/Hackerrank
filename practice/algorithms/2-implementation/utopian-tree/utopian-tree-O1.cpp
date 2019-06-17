#include <iostream>
using namespace std;

int height(int n) {
    return ~(~1<<(n>>1))<<(n&1);
}
int main() {
    int T;
    cout << ~60 <<'\n';
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
