// arc110_a
#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

bool valid(ll x, ll N, ll K, ll P, ll Q, const vector<ll>& v){

    ll base;
    ll diff;
    ll k;
    if (P < Q){
        base = P;
        diff = Q - P;
        k = N-K;
    } else {
        base = Q;
        diff = P - Q;
        k = K;
    }

    ll num = 0;
    REP(i, N){
        ll val = v[i] - base * x;
        if (val <= 0) continue;

        ll res = (val + diff - 1) / diff;

        if (res > x) return false;

        num += res;
    }
    return num <= x * k;
}

int main() {
#ifdef LOCAL
    ifstream in("input.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, K, P, Q, v0, a, c, mod;
    cin >> N >> K >> P >> Q >> v0 >> a >> c >> mod;

    vector<ll> v(N);
    v[0] = v0;
    REPN(i, 1, N){
        v[i] = ((ll)a * v[i-1] + c) % mod;
    }

    ll mn = min(P, Q);
    ll ok = (*max_element(ALL(v)) + mn - 1) / mn;
    ll ng = 0;

    while (ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if (valid(mid, N, K, P, Q, v)){
            ok = mid;
        } else {
            ng = mid;
        }
    }
    print(ok);

    return 0;
}
