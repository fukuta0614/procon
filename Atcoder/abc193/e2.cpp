// abc193_e
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

#define INF (ll)(2e18)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

// 拡張 Euclid の互除法
// ax + by = gcd(a, b) となる (x, y) を求め、d = gcd(a, b) を返す
ll extgcd(ll a, ll b, ll& x, ll& y) { ll d = a; if(b != 0){ d = extgcd(b, a%b, y, x); y -= (a/b) * x; } else{ x = 1; y = 0; } return d; }

// 負の数にも対応した mod
// 例えば -17 を 5 で割った余りは本当は 3 (-17 ≡ 3 (mod. 5))
// しかし単に -17 % 5 では -2 になってしまう
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 拡張 Euclid の互除法
// ap + bq = gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターンします
long long extGcd(long long a, long long b, long long &p, long long &q) {
    if (b == 0) { p = 1; q = 0; return a; }
    long long d = extGcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2) {
    long long p, q;
    long long d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
    if ((b2 - b1) % d != 0) return make_pair(0, -1);
    long long m = m1 * (m2/d); // lcm of (m1, m2)
    long long tmp = (b2 - b1) / d * p % (m2/d);
    long long r = mod(b1 + m1 * tmp, m);
    return make_pair(r, m);
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;
    while (T--){
        ll X, Y, P, Q;
        cin >> X >> Y >> P >> Q;

        ll ans = -1;

        REP(j, Q){
            int i = 0;
            ll n1 = 2*X + 2*Y;
            ll b1 = X + i;
            ll n2 = P + Q;
            ll b2 = P + j;

            auto res = ChineseRem(b1, n1, b2, n2);
            if (res.second == -1){
                continue;
            }
            ll tmp = res.first;
            ans = ans == -1 ? tmp : min(ans, tmp);
        }

        REP(i, Y) {
            int j = 0;
            ll n1 = 2*X + 2*Y;
            ll b1 = X + i;
            ll n2 = P + Q;
            ll b2 = P + j;

            auto res = ChineseRem(b1, n1, b2, n2);
            if (res.second == -1){
                continue;
            }
            ll tmp = res.first;
            ans = ans == -1 ? tmp : min(ans, tmp);
        }

        if (ans == -1){
            print("infinity");
        }  else {
            print(ans);
        }
    }

    return 0;
}
