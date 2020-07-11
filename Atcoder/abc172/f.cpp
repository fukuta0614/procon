// abc172_f
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

    ll X = 0;
    REPN(i, 2, N) X ^= A[i];
    ll S = A[0] + A[1];
    ll D = (S - X) / 2;

    // 解法2
//    if ((D & X) > 0 || D < 0 || D > A[0] || (S - X) % 2){
//        print(-1);
//        return 0;
//    }

//    ll Y = 0;
//    REP_REV(d, 50){
//        ll y = X & (1ll << d);
//        if ((D ^ (Y | y)) <= A[0]){
//            Y |= y;
//        }
//    }
//    ll a = D ^ Y;

//    if (a == 0){
//        print(-1);
//        return 0;
//    }
//
//    ll ans = A[0] - a;
//    print(ans);

    // 解法3 (bit桁DP)
    if (S < X || (S - X) % 2){
        print(-1);
        return 0;
    }

    int K = 50;
    vector<vector<ll>> dp(K+1, vector<ll>(2, -1)); // i番目まで見たaの最大値, 0,1: 小さいか確定してるかどうか。

    dp[0][0] = 0;
    REP(i, K){
        int k = K-1 - i;
        ll cd = (D >> k) & 1;
        ll cx = (X >> k) & 1;
        ll ca = (A[0] >> k) & 1;
        ll v = 1ll << k;

        if (cd & cx){ print(-1); exit(0); }

        REP(j, 2){
            if (dp[i][j] == -1) continue;

            REP(na, 2) REP(nb, 2){
                if ((na ^ nb) != cx) continue;
                if ((na & nb) != cd) continue;

                int nj;
                if (na < ca) {
                    nj = 1;
                } else if (na == ca) {
                    nj = j;
                } else {
                    if (j == 0) continue;
                    nj = j;
                }

                if (na){
                    dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] | v);
                } else {
                    dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]);
                }

            }

        }

    }
    ll a = max(dp[K][0], dp[K][1]);
    if (a == 0 || a == -1){
        print(-1);
        return 0;
    }

    ll ans = A[0] - a;
    print(ans);

    return 0;
}
