// arc112_b
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

    ll B, C;
    cin >> B >> C;

    ll mx_p = B + (C - 2) / 2;
    ll mn_p = B - C/2;

    ll mx_m = - B + (C - 1) / 2;
    ll mn_m = - B - (C - 1) / 2;

    ll ans;
    if (B > 0){
        mn_p = max(mn_p, 0ll);
        mx_m = min(mx_m, 0ll);
        ans = (mx_p - mn_p + 1) + (mx_m - mn_m + 1);
        if (mx_m == 0 && mn_p == 0) ans--;
    } else {
        mn_m = max(mn_m, 0ll);
        mx_p = min(mx_p, 0ll);
        ans = (mx_m - mn_m + 1) + (mx_p - mn_p + 1);
        if (mn_m == 0 && mx_p == 0) ans--;
    }
//    print(mn_m, mx_m, mn_p, mx_p);

    print(ans);

    return 0;
}
