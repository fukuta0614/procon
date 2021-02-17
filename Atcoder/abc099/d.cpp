// abc099_d
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
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e9)
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

    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C, 0));
    REP(i, C) REP(j, C) cin >> D[i][j];
    vector<vector<int>> S(N, vector<int>(N, 0));
    REP(i, N) REP(j, N) {cin >> S[i][j]; S[i][j]--;}

    vector<vector<int>> memo(3, vector<int>(C, 0));
    REP(k, C){
        REP(i, N) REP(j, N){
            int m = (i + j) % 3;
            memo[m][k] += D[S[i][j]][k];
        }
    }

    int ans = INF;
    REP(i, C) REP(j, C) REP(k, C){
        if (i == j || j == k || k == i) continue;
        int tmp = memo[0][i] + memo[1][j] + memo[2][k];
        ans = min(ans, tmp);
    }
    print(ans);

    return 0;
}
