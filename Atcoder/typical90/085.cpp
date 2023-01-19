// typical90_085
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

vector<ll> get_divisors(ll n){
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++){
        if (n % i != 0) continue;
        res.emplace_back(i);
        if (n / i == i) continue;
        res.emplace_back(n / i);
    }
    sort(ALL(res));
    return res;
}

map<ll, int> factorize(ll n){
    ll tmp = n;
    map<ll, int> res;
    for (ll a = 2; a * a <= n; a++) { int cnt = 0; while (tmp % a == 0){ cnt++; tmp /= a; } if (cnt > 0) res[a] = cnt; }
    if (tmp > 1) res[tmp] = 1;
    return res;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll K;
    cin >> K;

    auto divs = get_divisors(K);

    auto facts = factorize(K);

    ll ans = 0;

    for (auto d: divs){

        if (d * d * d > K) break;

        auto tmp = factorize(d);

        auto facts_tmp = facts;
        for (auto [p, n] : tmp){
            facts_tmp[p] -= n;
        }

        ll n_tmp = 1;
        for (auto [p, n] : facts_tmp){
            n_tmp *= (n+1);
        }
        print(d, n_tmp, facts_tmp, facts, tmp);

        ans += n_tmp / 2;

    }

    print(ans);



    return 0;
}
