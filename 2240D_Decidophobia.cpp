#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    long long d;
    cin >> n >> d;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    // Step 1: Initialize sliding window for the 0th person.
    // The window covers from index -d to +d.
    long long current_window_sum = 0;
    for (long long j = -d; j <= d; ++j) {
        // Safe modulo for negative indices
        current_window_sum += a[(j % n + n) % n];
    }
 
    long long max_total_happiness = 0;
 
    // Step 2: Calculate contribution for each person and slide the window
    for (int i = 0; i < n; ++i) {
        // S_i is sum of field of view (exclude the person themselves)
        long long S_i = current_window_sum - a[i];
        
        // C_i is the net happiness contribution if we give a gift to person i
        long long C_i = 2 * d * a[i] - S_i;
        
        // If contribution is positive, greedily take it
        if (C_i > 0) {
            max_total_happiness += C_i;
        }
        
        // Step 3: Slide the window for the next person (i + 1)
        if (i < n - 1) {
            // Remove the left-most element of the current window
            current_window_sum -= a[((i - d) % n + n) % n];
            // Add the right-most element for the next window
            current_window_sum += a[(i + 1 + d) % n];
        }
    }
 
    cout << max_total_happiness << "\n";
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