// arc114_a
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

#define INF (ll)(1e18)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

map<ll, int> factorize(ll n){
    ll tmp = n;
    map<ll, int> res;
    for (ll a = 2; a * a <= n; a++) { int cnt = 0; while (tmp % a == 0){ cnt++; tmp /= a; } if (cnt > 0) res[a] = cnt; }
    if (tmp > 1) res[tmp] = 1;
    return res;
}

bool is_prime(int n){
    if (n == 1) return false;
    for (int a=2; a*a <= n; a++) if (n % a == 0) return false;
    return true;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> X(N);
    REP(i, N) cin >> X[i];

    vector<int> primes;
    REPN(p, 2, 51) {
        if (is_prime(p)) {
            primes.emplace_back(p);
        }
    }


    vector<bool> used(N);
    ll ans = INF;

    REP(m, 1 << primes.size()){
        ll tmp = 1;
        REP(i, primes.size()){
            if ((m >> i) & 1) {
                tmp *= primes[i];
            }
        }

        bool ok = true;
        REP(i, N){
            if (gcd(X[i], tmp) == 1){
                ok = false;
            }
        }

        if (ok) {
            ans = min(ans, tmp);
        }
    }

    print(ans);


    return 0;
}
