#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    // L and R represent the valid range [L, R] for the number of active even-started intervals
    long long L = 0, R = 0;
    long long prev_target = 0;
    bool possible = true;
    
    for (int i = 1; i <= n; ++i) {
        long long diff = a[i - 1] - b[i - 1];
        // Apply the alternating sign transformation
        long long target = (i % 2 == 1) ? -diff : diff;
        
        if (i % 2 == 1) { // i is odd
            L = max(0LL, -target);
            // R remains the same because odd indices can start an arbitrary 
            // number of odd intervals, removing upper bounds on even ones.
        } else { // i is even
            L = max(0LL, -target);
            R = prev_target - target + R;
        }
        
        // If the lower bound exceeds the upper bound, it's impossible
        if (L > R) {
            possible = false;
        }
        
        prev_target = target;
    }
    
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}