// abc086_d
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


struct Cumsum2D{

    int H, W;
    vector<vector<ll>> cumsum;

    Cumsum2D(int H, int W, const vector<vector<ll>>& v) : H(H), W(W), cumsum(H+1, vector<ll>(W+1, 0)) {

        assert(static_cast<int>(v.size()) == H);
        assert(static_cast<int>(v[0].size()) == W);

        REP(i, H) {
            ll tmp = 0;
            REP(j, W){
                tmp += v[i][j];
                cumsum[i+1][j+1] = cumsum[i][j+1] + tmp;
            }
        }
    }

    // (i,j) -> (x,y)の合計 (i,jを含む）
    ll sum(int i, int j, int x, int y){
        if (i < 0 || j < 0) return 0;
        if (x >= H || y >= W) return 0;
        if (i > x || j > y) return 0;
        return cumsum[x+1][y+1] - cumsum[x+1][j] - cumsum[i][y+1] + cumsum[i][j];
    }

};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, K;
    cin >> N >> K;
    vector<vector<ll>> B(K, vector<ll>(K, 0));
    vector<vector<ll>> W(K, vector<ll>(K, 0));
    REP(i, N){
        int x, y; char c;
        cin >> x >> y >> c;
        x %= 2 * K;
        y %= 2 * K;

        bool rev = false;
        if (x >= K && y >= K){
            x -= K;
            y -= K;
        } else if (x >= K) {
            x -= K;
            rev = true;
        } else if (y >= K) {
            y -= K;
            rev = true;
        }

        if ((c == 'W') != rev){
            W[x][y] += 1;
        } else {
            B[x][y] += 1;
        }
    }

    Cumsum2D cumsum2d_b(K, K, B);
    Cumsum2D cumsum2d_w(K, K, W);

    ll ans = 0;
    REP(i, K) REP(j, K){
        ll tmp = 0;
        tmp += cumsum2d_b.sum(0, 0, i, j);
        tmp += cumsum2d_b.sum(i+1, j+1, K-1, K-1);
        tmp += cumsum2d_w.sum(0, j+1, i, K-1);
        tmp += cumsum2d_w.sum(i+1, 0, K-1, j);
        ans = max(ans, tmp);

        tmp = 0;
        tmp += cumsum2d_w.sum(0, 0, i, j);
        tmp += cumsum2d_w.sum(i+1, j+1, K-1, K-1);
        tmp += cumsum2d_b.sum(0, j+1, i, K-1);
        tmp += cumsum2d_b.sum(i+1, 0, K-1, j);
        ans = max(ans, tmp);
    }

    print(ans);

    return 0;
}
