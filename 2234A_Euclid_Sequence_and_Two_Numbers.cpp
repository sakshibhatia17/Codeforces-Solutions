#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    // Sort the sequence in descending order
    sort(b.rbegin(), b.rend());
    
    // Verify the Euclid sequence condition
    bool isValid = true;
    for (int i = 0; i < n - 2; i++) {
        if (b[i] % b[i+1] != b[i+2]) {
            isValid = false;
            break;
        }
    }
    
    // Output result
    if (isValid) {
        cout << b[0] << " " << b[1] << "\n";
    } else {
        cout << -1 << "\n";
    }
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