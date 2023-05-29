#include "testlib.h"
#include <iostream>
#include <random>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <numeric>


using namespace std;




int choose_multi(int mc) {
    if (rnd.next(0, 1)) {
        //small
        return rnd.next(1, min(10, mc / 4));
    } else {
        //big 
        return rnd.next(1, mc / 4);
    }
}

int choose_seg_gcd(int mc, int multi) {
    int can = mc / multi;
    assert(can >= 2);
    if (rnd.next(0, 1)) {
        //small
        return rnd.next(2, min(10, can));
    } else {
        //big
        return rnd.next(2, can);
    }
}


int choose_number(int mc, int g, int m) {
    int can = mc / g / m;
    assert(can >= 1);
    return rnd.next(1, can);
}


int main(int argc, char* argv[]) {


    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int MAXC = atoi(argv[2]);
    cout << n << '\n';
    if (n <= 1) {
        throw;
    }


    int multi = choose_multi(MAXC);
    int ones = rnd.next(1, min(n, 4));
    vector<int> inds(n);
    iota(inds.begin(), inds.end(), 0);
    shuffle(inds.begin(), inds.end());
    inds.resize(ones);
    inds.push_back(inds[0] + n);

    vector<int> a(n);
    for (int l = 0; l < ones; ++l) {
        int left = inds[l] + 1;
        int right = inds[l + 1];
        int g = choose_seg_gcd(MAXC, multi);
        for (int i = left; i < right; ++i) {
            a[i % n] = g * choose_number(MAXC, g, multi);
        }
    }

    for (int l = 0; l < ones; ++l) {
        a[inds[l]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        a[i] *= multi;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << '\n';
}
