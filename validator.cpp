#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int T = inf.readInt(1, 10000, "T");
    inf.readEoln();
    long long sumN = 0;
    for(int tc=1;tc<=T;tc++){
        setTestCase(tc);
        int N = inf.readInt(1, 100000, "N");
        inf.readSpace();
        long long K = inf.readLong(0LL, 1000000000000000000LL, "K");
        inf.readEoln();
        sumN+=N;
        ensuref(sumN<=200000, "sum of N exceeds 200000");
        for(int row=0;row<3;row++){
            for(int i=1; i<=N;i++){
                inf.readLong(1LL, 1000000000LL, "profit");
                if (i<N) inf.readSpace();
            }
            inf.readEoln();
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                long long x = inf.readLong(0LL, 1000000000LL, "W");
                if (i==j) {
                    ensuref(x==0, "W[%d][%d] must be 0", i, j);
                }
                if (j<3) inf.readSpace();
            }
            inf.readEoln();
        }
    }
    inf.readEof();
    return 0;
}