// abc203_d
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

#define INF (ll)(1e9+1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Cumsum2D{

    int H, W;
    vector<vector<int>> cumsum;

    Cumsum2D(int H, int W, const vector<vector<int>>& v) : H(H), W(W), cumsum(H+1, vector<int>(W+1, 0)) {

        assert(static_cast<int>(v.size()) == H);
        assert(static_cast<int>(v[0].size()) == W);

        REP(i, H) {
            int tmp = 0;
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
    vector<vector<int>> A(N, vector<int>(N, 0));
    REP(i, N) REP(j, N) cin >> A[i][j];
    vector<vector<int>> B(N, vector<int>(N, 0));

    auto valid = [&](int x){

        REP(i, N) REP(j, N){
            B[i][j] = int(A[i][j] >= x);
        }
        Cumsum2D c(N, N, B);

        bool valid = true;
        REP(i, N-K+1) REP(j, N-K+1){
            int sm = c.sum(i, j, i+K-1, j+K-1);
            valid = valid & (sm >= K*K/2+1);
        }
        return valid;
    };

    int ok = 0;
    int ng = INF;
    while (ng - ok > 1){
        int x = (ok + ng) / 2;
        if (valid(x)){
            ok = x;
        } else {
            ng = x;
        }
    }

    print(ok);


    return 0;
}
