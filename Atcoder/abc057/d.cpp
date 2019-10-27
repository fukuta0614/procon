// abc057_d
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)
#define EPS (1e-8)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


vector<vector<ll>> make_nCk_table(int N){
    vector<vector<ll>> nCk;
    nCk.assign(N+1, vector<ll>(N+1, 0));
    REP(i, N+1) {
        nCk[i][0] = 1;
        nCk[i][i] = 1;
        REPN(j, 1, i) nCk[i][j] = nCk[i-1][j-1] + nCk[i-1][j];
    }
    return nCk;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, A, B;
    cin >> N >> A >> B;

    vector<ll> v(N);
    map<ll, int> mp;
    REP(i, N) {
        cin >> v[i];
        mp[v[i]]++;
    }

    sort(ALL(v));

    double mx = 0;
    ll x = 0;
    REP(i, A) {
        mx += v[N-1-i];
        x = v[N-1-i];
    }

    mx /= A;
    print(mx);

    auto nCk = make_nCk_table(N);

    ll ans = 0;
    if (x == v[N-1]){
        ll n = mp[v[N-1]];
        REPN(k, A, min(n, B)+1){
            ans += nCk[n][k];
        }
    } else {
        ll n = mp[x];
        ll tmp = N - (upper_bound(ALL(v), x) - v.begin());
        ll k = A - tmp;
        ans += nCk[n][k];
    }

    print(ans);


    return 0;
}
