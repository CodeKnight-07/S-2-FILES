#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int T = inf.readInt();
    for(int tc = 1; tc <= T; tc++){
        setTestCase(tc);
        int N = inf.readInt();
        long long K = inf.readLong();
        vector<vector<long long>> p(3, vector<long long>(N));
        for(int j = 0; j < 3; j++) {
            for (int i = 0; i < N; i++) {
                p[j][i] = inf.readLong();
            }
        }
        vector<vector<long long>> w(3, vector<long long>(3));
        for (int i=0;i<3;i++) {
            for (int j=0; j<3; j++) {
                w[i][j] = inf.readLong();
            }
        }
        long long juryAns = ans.readLong();
        string juryPath = ans.readToken();
        long long contAns = ouf.readLong();
        string contPath = ouf.readToken();
        if(contAns != juryAns){
            quitf(_wa, "testcase %d: expected answer %lld, found %lld", tc, juryAns, contAns);
        }
        if((int)contPath.size() != N){
            quitf(_wa, "testcase %d: path length must be %d, found %d", tc, N, (int)contPath.size());
        }
        long long mn = LLONG_MAX;
        long long cost = 0;
        for (int i=0; i<N;i++) {
            char ch = contPath[i];
            if (ch < 'A' || ch > 'C') {
                quitf(_wa, "testcase %d: invalid character in path", tc);
            }
            int cur = ch - 'A';
            mn = min(mn, p[cur][i]);
            if (i > 0) {
                int prev = contPath[i - 1] - 'A';
                cost+=w[prev][cur];
                if (cost>K) {
                    quitf(_wa, "testcase %d: transition cost exceeds K", tc);
                }
            }
        }
        if (mn != contAns) {
            quitf(_wa, "testcase %d: claimed answer is %lld, but path gives minimum profit %lld", tc, contAns, mn);
        }
    }
    quitf(_ok, "all testcases passed");
    return 0;
}