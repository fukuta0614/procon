// abc196_d
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

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int H, W, A, B;
int ans = 0;
void dfs(int a, int node, vector<vector<int>>& S){

    if (node == H*W){
        ans += a == A;
        return;
    }
    int i = node / W;
    int j = node % W;

    if (i + 1 < H && S[i][j] == 0 && S[i + 1][j] == 0) {
        S[i][j] = S[i+1][j] = 1;
        dfs(a+1, i*W+j+1, S);
        S[i][j] = S[i+1][j] = 0;
    }

    if (j + 1 < W && S[i][j] == 0 && S[i][j+1] == 0) {
        S[i][j] = S[i][j+1] = 1;
        dfs(a+1, i*W+j+1, S);
        S[i][j] = S[i][j+1] = 0;
    }

    dfs(a, i*W+j+1, S);
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> H >> W >> A >> B;

    vector<vector<int>> S(H, vector<int>(W));
    dfs(0, 0, S);
    print(ans);

    return 0;
}
