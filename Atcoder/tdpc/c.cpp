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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

double elo(double p, double q){
    return 1.0 / (1.0 + pow(10, (q - p) / 400));
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int K, N, R[1024];
    cin >> K;
    N = 1 << K;
    REP(i, N) {cin >> R[i];}

    vector<double> dp(N, 1.0);
    REP(k, K){
        vector<double> next_dp(N, 0.0);
        REP(i, N){
            int d = 1 << k;
            int d2 = d * 2;
            int q = i / d2;
            int r = i % d2;
            int s = r / d == 0 ? q * d2 + d : q * d2;
            double tmp = 0;
            REPN(j, s, s+d){
                tmp += dp[j] * elo(R[i], R[j]);
            }
            next_dp[i] = tmp * dp[i];
        }
        dp = next_dp;
    }

    REP(i, N) print(dp[i]);

    return 0;
}
