// abc145_f
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
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, K;
    cin >> N >> K;
    vector<int> H(N+1, 0);
    REP(i, N) cin >> H[i+1];

    vector<vector<vector<ll>>> dp(N+2, vector<vector<ll>>(K+2, vector<ll>(K+2, INF)));
    // dp[i][j][k] : i番目まで見て、j個消していて、k個連続で消している状態
    // 配るDP
    dp[0][0][0] = 0;
//    print(0,dp[0]);
    REP(i, N) {
        REP(j, K+1){
            REP(k, min(i, K)+1){
                dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + max(0, H[i+1] - H[i-k]));
                dp[i+1][j+1][k+1] = dp[i][j][k];
            }
        }
//        print(i+1,dp[i+1]);
    }

    ll ans = INF;
    REP(j, K+1) REP(k, K+1){
        ans = min(ans, dp[N][j][k]);
    }

    print(ans);

    return 0;
}
