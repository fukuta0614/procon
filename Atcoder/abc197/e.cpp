// abc197_e
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> X(N), C(N);
    REP(i, N) cin >> X[i] >> C[i];

    vector<vector<ll>> balls(N);
    REP(i, N){
        balls[C[i]-1].emplace_back(X[i]);
    }
    REP(i, N){
        if (balls[i].empty()) continue;
        sort(ALL(balls[i]));
    }

    vector<P> dp(2, P(0, 0));
    REP(i, N){
        if (balls[i].empty()) continue;

        auto prev = dp;
        dp.assign(2, P(INF, 0));

        REP(j, 2){
            ll d = prev[j].first;
            ll x = prev[j].second;

            // left -> right
            ll a = abs(x - balls[i][0]) + abs(balls[i][0] - balls[i].back());
            dp[0] = min(dp[0], P(a + d, balls[i].back()));

            // right -> left
            ll b = abs(x - balls[i].back()) + abs(balls[i][0] - balls[i].back());
            dp[1] = min(dp[1], P(b + d,balls[i][0]));
        }
    }

    ll tmp1 = dp[0].first + abs(dp[0].second - 0);
    ll tmp2 = dp[1].first + abs(dp[1].second - 0);
    ll ans = min(tmp1, tmp2);

    print(ans);

    return 0;
}
