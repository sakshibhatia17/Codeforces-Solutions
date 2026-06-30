#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long x;
        scanf("%lld", &x);
 
        // count digits of x
        int d = 0;
        long long tmp = x;
        while(tmp > 0){ d++; tmp /= 10; }
 
        long long p = 1;
        for(int i = 0; i < d; i++) p *= 10;
 
        long long y = p + 1; // e.g. d=1 -> 11, d=2 -> 101, etc.
 
        printf("%lld\n", y);
    }
    return 0;
}