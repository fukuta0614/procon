// abc201_d
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

int H, W;
vector<vector<char>> A;
vector<vector<int>> memo;

int rec(int i, int j){

    if (memo[i][j] != INF) return memo[i][j];

    int x = A[i][j] == '+' ? 1 : -1;
    if (i == 0 && j == 0) x = 0;

    int ret = -INF;
    if (i < H-1) ret = max(ret, rec(i+1, j));
    if (j < W-1) ret = max(ret, rec(i, j+1));
    if (ret == -INF) ret = 0;

    return memo[i][j] = x - ret;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> H >> W;
    A.assign(H, vector<char>(W, 0));
    REP(i, H) REP(j, W) cin >> A[i][j];

    memo.assign(H, vector<int>(W, INF));

    int ans = rec(0, 0);

//    print(ans);
//    print(memo);

    if (ans < 0){
        print("Takahashi");
    } else if (ans > 0){
        print("Aoki");
    } else {
        print("Draw");
    }

    return 0;
}
