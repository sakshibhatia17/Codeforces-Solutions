#include <iostream>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    long long total_triples = 0;
    
    // Iterate through all possible values of the middle element 'b'
    for (int b = 1; b <= n; ++b) {
        long long multiples = n / b;
        total_triples += multiples * multiples;
    }
    
    cout << total_triples << "\n";
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