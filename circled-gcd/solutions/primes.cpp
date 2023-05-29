#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// floating point errors
// #pragma GCC optimize("Ofast,unroll-loops")

// safe
// #pragma GCC optimize("O3,unroll-loops")

// doesn't work in yandex
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// doesn't work in some judges
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,tune=native")

// safe
// #pragma GCC target("sse4.2,bmi,bmi2,lzcnt,popcnt")

template <typename T1, typename T2>
inline void mine(T1 &x, const T2 &y) {
    if (y < x)
        x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, const T2 &y) {
    if (x < y)
        x = y;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &b) {
    os << b.first << ' ' << b.second;
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &b) {
    for (const auto &k : b)
        os << k << ' ';
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &b) {
    for (auto &k : b)
        is >> k;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &b) {
    for (const auto &k : b)
        os << k << ' ';
    return os;
}

void dbg_out() {
    cerr << endl;
}

template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << "   " << H;
    dbg_out(T...);
}

#ifdef LOCAL_SERGEY
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define pb push_back
#define eb emplace_back
#define ppb pop_back()
#define mp make_pair
#define fx(x, a) for (auto &x : a)
#define siz(x) (long long)x.size()
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define left leftkekmda
#define right rightkekmda

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
using str = string;

template <typename T>
using V = vector<T>;

using vi = V<int>;
using vl = V<ll>;
using vch = V<char>;
using vpii = V<pii>;
using vvpii = V<V<pii>>;
using vpll = V<pll>;
using vvpll = V<V<pll>>;
using vvi = V<vi>;
using vvl = V<vl>;
using vvch = V<vch>;

template <typename T>
int Bit(T x, int sh) {
    return (x >> sh) & 1;
}
template <typename T>
int Bits(T x) {
    return __builtin_popcountll(x);
}
template <typename T>
int MinBit(T x) {
    return __builtin_ctzll(x);
}
template <typename T>
int MaxBit(T x) {
    return 63 - __builtin_clzll(x);
}

ll div_up(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}
ll div_down(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


const int C = 1e6 + 10;

struct Sieve {
    vector<int> primes;
    int ldiv[C];
    Sieve() {
        primes.reserve(C / 10 + 30);
        memset(ldiv, -1, sizeof(int) * C);
        for (int i = 2; i < C; ++i) {
            if (ldiv[i] == -1) {
                primes.push_back(i);
                ldiv[i] = i;
            }
            for (auto x : primes) {
                if (1ll * x * i >= C || x > ldiv[i]) {
                    break;
                }
                ldiv[i * x] = x;
            }
        }
    }
}sv;



void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int g = a[0];
    for (int i = 1; i < n; ++i) {
        g = gcd(a[i], g);
    }
    for (int i = 0; i < n; ++i) {
        a[i] /= g;
    }
    map<int, vector<int>> where;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int p : sv.primes) {
            if (1ll * p * p > x) break;
            if (x % p == 0) {
                where[p].push_back(i);
            }
            while (x % p == 0) {
                x /= p;
            }
        }
        if (x > 1) {
            where[x].push_back(i);
        }
    }
    int ans = 0;
    for (auto[p, pos] : where) {
        int sz = pos.size();
        for (int i = 0; i < sz; ++i) {
            pos.push_back(pos[i] + n);
        }
        int i = 0;
        while (i < pos.size()) {
            int j = i;
            while (j < pos.size() && pos[j] - pos[i] == j - i) {
                ++j;
            }
            maxe(ans, j - i);
            i = j;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int test_ = 1;
    // cin >> test_;
    while (test_--)
        solve();
}
