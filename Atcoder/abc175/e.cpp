// abc175_e
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif
    int R, C, K;
    cin >> R >> C >> K;
    vector<vector<ll>> items(R, vector<ll>(C, 0));
    REP(i, K){
        int r, c, v;
        cin >> r >> c >> v;
        r--; c--;
        items[r][c] = v;
    }

    vector<vector<vector<ll>>> dp(R, vector<vector<ll>>(C, vector<ll>(4, 0)));
    REP(i, R) REP(j, C) {

        if (i>0) dp[i][j][0] = *max_element(ALL(dp[i-1][j]));
        dp[i][j][1] = dp[i][j][0] + items[i][j];

        if (j>0){
            REPN(k, 1, 4){
                dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + items[i][j]);
            }
        }
    }
//    REP(i, R) print(dp[i]);

    ll ans = *max_element(ALL(dp[R-1][C-1]));
    print(ans);

    return 0;
}
