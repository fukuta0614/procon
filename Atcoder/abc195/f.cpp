// abc195_f
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

string to_bin(int n){ std::stringstream ss; ss << std::bitset<8>(n); return ss.str(); }


map<ll, int> factorize(ll n){
    ll tmp = n;
    map<ll, int> res;
    for (ll a = 2; a < 72; a++) { int cnt = 0; while (tmp % a == 0){ cnt++; tmp /= a; } if (cnt > 0) res[a] = cnt; }
    return res;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll A, B;
    cin >> A >> B;

    vector<map<ll, int>> fs;
    for (ll i = A; i <= B; ++i) {
        fs.emplace_back(factorize(i));
    }
//    print(fs.size(), fs);

    set<ll> ds;
    for (auto& mp: fs){
        for (auto& [p, n] : mp){
            ds.emplace(p);
        }
    }
    vector<ll> ds2(ALL(ds));

//    print(ds2.size(), ds2);

    map<ll, ll> fs2;
    int prime_cnt = 0;
    REP(i, fs.size()){
        ll key = 0;
        for (auto& [p, n]: fs[i]){
            int x = lower_bound(ALL(ds2), p) - ds2.begin() + 1;
            key |= ll(1) << x;
        }
        if (key == 0){
            prime_cnt++;
        } else {
            fs2[key]++;
        }
    }

//    print(fs2.size(), fs2);

    vector<ll> dp(1 << 21);
    dp[0] = 1;
    for (auto [key, n]: fs2){
        REP(e, 1 << 21){
            if (e & key) continue;
            dp[e | key] += n * dp[e];
        }
    }

    ll ans = 0;
    REP(e, 1 << 21){
        ans += dp[e];
    }

//    map<ll, ll> dp;
//    dp[0] = 1;
//    for (auto [key, n]: fs2){
//        auto tmp = dp;
//        for (auto [e, n2]: tmp){
//            if (e & key) continue;
//            dp[e | key] += n * dp[e];
//        }
//    }
//
//    ll ans = 0;
//    for (auto [e, n]: dp){
//        ans += n;
//    }
    ans *= pow(2, prime_cnt);

    print(ans);

    return 0;
}
