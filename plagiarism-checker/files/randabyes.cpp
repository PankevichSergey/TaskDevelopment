#include "testlib.h"
#include <iostream>
#include <random>
#include <unordered_map>


using namespace std;

vector<char> allowed;


void init_allowed() {
    for (char c = 'a'; c <= 'b'; ++c) {
        allowed.push_back(c);
    }
}

mt19937 rng(228);

string gen(int n) {
    string res;
    for (int i = 0; i < n; ++i) {
        res += allowed[rnd.next(0, (int)allowed.size() - 1)];
    }
    return res;
}


int main(int argc, char* argv[]) {

    init_allowed();

    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    cout << n << '\n';

    while (true) {
        string a = gen(n);
        string b = gen(n);
        cout << a << '\n';
        cout << b << '\n';
        return 0;
    }
}
