#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(v) ((int)(v).size())
#define all(a) (a).begin(),  (a).end()
#define rall(a) a.rbegin(), a.rend()
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define time ((double)clock() / (double)CLOCKS_PER_SEC)

using pii = pair<int, int>;
using ll = long long;
using int64 = long long;
using ld = double;

const ll infll = (ll) 1e18 + 27;
const ll inf = (ll) 1e9;

#define dbg(x) cout << #x << " = " << (x) << endl

template<class T>
using pq = priority_queue<T, vector<T>, less<T>>;
template<class T>
using pqr = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename T2>
istream &operator>>(istream &in, pair<T, T2> &b) {
    in >> b.first >> b.second;
    return in;
}

template<typename T, typename T2>
ostream &operator<<(ostream &out, const pair<T, T2> &b) {
    out << "{" << b.first << ", " << b.second << "}";
    return out;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &b) {
    for (auto &v : b) {
        in >> v;
    }
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &b) {
    for (auto &v : b) {
        out << v << ' ';
    }
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, deque<T> &b) {
    for (auto &v : b) {
        out << v << ' ';
    }
    return out;
}

template<typename T>
void print(T x, string end = "\n") {
    cout << x << end;
}


template<typename T1, typename T2>
bool chkmin(T1 &x, const T2 &y) { return x > y && (x = y, true); }

template<typename T1, typename T2>
bool chkmax(T1 &x, const T2 &y) { return x < y && (x = y, true); }

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1010;

void solve() {
    int n;
    cin >> n;
	string a, b;
    cin >> a >> b;
    vector<set<char>> change(N);
    for (int i = 0; i < sz(a); i++) {
        if (a[i] == b[i]) continue;
        change[a[i]].insert(b[i]);
    }
    bool All = true;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (sz(change[i])) {
            All = false;
            cnt++;
            if (sz(change[i]) > 1) {
                cout << "NO\n";
                return;
            }
        }
    }
    // if (All) {
        // cout << "NO\n";
        // return;
    // }
    cout << "YES\n";
    cout << cnt << '\n';
    for (int i = 0; i < N; i++) {
        if (sz(change[i])) {
            cout << char(i) << " " << *change[i].begin() << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(15);
    int32_t test = 1;
    // cin >> test;
    while (test--)
        solve();
    return 0;
}
