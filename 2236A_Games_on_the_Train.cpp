#include <iostream>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    int min_val = 1e9;
    int max_val = -1e9;
    
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        min_val = min(min_val, h);
        max_val = max(max_val, h);
    }
    
    // Minimum k is (max_h + 1) - min_h
    cout << max_val - min_val + 1 << "\n";
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