#include <bits/stdc++.h>
#ifdef LOCAL
#include "cxx-prettyprint/prettyprint.hpp"
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ostream& operator<<(ostream& os, const __int128& x) {
    ll a = (ll) (x / 1000000000000000000ll);
    ll b = (ll) (x % 1000000000000000000ll);
    if (a != 0){
        os << a << b;
    } else {
        os << b;
    }
    return os;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N = 100;
    int M = 50;

    vector<int> A(N);
    REP(i, N) A[i] = (i+1)*(i+1);

    ll mx = 0;
    REP(i, M) mx += A[N-i-1];

    print("max", mx);

    vector<vector<ll>> dp(M+1, vector<ll>(mx+1));
    dp[0][0] = 1;
    REP(i, N){
        REPN_REV(j, 1, min(i+2, M+1)){
            REPN(k, A[i], mx+1){
                dp[j][k] += dp[j-1][k - A[i]];
            }
        }
        print(i);
    }

    ll ans = 0;
    REP(k, mx+1) {
        if (dp[M][k] == 1){
            ans += k;
        }
    }
    print("ans", ans);

    return 0;
}
