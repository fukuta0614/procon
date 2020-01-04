// abc105_c
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

    ll N;
    cin >> N;

    vector<ll> u(40);
    vector<ll> d(40);
    ll mx=0;
    ll mn=0;
    REP(i, 40){
        if (i % 2 == 0){
            u[i] = mx + (1ll << i);
            d[i] = mn + (1ll << i);
        } else {
            u[i] = mx - (1ll << i);
            d[i] = mn - (1ll << i);
        }
        mx = max(mx, u[i]);
        mn = min(mn, d[i]);
    }

//    print(u);
//    print(d);

    string ans;
    REP_REV(i, 40){
        if (d[i] <= N && N <= u[i]){
            ans += '1';
            if (i % 2 == 0){
                N -= 1ll << i;
            } else {
                N += 1ll << i;
            }
        } else {
            if (ans.size() > 0) ans += '0';
        }
    }
    if (ans.size() == 0) ans = '0';
    print(ans);


    return 0;
}
