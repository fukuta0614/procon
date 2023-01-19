// abc251_b
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

    int N, W;
    cin >> N >> W;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    vector<bool> can(W+1);

    REP(i, N){
        int x = A[i];
        if (x <= W){
            can[x] = true;
        }
    }

    REP(i, N) REPN(j, i+1, N){
        int x = A[i] + A[j];
        if (x <= W){
            can[x] = true;
        }
    }

    REP(i, N) REPN(j, i+1, N) REPN(k, j+1, N){
        int x = A[i] + A[j] + A[k];
        if (x <= W){
            can[x] = true;
        }
    }

    vector<int> can2(W);
    REP(i, W+1){
        if (can[i]){
            can2[i] = i;
        }
    }
    print(can2);

    int ans = 0;
    REP(x, W+1){
        ans += can[x];
    }

    print(ans);

    return 0;
}
