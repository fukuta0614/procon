// abc093_d
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

    int Q;
    cin >> Q;
    while (Q--){
        ll A, B;
        cin >> A >> B;
        if (A > B) swap(A, B);

        // 1-A-1位までと、B+1-B+A-1までをペアリング
        ll ans = 2 * (A - 1);

        // A+1からB-1までの数
        ll ok = 0;
        ll ng = B - A;
        while (ng - ok > 1){
            ll x = (ng + ok) / 2;

            // 中間くらいを評価
            bool valid = true;
            ll m = x/2;
            REPN(c, max(0ll, m-2), min(m+2, B-A)){
                ll tmp = (A + c) * (2 * A + x - (A + c));
                if (tmp >= A * B){
                    valid = false;
                }
            }

            if (valid){
                ok = x;
            } else {
                ng = x;
            }
        }

        ans += ok;
        print(ans);

    }

    return 0;
}
