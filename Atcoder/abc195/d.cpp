// abc195_d
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

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<P> VW(N);
    REP(i, N) cin >> VW[i].second >> VW[i].first;
    vector<int> X(M);
    REP(i, M) cin >> X[i];

    sort(ALL(VW), greater<>());

    vector<int> order(M);
    iota(ALL(order), 0);
    sort(ALL(order), [&X](int i, int j){
        return X[i] < X[j];
    });

    while (Q--){
        int l, r;
        cin >> l >> r;
        l--; r--;

        int ans = 0;
        vector<bool> used(M);
        REP(i, N){
            auto [v, w] = VW[i];
            for (auto j: order){
                if (l <= j && j <= r) continue;
                if (used[j]) continue;
                if (w <= X[j]){
                    ans += v;
                    used[j] = true;
                    break;
                }
            }
        }
        print(ans);
    }

    return 0;
}
