// abc283_e
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W, 0));
    REP(i, H) REP(j, W) cin >> A[i][j];

    auto check = [&](int x, int y){
        int c = A[x][y];
        bool ret = false;
        if (x >= 1) ret |= (c == A[x-1][y]);
        if (x <= H-2) ret |= (c == A[x+1][y]);
        if (y >= 1) ret |= (c == A[x][y-1]);
        if (y <= W-2) ret |= (c == A[x][y+1]);
        return !ret;
    };

    auto flip = [&](int x){
        REP(j, W){
            A[x][j] = 1 - A[x][j];
        }
    };

    int ans = 0;
    REP(i, H){
        bool need_flip = false;
        REP(j, W){
            need_flip |= check(i, j);
        }
//        print(i, need_flip);
//        print(A);
        if (need_flip){
            if (i == H-1){
                print(-1);
                return 0;
            } else {
                flip(i+1);
                ans++;

                need_flip = false;
                REP(j, W){
                    need_flip |= check(i, j);
                }
                if (need_flip){
                    print(-1);
                    return 0;
                }
            }
        }
    }

    ans = min(ans, H-ans);
    print(ans);

    return 0;
}
