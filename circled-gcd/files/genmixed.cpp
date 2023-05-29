#include "testlib.h"
#include <iostream>
#include <random>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <numeric>


using namespace std;

int MAXC;

vector<int> fibs;

void init_fibs() {
    fibs = {1, 1};
    int sz = 2;
    while (fibs[sz - 1] + fibs[sz - 2] <= MAXC) {
        fibs.push_back(fibs[sz - 1] + fibs[sz - 2]);
        ++sz;
    }
}

struct Sieve {
    vector<int> primes;
    vector<int> ldiv;
    Sieve(int C) {
        ldiv.resize(C + 1, -1);
        primes.reserve(C / 10 + 30);
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
};



int main(int argc, char* argv[]) {


    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    MAXC = atoi(argv[2]);
    init_fibs();
    Sieve sv(MAXC);


    cout << n << '\n';
    if (n <= 1) {
        throw;
    }
    for (int i = 0; i < n; ++i) {
        int g = rnd.next(1, 3);
        int res;
        if (g == 1) {
            res = sv.primes[rnd.next(sv.primes.size())];
        } else if (g == 2) {
            res = fibs[rnd.next(fibs.size())];
        } else {
            res = rnd.next(1, MAXC);
        }
        cout << res << (i == n - 1 ? "" : " ");
    }
    cout << '\n';
}
