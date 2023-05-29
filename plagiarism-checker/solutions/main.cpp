#include <iostream>
#include <map>
#include <cassert>

using namespace std;

int main() {
    int n;
    cin >> n;
    string a;
    string b;
    cin >> a >> b;
    map<char, char> must;
    for (int i = 0; i < n; ++i) {
        if (b[i] != a[i]) {
            auto it = must.find(a[i]);
            if (it == must.end()) {
                must[a[i]] = b[i];
            } else if (it->second != b[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    cout << must.size() << '\n';
    for (auto[c1, c2] : must) {
        assert(c1 != c2);
        cout << c1 << ' ' << c2 << '\n';
    }
}
