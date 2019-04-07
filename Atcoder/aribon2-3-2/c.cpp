// aribon2-3-2_c
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int dp[101][101][101];

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, M;
    cin >> N >> M;

    REP(i, N){
        int a,b,c,w;
        cin >> a >> b >> c >> w;
        dp[a][b][c] = max(dp[a][b][c], w);
    }

    REP(a, 101) REP(b, 101) REP(c, 101) {
        dp[a][b][c] = max(dp[a][b][c], dp[max(0,a-1)][max(0,b-0)][max(0,c-0)]);
        dp[a][b][c] = max(dp[a][b][c], dp[max(0,a-0)][max(0,b-1)][max(0,c-0)]);
        dp[a][b][c] = max(dp[a][b][c], dp[max(0,a-0)][max(0,b-0)][max(0,c-1)]);
    }

    REP(i, M){
        int x,y,z;
        cin >> x >> y >> z;
        print(dp[x][y][z]);
    }

    return 0;
}
