#include "testlib.h"
#include <iostream>
#include <random>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <numeric>


using namespace std;


int main(int argc, char* argv[]) {


    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int MAXC = atoi(argv[2]);
    cout << n << '\n';
    if (n <= 1) {
        throw;
    }
    for (int i = 0; i < n; ++i) {
        cout << MAXC << (i == n - 1 ? "" : " ");
    }
    cout << '\n';
}
