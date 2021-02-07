// abc191_d
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
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    long double X, Y, R;
    cin >> X >> Y >> R;

    ll left = ll(X - R);
    ll right = ll(X + R);

//    print(left, right);

    ll ans = 0;
    REPN(x, left, right+1){

        long double t = sqrt(R*R - (X - x)*(X - x));
        ll up = (ll)floor(Y + t);

        if ((X - x)*(X - x) + (up+1 - Y) * (up+1 - Y) <= R*R){
            up++;
        }

        if ((X - x)*(X - x) + (up - Y) * (up - Y) > R*R){
            up--;
        }

        ll down = (ll) ceil(Y - t);

        if ((X - x)*(X - x) + (down-1- Y) * (down-1 - Y) <= R*R){
            down--;
        }

        if ((X - x)*(X - x) + (down - Y) * (down - Y) > R*R){
            down++;
        }
//        print(x, up, down);

        ans += up - down + 1;
    }

    print(ans);

    return 0;
}
