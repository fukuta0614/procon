// abc122_d
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define MOD (1000000007)
#define COUT(x) cout << x << endl

int dp[101][4][4][4];

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    REP(s1, 4) REP(s2, 4) REP(s3, 4){
        if ((s1==0 && s2==1 && s3==2) || (s1==0 && s2==2 && s3==1) || (s1==1 && s2==0 && s3==2)) continue;
        dp[3][s1][s2][s3] = 1;
    }

    REPN(i, 3, N){
        REP(s1, 4) REP(s2, 4) REP(s3, 4){

            int x = dp[i][s1][s2][s3];

            if ((s1 == 0)  ||
                (s1 == 1 && s2 != 2 && s3 != 2) ||
                (s1 == 2 && s2 != 1) ||
                (s1 == 3 && !(s2 == 1 && s3 == 2)))
            {
                dp[i+1][0][s1][s2] = (dp[i+1][0][s1][s2] + x) % MOD;
            }

            if (!(s1 == 0 && s2 == 2)) {
                dp[i+1][1][s1][s2] = (dp[i+1][1][s1][s2] + x) % MOD;
            }

            dp[i+1][2][s1][s2] = (dp[i+1][2][s1][s2] + x) % MOD;
            dp[i+1][3][s1][s2] = (dp[i+1][3][s1][s2] + x) % MOD;
        }
    }

    int ans = 0;
    REP(s1, 4) REP(s2, 4) REP(s3, 4) {ans = (ans + dp[N][s1][s2][s3])%MOD;}
    COUT(ans);

    return 0;
}
