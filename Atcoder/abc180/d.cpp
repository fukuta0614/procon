// abc180_d
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF (ll)(2e18)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll X, Y, A, B;

bool check(ll x){

    ll tmp = X;
    REP(i, x){

        if (tmp < B / (A-1)){
            tmp = tmp * A;
        } else {
            tmp = tmp + B;

            ll res = x - i - 1;
            if (res >= ((Y - tmp + B - 1) / B)){
                return false;
            }  else {
                return true;
            }
        }
    }

    return tmp < Y;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> X >> Y >> A >> B;

    ll ok = 0;
    ll ng = INF;
    while (ng - ok > 1){

        ll mid = (ok + ng) / 2;

        if (check(mid)){
            ok = mid;
        } else {
            ng = mid;
        }
    }

    print(ok);

    return 0;
}
