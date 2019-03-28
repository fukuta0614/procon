// aribon1-6_a
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define all(x) x.begin(), x.end()
#define INF ((1 << 16)-1)
#define MOD (1000000007)
#define print(arr, n) REP(i, n) cout << arr[i] << " ";

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    set<ll> S{};
    vector<ll> P{};
    ll N, M;
    cin >> N >> M;
    ll p;
    REP(i, N) { cin >> p; P.emplace_back(p);}

    REP(i, N) S.insert(P[i]);
    REP(i, N){
        REPN(j, i, N){
            ll m = P[i]+P[j];
            if (m <= M) S.insert(m);
        }
    }

    ll ans = 0;
    for (auto s: S) {
        auto it = S.lower_bound(M - s);
        if (it != S.begin()) ans = max(ans, s + *(--it));
    }

    cout << ans << endl;
    return 0;
}


