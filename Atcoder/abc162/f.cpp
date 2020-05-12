// abc162_f
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

#define INF ((ll)1e15)
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

    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    // dp[i][j] i個見て、(i+1)/2-j選んでいる状態
    // 残りのn-i個で最高でも (n-i+1)/2個しか選べない。計算すると、たかだかj=2まで
    vector<vector<ll>> dp(N+1, vector<ll>(3, -INF));
    dp[0][0] = 0;
    dp[1][0] = A[0];
    dp[1][1] = 0;
    REPN(i, 2, N+1){
        ll a = A[i-1];
        if (i % 2 == 1){
            if (i >= 2) dp[i][0] = max(dp[i][0], dp[i-2][0] + a);

            if (i >= 1) dp[i][1] = max(dp[i][1], dp[i-1][0]);
            if (i >= 2) dp[i][1] = max(dp[i][1], dp[i-2][0]);
            if (i >= 2) dp[i][1] = max(dp[i][1], dp[i-2][1] + a);

            if (i >= 1) dp[i][2] = max(dp[i][2], dp[i-1][1]);
            if (i >= 2) dp[i][2] = max(dp[i][2], dp[i-2][1]);
            if (i >= 2) dp[i][2] = max(dp[i][2], dp[i-2][2] + a);

            if (i >= 3) dp[i][2] = max(dp[i][2], dp[i-3][0]);
            if (i >= 4) dp[i][2] = max(dp[i][2], dp[i-4][0]);
            if (i >= 4) dp[i][2] = max(dp[i][2], dp[i-4][1] + a);

        } else {

            if (i >= 1) dp[i][0] = max(dp[i][0], dp[i-1][0]);
            if (i >= 2) dp[i][0] = max(dp[i][0], dp[i-2][0] + a);

            if (i >= 1) dp[i][1] = max(dp[i][1], dp[i-1][1]);
            if (i >= 2) dp[i][1] = max(dp[i][1], dp[i-2][0]);
            if (i >= 3) dp[i][1] = max(dp[i][1], dp[i-3][0]);
            if (i >= 2) dp[i][1] = max(dp[i][1], dp[i-2][1] + a);

            if (i >= 1) dp[i][2] = max(dp[i][2], dp[i-1][2]);

            if (i >= 2) dp[i][2] = max(dp[i][2], dp[i-2][1]);
            if (i >= 3) dp[i][2] = max(dp[i][2], dp[i-3][1]);
            if (i >= 2) dp[i][2] = max(dp[i][2], dp[i-2][2] + a);

            if (i >= 4) dp[i][2] = max(dp[i][2], dp[i-4][0]);
            if (i >= 5) dp[i][2] = max(dp[i][2], dp[i-5][0]);
            if (i >= 4) dp[i][2] = max(dp[i][2], dp[i-4][1] + a);
        }
    }
//    print(dp);
    ll ans = N % 2 == 0 ? dp[N][0] : dp[N][1];
    print(ans);

    return 0;
}
