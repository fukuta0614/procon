// tdpc_d
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int i = 0 ; i < n ; ++i)
#define REPN(i, m, n) for (int i = m ; i < n ; ++i)
#define INF (1 << 31)-1
#define MOD

int main() {
//    std::ifstream in("../arg.txt");
//    std::cin.rdbuf(in.rdbuf());

    int N;
    ll D;
    cin >> N >> D;
    int d2 = 0, d3 = 0, d5 = 0;

    while (D % 2 == 0) { D /= 2; ++d2; }
    while (D % 3 == 0) { D /= 3; ++d3; }
    while (D % 5 == 0) { D /= 5; ++d5; }

    if (D > 1) {
        cout << 0 << endl;
        return 0;
    }

    double dp[N + 1][d2 + 1][d3 + 1][d5 + 1] = {};
    dp[0][0][0][0] = 1.0;

    for (int n = 0; n < N; ++n) {
        for (int i = 0; i <= d2; ++i) {
            for (int j = 0; j <= d3; ++j) {
                for (int k = 0; k <= d5; ++k) {
                    if (dp[n][i][j][k] == 0) break;
                    double p = dp[n][i][j][k] / 6.0;
                    dp[n + 1][i][j][k] += p;
                    dp[n + 1][min(d2, i + 1)][j][k] += p;
                    dp[n + 1][i][min(d3, j + 1)][k] += p;
                    dp[n + 1][min(d2, i + 2)][j][k] += p;
                    dp[n + 1][i][j][min(d5, k + 1)] += p;
                    dp[n + 1][min(d2, i + 1)][min(d3, j + 1)][k] += p;
                }
            }
        }
    }

    cout << dp[N][d2][d3][d5] << endl;
    return 0;
}
