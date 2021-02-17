// abc089_d
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

    int H, W, D;
    cin >> H >> W >> D;
    vector<int> X(H*W+1), Y(H*W+1);
    REP(i, H) REP(j, W) {
        int a; cin >> a;
        X[a] = i; Y[a] = j;
    }

    vector<vector<int>> cumsum(D);
    REP(d, D){
        int n = d == 0 ? D : d;
        int i = X[n];
        int j = Y[n];
        cumsum[d].emplace_back(0);
        while (n + D <= H*W){
            n += D;
            int x = X[n];
            int y = Y[n];
            cumsum[d].emplace_back(cumsum[d].back() + abs(x-i) + abs(y-j));
            i = x;
            j = y;
        }
    }

//    REP(d, D) print(cumsum[d]);

    int Q;
    cin >> Q;
    while (Q--){
        int a, b;
        cin >> a >> b;
        int d = a % D;
        int ra = d == 0 ? a/D-1 : a/D;
        int rb = d == 0 ? b/D-1 : b/D;
        int ans = cumsum[d][rb] - cumsum[d][ra];
        print(ans);
    }



    return 0;
}
