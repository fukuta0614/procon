// aribon2-2_e
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define INF (1ll << 40)
#define MOD (1000000007)

#define ALL(x) x.begin(), x.end()
#define COUT(x) cout << x << endl
#define COUT_2DARR(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    ull N;
    cin >> N;

    vector<P> G(N);
    ll x, w;
    REP(i, N) {
        cin >> x >> w;
        G[i].first = x - w;
        G[i].second = x + w;
    }
    sort(ALL(G), [](const P& x, const P& y) { return x.second < y.second; });

    ll ans = 0, t = -INF;
    for (auto p: G){
        if (t <= p.first){
            t = p.second;
            ans++;
        }
    }

    COUT(ans);
    return 0;
}
