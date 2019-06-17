#include <bits/stdc++.h>

using namespace std;
int main() {
    int s,t,a,b,d,m,n;
    cin >>s>>t;
    cin >>a>>b;
    cin >>m>>n;
    
    int apple = 0;
    for (int i = 1 ; i <= m ; ++i) {
        int d;
        cin >>d;
        if (a+d >=s && a+d <=t) 
            apple++;
    }
    
    int orange = 0;
    for (int i = 1 ; i <= n ; ++i) {
        int d;
        cin >>d;
        if (b+d >=s && b+d <=t) 
            orange++;
    }
    
    cout <<apple<<'\n';
    cout <<orange<<'\n';
    
    return 0;
}
