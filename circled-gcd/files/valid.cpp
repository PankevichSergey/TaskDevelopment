#include "testlib.h"



const int MINN = 2;
const int MAXN = 200'000;
const int MAXC = 1'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, MAXN, "n");
    inf.readEoln();

    for(int i = 0; i < n; ++i) {
        inf.readInt(1, MAXC, "a_i");
        if (i < n - 1) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    inf.readEof();
}
