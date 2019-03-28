#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)
#define REP(i, a) FOR(i,0,a)
typedef long long ll;
ll X, P, A, B, sp, xx;

unordered_map<ll, ll> mp;
const ll K = 1 << 24;

ll mpw(ll n, ll m) {
    ll ret = 1;
    while (m > 0) {
        if (m & 1) {
            ret *= n;
            ret %= P;
        }
        n *= n;
        n %= P;
        m /= 2;
    }
    return ret;
}

ll inv(ll n) {
    return mpw(n, P - 2);
}

ll bsgs(ll y) {
    ll z = y;
    REP(i, sp) {
        auto ite = mp.find(z);
        if (ite != mp.end() && i * sp + ite->second < P - 1) {
            return i * sp + ite->second;
        }
        z *= xx;
        z %= P;
    }
    return -1;
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    cin >> X >> P >> A >> B;
    for (sp = 1; sp * sp < P; sp++);
    xx = mpw(inv(X), sp);
    ll a = 1;
    REP(i, sp) {
        mp[a] = i;
        a *= X;
        a %= P;
    }

    cout << sp << endl;
    cout << xx << endl;

    for(auto it = mp.cbegin(); it != mp.cend(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
//    18795
//    256168923
//    130952736 18792
//    267091251 18790
//    64163265 18787
//    108727466 18786
//    90066785 18785
//    182800937 18784

    ll ans = P;
    if (B - A <= K) {
        ll b = mpw(X, A);
        REP(i, B - A + 1) {
            ans = min(ans, b);
            b *= X;
            b %= P;
        }
    } else {
        ll b = mpw(X, A);
        REP(i, K) {
            ans = min(ans, b);
            b *= X;
            b %= P;
        }

        FOR(i, 1, ans) {
            ll c = bsgs(i);
            cout << i << " " << c << endl;

            if (c < A) {
                c = c + (A - c + P - 2) / (P - 1) * (P - 1);
            }
            if (c <= B) {
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
