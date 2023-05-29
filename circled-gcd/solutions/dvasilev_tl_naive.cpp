#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int it = 0; 1; ++it) {
        vector<int> b(n);
        bool eq = true;
        for (int i = 0; i < n; ++i) {
            eq &= a[i] == a[0];
            b[i] = gcd(a[i], a[(i + 1) % n]);
        }
        if (eq) {
            cout << it << endl;
            return;
        }
        a = b;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int t = 1;
    // cin >> t;

    for (int test = 1; test <= t; ++test) {
        solve();
    }
    return 0;
}
