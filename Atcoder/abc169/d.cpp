// abc169_d
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


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

    ll N;
    cin >> N;

    auto fac = factorize(N);
//    print(fac);

    ll ans = 0;
    for (auto e: fac){
        ll p = e.first;
        ll x = e.second;

        if (p == 1) continue;

        ll tmp = 0;
        int i = 1;
        while (true) {
            if (tmp + i <= x) {
                tmp += i;
                i++;
            } else {
                break;
            }
        }
        ans += i-1;
    }

    print(ans);

    return 0;
}
