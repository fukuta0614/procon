// abc147_e
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

#define INF ((1 << 29)-1)
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

    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W, 0));
    vector<vector<int>> B(H, vector<int>(W, 0));

    REP(i, H) REP(j, W) cin >> A[i][j];
    REP(i, H) REP(j, W) cin >> B[i][j];

    vector<vector<int>> X(H, vector<int>(W, 0));
    REP(i, H) REP(j, W){
        X[i][j] = abs(A[i][j] - B[i][j]);
    }

    int mx_n = 12801;
    vector<vector<vector<bool>>> dp(H, vector<vector<bool>>(W, vector<bool>(mx_n)));
    dp[0][0][mx_n/2] = true;
    REP(i, H) REP(j, W) {

        int x = X[i][j];

        if (i < H-1){
            REPN(k, x, mx_n-x){
                dp[i+1][j][k + x] = dp[i+1][j][k + x] | dp[i][j][k];
                dp[i+1][j][k - x] = dp[i+1][j][k - x] | dp[i][j][k];
            }
        }

        if (j < W-1){
            REPN(k, x, mx_n-x){
                dp[i][j+1][k + x] = dp[i][j+1][k + x] | dp[i][j][k];
                dp[i][j+1][k - x] = dp[i][j+1][k - x] | dp[i][j][k];
            }
        }
    }

    int x = X[H-1][W-1];
    auto tmp = dp[H-1][W-1];
    REPN(k, x, mx_n - x){
        dp[H-1][W-1][k+x] = tmp[k];
        dp[H-1][W-1][k-x] = tmp[k];
    }

//    vector<int> asdf(20);
//    iota(ALL(asdf), 0);
//    print(0, 0, asdf);
//
//    REP(i, H){
//        print(i, "-----");
//        REP(j, W){
//            print(i, j, dp[i][j]);
//        }
//    }
//    print(0, 0, tmp);


    int ans = INF;
    REPN(k, mx_n/2, mx_n){
        if (dp[H-1][W-1][k]) {
            ans = min(ans, k-mx_n/2);
        }
    }

    REPN_REV(k, 0, mx_n/2){
        if (dp[H-1][W-1][k]) {
            ans = min(ans, mx_n/2-k);
        }
    }

    print(ans);


    return 0;
}
