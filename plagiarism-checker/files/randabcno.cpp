#include "testlib.h"
#include <iostream>
#include <random>
#include <unordered_map>


using namespace std;

vector<char> allowed;


void init_allowed() {
    for (char c = 'a'; c <= 'c'; ++c) {
        allowed.push_back(c);
    }
}


bool checkyes(string a, string b) {
    unordered_map<char, char> p;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            auto it = p.find(a[i]);
            if (it == p.end()) {
                p[a[i]] = b[i];
            } else {
                if (it->second != b[i]) {
                    return false;
                }
            }
        }
    }
    return true;
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
    if (n == 1) {
        throw;
    }
    while (true) {
        string a = gen(n);
        string b = gen(n);
        if (!checkyes(a, b)) {
            cout << a << '\n';
            cout << b << '\n';
            return 0;
        }
    }
}
