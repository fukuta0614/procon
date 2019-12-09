#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;
ll bit_kosu[61];


int main(){
    ll n;
    cin >> n;
    REP(i, n) {
        ll tmp;
        cin >> tmp;
        REP(j, 60) {
            if((tmp >> j) & 1) {
                bit_kosu[j]++;
            }
        }
    }
    ll ans = 0;
    ll modint = 1000000007;

    REP(j, 60) {
        long long  tmp = (long long)1 << j;
        //printf( "case3: %lld\n", tmp);
        tmp %= modint;
        ll sdf = bit_kosu[j] * (n - bit_kosu[j]);
        sdf %= modint;

        tmp *= sdf;
        tmp %= modint;

        ans += tmp;
        ans %= modint;

    }

    cout << ans << endl;

    return 0;
}
