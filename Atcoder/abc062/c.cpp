// abc062_c
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

    ll H, W;
    cin >> H >> W;

    ll ans = 1e20;
    REPN(i, 1, H+1){
        ll h = H-i;
        ll a = i * W;
        if (h % 2 == 0 || W % 2 == 0){
            ll b = h * W / 2;
            ans = min(ans, abs(a - b));
        } else {
            ll b = (h * W + min(h, W)) / 2;
            ll c = (h * W - min(h, W)) / 2;
            ans = min(ans, abs(max(a, b) - min(a, c)));
        }
    }

    REPN(i, 1, W+1){
        ll w = W-i;
        ll a = i * H;
        if (w % 2 == 0 || H % 2 == 0){
            ll b = w * H / 2;
            ans = min(ans, abs(a - b));
        } else {
            ll b = (w * H + min(w, H)) / 2;
            ll c = (w * H - min(w, H)) / 2;
            ans = min(ans, abs(max(a, b) - min(a, c)));
        }
    }

    print(ans);

    return 0;
}
