#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int g = a[0];
    for (int i = 1; i < n; ++i) {
        g = gcd(a[i], g);
    }
    for (int i = 0; i < n; ++i) {
        a[i] /= g;
    }
    int cnt_1 = 0;
    for (int i = 0; i < n; ++i) {
        cnt_1 += a[i] == 1;
    }

    vector<int> to_check;
    for (int i = 0; i < n; ++i) {
        to_check.push_back(i);
    }
    vector<int> b(n);
    for (int it = 0; 1; ++it) {
        if (cnt_1 == n) {
            cout << it << endl;
            return;
        }
        vector<int> nxt_to_check;
        for (int i : to_check) {
            b[i] = gcd(a[i], a[(i + 1) % n]);
            if (a[i] != b[i]) {
                nxt_to_check.push_back(i);
                nxt_to_check.push_back((i + n - 1) % n);
                if (b[i] == 1) {
                    ++cnt_1;
                }
            }
        }
        for (int i : to_check) {
            a[i] = b[i];
        }
        to_check = nxt_to_check;
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
