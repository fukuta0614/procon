// abc274_f
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

    int N, A;
    cin >> N >> A;

    vector<int> W(N), X(N), V(N);
    REP(i, N) cin >> W[i] >> X[i] >> V[i];

    int ans = 0;
    REP(i, N){
        vector<pair<double, int>> event;
        int tmp = 0;
        REP(j, N){
            double vdiff = V[j] - V[i];
            double xdiff = X[i] - X[j];

            if (X[i] <= X[j] && X[j] <= X[i] + A) {
                tmp += W[j];
            }

            if (vdiff > 0) {
                event.emplace_back(xdiff / vdiff, W[j]);
                event.emplace_back((xdiff + A) / vdiff, -W[j]);
            } else if (vdiff < 0){
                event.emplace_back(xdiff / vdiff, -W[j]);
                event.emplace_back((xdiff + A) / vdiff, W[j]);
            }
        }
        ans = max(ans, tmp);

        const double eps = 1e-9;
        for (auto& [t, w]: event){
            t += w > 0 ? -eps : eps;
        }

        sort(ALL(event));
//        print(i, tmp, event);
        for (auto& [t, w]: event){
            if (t >= 0) tmp += w;
            ans = max(ans, tmp);
        }
    }
    print(ans);

    return 0;
}
