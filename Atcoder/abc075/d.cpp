// abc075_d
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

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);

    REP(i, N) cin >> X[i] >> Y[i];

    auto orig_x = X;
    auto orig_y = Y;

    sort(ALL(X));
    sort(ALL(Y));

    ll ans = (ll)1e20;
    REP(xi, N-1) REPN(xj, xi+1, N) REP(yi, N-1) REPN(yj, yi+1, N){

        ll l = X[xi];
        ll r = X[xj];
        ll u = Y[yi];
        ll d = Y[yj];

        ll cnt = 0;
        REP(k, N){
            if (l <= orig_x[k] && orig_x[k] <= r && u <= orig_y[k] && orig_y[k] <= d) cnt++;
        }

        if (cnt >= K){
            ll area = (r - l) * (d - u);
            ans = min(ans, area);
        }
    }

    print(ans);

    return 0;
}
