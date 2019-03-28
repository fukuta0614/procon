// arc042_d
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))

unordered_map<ll, ll> mp;
ll m, factor;

ll mod_pow(ll x, ll a, ll mod) {
    ll ret = 1;
    while (a > 0) {
        if (a & 1) ret = ret * x % mod;
        a >>= 1;
        x = x * x % mod;
    }
    return ret;
}

ll mod_inv(ll x, ll mod) {
    return mod_pow(x, mod - 2, mod);
}

ll baby_step_giant_step(ll x, ll y, ll mod) {

    ll e = y;
    REP(i, m) {
        auto it = mp.find(e);
        if (it != mp.end() && i * m + it->second < mod - 1) {
            return i * m + it->second;
        }
        e = (e * factor) % mod;
    }
    return -1;
}

void bsgs_search(ll x, ll p, ll a, ll b) {
    // create table
    ll e = 1ll;
    m = static_cast<ll>(ceil(sqrt(p)));
    for (ll i = 0; i < m; ++i) {
        mp[e] = i;
        e = (e * x) % p;
    }

    // giant baby
    ll k;
    factor = mod_pow(mod_inv(x, p), m, p);

    for (int y = 1;; ++y) {
        k = baby_step_giant_step(x, y, p);

        if (k < a) {
            k = k + (a - k + p - 2) / (p - 1) * (p - 1);
        }
        if (k <= b) {
            cout << y << endl;
            return;
        }
    }
}

void linear_search(ll x, ll p, ll a, ll b) {
    // normal
    ll n, mn;
    n = mod_pow(x, a, p);
    mn = n;
    REP(i, b - a) {
        n = n * x % p;
        mn = min(n, mn);
    }
    cout << mn << endl;

}

int main() {

#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    ll x, p, a, b;

    cin >> x >> p >> a >> b;

    ll K = 1 << 24;
    if (b - a < K) {
        linear_search(x, p, a, b);
    } else {
        bsgs_search(x, p, a, b);
    }

    return 0;

}

