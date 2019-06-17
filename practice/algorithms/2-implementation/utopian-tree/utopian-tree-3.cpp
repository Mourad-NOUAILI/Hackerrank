#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int fastexp(int a,int n){
    if (n==1) return a;
    if (n%2==0) return (fastexp(a,n/2)*fastexp(a,n/2));
    else return (a*fastexp(a,(n-1)/2)*fastexp(a,(n-1)/2));
}
int main() {
    int t;
    int n,i;
    scanf("%d",&t);
    for (i=0;i<t;i++) {
        scanf("%d",&n);
        printf("%d\n",fastexp(2,(n+1)/2+1)-1-(n%2));
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
