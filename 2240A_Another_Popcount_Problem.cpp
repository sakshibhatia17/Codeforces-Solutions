#include <iostream>
#include <algorithm>
 
using namespace std;
 
void solve() {
    long long n, k;
    cin >> n >> k;
    
    long long ans = 0;
    long long p = 1;
    
    // Greedily pick the smallest powers of 2
    while (n >= p) {
        long long take = min(k, n / p);
        ans += take;
        n -= take * p;
        p *= 2;
    }
    
    cout << ans << "\n";
}
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}