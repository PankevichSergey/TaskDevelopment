#include "testlib.h"
#include <string>

using namespace std;

pair<bool, int> is_ok(string s) {
    int it = -1;
    for (char c : s) {
        ++it;
        if (c >= 'a' && c <= 'z') continue;
        if (c >= 'A' && c <= 'Z') continue;
        if (c >= '0' && c <= '9') continue;
        if (c == '(' || c == ')') continue;
        if (c == '{' || c == '}') continue;
        if (c == '[' || c == ']') continue;
        if (c == '<' || c == '>' || c == '=') continue;
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == ';') continue;
        return {false, it};
    }
    return {true, -1};
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 200'000, "n");
    int gr_n = validator.group().empty() ? 0 : atoi(validator.group().c_str());
    inf.readEoln();
    string a = inf.readWord();
    ensuref(a.size() == n, "first string size is not n");
    inf.readEoln();
    ensuref(is_ok(a).first, "a = %s contains bad char in pos %d", a.c_str(), is_ok(a).second);
    string b = inf.readWord();
    ensuref(b.size() == n, "second string size is not n");
    ensuref(is_ok(a).first, "b = %s contains bad char in pos %d", b.c_str(), is_ok(b).second);
    if(gr_n == 1){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        ensuref(a == "ab" || a == "a" || a == "b", "not ab in a");
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        ensuref(b == "ab" || b == "a" || b == "b", "not ab in b");
    }
    if(gr_n == 2){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        ensuref(a == "a" || a == "b" || a == "c" || a == "ab" || a == "ac" || a == "ab" || a == "abc", "not abc in a");
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        ensuref(b == "a" || b == "b" || b == "c" || b == "ab" || b == "ac" || b == "ab" || b == "abc", "not abc in b");
    }
    if(gr_n == 3){
        ensuref(n <= 1000, "n is more than 1000!");
    }
    inf.readEoln();
    inf.readEof();
}
