#include "testlib.h"
#include <iostream>
#include <random>
#include <unordered_map>


using namespace std;

vector<char> allowed;


void init_allowed() {
    for (char c = 0; c < 127; ++c) {
        if (c >= 'a' && c <= 'z') allowed.push_back(c);
        if (c >= 'A' && c <= 'Z') allowed.push_back(c);
        if (c >= '0' && c <= '9') allowed.push_back(c);
        if (c == '(' || c == ')') allowed.push_back(c);
        if (c == '{' || c == '}') allowed.push_back(c);
        if (c == '[' || c == ']') allowed.push_back(c);
        if (c == '<' || c == '>' || c == '=') allowed.push_back(c);
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == ';') allowed.push_back(c);
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

    string a = gen(n);
    unordered_map<char, char> p;
    for (char c : allowed) {
        if (rnd.next(0, 1) == 1) {
            p[c] = allowed[rnd.next(0, (int)allowed.size() - 1)];
        } else {
            p[c] = c;
        }
    }
    string b;
    for (int i = 0; i < n; ++i) {
        if (rnd.next(0, 1) == 1) {
            b += p[a[i]];
        } else {
            b += a[i];
        }
    }
    cout << a << '\n';
    cout << b << '\n';
}
