// mitsui_sumitomo_2019_f
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

    ll T1, T2;
    cin >> T1 >> T2;
    ll A1, A2;
    cin >> A1 >> A2;
    ll B1, B2;
    cin >> B1 >> B2;

    // A1のほうが大きいとする
    if (B1 > A1){
        swap(A1, B1);
        swap(A2, B2);
    }

    ll C1 = A1 - B1;
    ll C2 = A2 - B2;

    //
    if (C1 == 0){
        if (C2 == 0){
            print("infinity");
        } else {
            print(1);
        }
        return 0;
    }

    ll x = C1 * T1;
    ll y = C2 * T2;

    if (C1 * T1 + C2 * T2 > 0){
        print(0);
        return 0;
    }

    if (C1 * T1 + C2 * T2 == 0){
        print("infinity");
        return 0;
    }

    ll d = -(x + y);

    if (d > x){
        print(1);
        return 0;
    }

    if (d == x){
        print(2);
        return 0;
    }

    ll ans;
    if (x % d == 0){
        ll n = x / d;
        ans = 2 * n;
    } else {
        ll n = x / d ;
        ans = 2 * n + 1;
    }
    print(ans);


    return 0;
}
