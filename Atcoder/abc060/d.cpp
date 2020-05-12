// abc060_d
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

int N, T;
vector<ll> W, V;

void dp_rec(){


}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> T;
    W.assign(N, 0);
    V.assign(N, 0);
    REP(i, N) cin >> W[i] >> V[i];

    map<ll, ll> dp;
    dp[0] = 0;
    REP(i, N){
        auto dp_prev = dp;
        for (auto e: dp_prev){
            ll w = e.first;
            ll v = e.second;
            ll tmp = dp[w + W[i]];
            dp[w + W[i]] = max(tmp , v + V[i]);
        }
//        print(dp);
    }

    ll ans = 0;
    for (auto e: dp){
        ll w = e.first;
        ll v = e.second;
        if (w <= T){
            ans = max(ans, v);
        }
    }

    print(ans);

    return 0;
}
