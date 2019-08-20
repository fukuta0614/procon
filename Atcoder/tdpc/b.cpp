// tdpc_b
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

int a, b, A[1000], B[1000];

int memo[1002][1002];

int dfs(int i, int j){

    if (memo[i][j] != -1) return memo[i][j];

    if (i >= a && j >= b) return memo[i][j] = 0;
    if (i > a || j > b) return memo[i][j] = INF;
    if (i == a) return memo[i][j] = B[j] + dfs(i, j+2);
    if (j == b) return memo[i][j] = A[i] + dfs(i+2, j);

    return memo[i][j] = max(A[i] + min(dfs(i+2,j), dfs(i+1,j+1)), B[j] + min(dfs(i,j+2), dfs(i+1,j+1)));

}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> a >> b;
    REP(i, a) cin >> A[i];
    REP(i, b) cin >> B[i];
    REP(i, a+2) REP(j, b+2) memo[i][j] = -1;
    int ans = dfs(0, 0);
    print(ans);

    return 0;
}


