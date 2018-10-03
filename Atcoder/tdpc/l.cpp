// tdpc_l
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int i = 0 ; i < n ; ++i)
#define REPN(i, m, n) for (int i = m ; i < n ; ++i)
#define INF ((1 << 16)-1)
#define MOD (1000000007)

#define MAXN 1024
int F[MAXN][MAXN];
int sum[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());

    int N;
    cin >> N;

    REP(i, N) REP(j, N) cin >> F[i][j];

    REP(i, N) REP(j, i) sum[i][j + 1] = sum[i][j] + F[i][j];


    REPN(i, 1, N) {
        int tmp = -INF;
        REP(j, i + 1) {
            tmp = max(tmp, dp[i - 1][j]);
            dp[i][j] = tmp + (sum[i][i] - sum[i][j]);
        }
    }
    int ans = -INF;
    REP(j, N) {
        ans = max(ans, dp[N - 1][j]);
//        debug(dp[N - 1][j]);
    }

    cout << 2 * ans << endl;

    return 0;
}
