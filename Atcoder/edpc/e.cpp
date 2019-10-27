// edpc_e
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

    ll N, W;
    cin >> N >> W;

    vector<ll> w(N), v(N);
    REP(i, N) cin >> w[i] >> v[i];

    ll max_V = 1e5+1;
    vector<ll> dp(max_V+1, numeric_limits<ll>::max());
    dp[0] = 0;
    REP(i, N){
        REP_REV(j, max_V+1){
            if (j - v[i] < 0) break;
            if (dp[j - v[i]] == numeric_limits<ll>::max()) continue;
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    ll ans = 0;
    REP_REV(j, max_V+1){
        if (dp[j] <= W) {
            ans = j;
            break;
        }
    }
    print(ans);


    return 0;
}
