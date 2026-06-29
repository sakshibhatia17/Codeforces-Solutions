#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    long long c;
    cin >> n >> c;
    
    vector<int> a(n);
    vector<int> b(n);
    
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    
    long long sum_b = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }
    
    // Check Option 1: No reordering
    bool possible_no_reorder = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            possible_no_reorder = false;
            break;
        }
    }
    
    if (possible_no_reorder) {
        cout << sum_a - sum_b << "\n";
        return;
    }
    
    // Check Option 2: With reordering
    vector<int> sorted_a = a;
    vector<int> sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    
    bool possible_reorder = true;
    for (int i = 0; i < n; ++i) {
        if (sorted_a[i] < sorted_b[i]) {
            possible_reorder = false;
            break;
        }
    }
    
    if (possible_reorder) {
        cout << c + (sum_a - sum_b) << "\n";
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