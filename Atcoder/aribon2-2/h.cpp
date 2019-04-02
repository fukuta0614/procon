// aribon2-2_h
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF ((1 << 29)-1)

#define ALL(x) x.begin(), x.end()
#define COUT(x) cout << x << endl
#define COUT_2DARR(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N, K;
    string S;

    cin >> N >> K;
    cin >> S;

    string T = S;
    string ans = S;
    REP(i, N){
        int minSm = INF;
        REPN(j, i, N) {
            string tmp = T;
            swap(tmp[i], tmp[j]);
            int sm = 0;
            REP(k, N) { if (tmp[k] != S[k]) sm++; }
            if (sm <= K && (tmp.substr(0,i+1) < ans.substr(0,i+1) || (tmp.substr(0,i+1) == ans.substr(0,i+1) && sm < minSm))){
                ans = tmp;
                minSm = sm;
            }
        }
        T = ans;
    }
    COUT(ans);

    return 0;
}
