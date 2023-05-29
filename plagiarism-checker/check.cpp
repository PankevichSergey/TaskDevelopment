#include "testlib.h"
#include<string>
#include<map>

using namespace std;

struct Answer {
    string s;
    int cnt;
    map<char, char> p;
};

bool check_letter(char c){
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= '0' && c <= '9') return true;
    if (c == '(' || c == ')') return true;
    if (c == '{' || c == '}') return true;
    if (c == '[' || c == ']') return true;
    if (c == '<' || c == '>' || c == '=') return true;
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == ';') return true;
    return false;
}

pair<Answer, bool> readAns(InStream &stream) {
    string res = lowerCase(stream.readWord("[a-zA-Z]{2,3}"));
    bool correct = true;
    if (res == "yes") {
        int cnt = stream.readInt(0, 255);
        map<char, char> pos;
        for (int i = 0; i < cnt; ++i) {
            string a_ = stream.readWord();
            if (a_.size() != 1) {
                correct = false;
            }
            char a = a_[0];
            ensuref(check_letter(a), "a is incorrect symbol!");
            string b_ = stream.readWord();
            if (b_.size() != 1) {
                correct = false;
            }
            char b = b_[0];
            if (!check_letter(b)) {
                correct = false;
            }
            if (pos.find(a) != pos.end()) {
                correct = false;
            }
            pos[a] = b;
        }
        return {{res, cnt, pos}, correct};
    }
    return {{res, 0, {}}, correct};
}

string S, T;

bool is_valid_cnt(int cnt) {
    set<char> diff;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] != T[i]) {
            diff.insert(S[i]);
        }
    }
    return diff.size() == cnt;
}

bool is_valid_p(map<char, char> &p) {
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] != T[i] && (p.count(S[i]) == 0 || p[S[i]] != T[i])) {
            return false;
        }
    }
    return true;
}

bool is_valid_ans(Answer &ans){
    return is_valid_p(ans.p) && is_valid_cnt(ans.cnt);
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    auto jans_ = readAns(ans);
    auto pans_ = readAns(ouf);
    if(jans_.second == false){
        quit(_wa, "jury has bad output");
    }
    if(pans_.second == false){
        quit(_wa, "participant has bad output");
    }
    Answer jans = jans_.first;
    Answer pans = pans_.first;
    int n = inf.readInt();
    S = inf.readWord();
    T = inf.readWord();
    if(pans.s == "no" && jans.s == "no"){
        quit(_ok, "Ok!");
    }
    if ((pans.s != "yes") || !is_valid_ans(pans)) {
        quit(_wa, "participant's answer is wrong");
    }
    if ((jans.s != "yes") || !is_valid_ans(jans)) {
        quit(_wa, "jury's answer is wrong");
    }
    quit(_ok, "Ok!");
}
