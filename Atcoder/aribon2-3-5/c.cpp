// aribon2-3-5_c
// https://atcoder.jp/contests/arc083/tasks/arc083_c
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

int N;
int X[1000];
vector<int> G[1000];
int memo[1001]; // 部分木の、自分の色じゃないほうの和の最小値

int dfs(int v){

    if (memo[v] >= 0) return memo[v];

    int sz = G[v].size();
    if (sz == 0) return 0;

    vector<vector<bool>> dp;
    dp.assign(sz+1, vector<bool>(X[v]+1, false));
    dp[0][0] = true;
    int sm = 0;
    REP(i, sz){
        int c = G[v][i];
        memo[c] = dfs(c);
        if (memo[c] == -1) return -1;
        sm += memo[c] + X[c];
        REP_REV(j, X[v]+1){
            bool tmp = false;
            if (j >= X[c]) tmp |= dp[i][j - X[c]];
            if (j >= memo[c]) tmp |= dp[i][j - memo[c]];
            dp[i+1][j] = tmp;
        }
    }

    REP_REV(j, X[v]+1){
        if (dp[sz][j]) {return sm - j;}
    }
    return -1;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    cin >> N;
    REPN(i, 1, N) {
        int p; cin >> p;
        G[--p].emplace_back(i);
    }
    REP(i, N) cin >> X[i];
    REP(i, N) memo[i] = -1;

    int ans = dfs(0);
    if (ans == -1) {
        print("IMPOSSIBLE");
    } else {
        print("POSSIBLE");
    }

    return 0;
}
