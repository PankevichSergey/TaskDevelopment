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
        int res = fibs[sz - 1] + fibs[sz - 2];
        fibs.push_back(res);
        ++sz;
    }
}

int main(int argc, char* argv[]) {

    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    MAXC = atoi(argv[2]);
    init_fibs();


    cout << n << '\n';
    if (n <= 1) {
        throw;
    }
    for (int i = 0; i < n; ++i) {
        cout << fibs[rnd.next(fibs.size())] << (i == n - 1 ? "" : " ");
    }
    cout << '\n';
}
