// abc135_d
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
#define CHAR2INT(c) (c - '0')

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll d_10[100001] = {0};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S;
    cin >> S;

    d_10[0] = 1;
    REP(i, 100001){
        d_10[i+1] = (d_10[i] * 10) % 13;
    }

    vector<ll> dp(13, 0);
    dp[0] = 1;
    REP(i, S.size()) {
        auto prev = dp;
        dp.assign(13, 0);
        REP(j, 13) {
            if (S[i] == '?') {
                REP(d, 10) {
                    ll x = (j + d * d_10[S.size()-i-1]) % 13;
                    dp[x] = (dp[x] + prev[j]) % MOD;
                }
            } else {
                int n = CHAR2INT(S[i]);
                ll x = (j + n * d_10[S.size()-i-1]) % 13;
                dp[x] = (dp[x] + prev[j]) % MOD;
            }
        }
    }
    print(dp[5]);

    return 0;
}
