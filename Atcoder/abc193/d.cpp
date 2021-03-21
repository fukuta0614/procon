// abc193_d
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

    int K;
    cin >> K;
    string S, T;
    cin >> S >> T;

    ll rest = 9*K-8;
    ll numerator = 0;
    ll denominator = rest * (rest - 1);

    map<int, int> mp_s;
    REP(i, 4) mp_s[S[i]-'0']++;
    map<int, int> mp_t;
    REP(i, 4) mp_t[T[i]-'0']++;

//    print(mp_s, mp_t);

    REPN(i, 1, 10) REPN(j, 1, 10){
        ll p = K - mp_s[i] - mp_t[i];
        ll q = K - mp_s[j] - mp_t[j];
        if (i == j) q--;

        mp_s[i]++;
        mp_t[j]++;

        ll x = 0;
        REPN(k, 1,10) x += k * pow(10, mp_s[k]);

        ll y = 0;
        REPN(k, 1,10) y += k * pow(10, mp_t[k]);

//        print(i, j, p, q, x, y);

        if (p > 0 && q > 0 && x > y){
            numerator += p * q;
        }

        mp_s[i]--;
        mp_t[j]--;
    }

//    print(numerator, denominator);
    double ans = 1.0 * numerator / denominator;

    print(ans);

    return 0;
}
