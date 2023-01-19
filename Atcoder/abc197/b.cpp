// abc197_b
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

int dx[4]={ 1, 0, -1, 0 };
int dy[4]={ 0, 1, 0, -1 };
bool bound_check(int i, int j, int N, int M) {return (0 <= i) && (i < N) && (0 <= j) && (j < M);}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    X--;Y--;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    int ans = 0;
    REP(k, 4){
        int x = X;
        int y = Y;
        while (true){
            x += dx[k];
            y += dy[k];
            if (not bound_check(x, y, H, W)) break;
            if (S[x][y] == '#') break;
            ans++;
        }
    }
    ans++;

    print(ans);


    return 0;
}
