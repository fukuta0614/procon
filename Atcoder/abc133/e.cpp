// abc133_e
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

ll N, K;
vector<vector<int>> G;

ll dfs(int idx, int depth, int src){

    ll k = K - min(depth+1, 2);
    ll ans = 1;
    for (auto dst: G[idx]) {
        if (dst == src) continue;
        ans *= k--;
        ans %= MOD;
        ans *= dfs(dst, depth+1, idx);
        ans %= MOD;
    }

    return ans;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> K;

    G.resize(N);
    int a, b;
    REP(i, N-1){
        cin >> a >> b; a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    ll ans = (K * dfs(0, 0, -1)) % MOD;
    print(ans);

    return 0;
}
