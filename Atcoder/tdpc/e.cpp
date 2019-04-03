#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define CHAR2INT(c) (c - '0')
#define ALL(x) x.begin(), x.end()
#define COUT(x) cout << x << endl
#define COUT_2DARR(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ull dp[10002][100][2] = {0};

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int D;
    cin >> D;

    string N;
    cin >> N;

    dp[0][0][0] = 1;
    REP(i, N.size()){
        REP(j, D){
            REP(k, 2){
                int n = k ? 9 : CHAR2INT(N[i]);
                REP(d, n+1){
                    dp[i+1][(j+d)%D][k||(d!=n)] += dp[i][j][k] % MOD;
                }
            }
        }

    }
    ull ans = (dp[N.size()][0][0] + dp[N.size()][0][1] - 1) % MOD;

    COUT(ans);
    return 0;
}
