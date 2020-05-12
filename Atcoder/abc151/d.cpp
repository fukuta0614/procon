// abc151_d
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

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    vector<vector<int>> dp(H*W, vector<int>(H*W, INF));
    REP(i, H) REP(j, W) {
        if (S[i][j] == '#') continue;

        dp[i*W+j][i*W+j] = 0;

        REP(k, 4){
            int ni = i + dy[k];
            int nj = j + dx[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;

            if (S[ni][nj] == '.') {
                dp[i*W+j][ni*W+nj] = 1;
            }
        }
    }

//    REP(i, H*W) print(dp[i]);

    REP(k, H*W) REP(i, H*W) REP(j, H*W)  {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }

//    print("----");
//    REP(i, H*W) print(dp[i]);

    int ans = 0;
    REP(i, H*W) REP(j, H*W) {
        if (dp[i][j] != INF) ans = max(ans, dp[i][j]);
    }

    print(ans);


    return 0;
}
