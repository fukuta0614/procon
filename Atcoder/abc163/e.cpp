// abc163_e
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

#define INF ((ll)1e15)
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

    int N;
    cin >> N;
    vector<P> A(N);
    REP(i, N) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(ALL(A), greater<P>());

    // dp[l][r]: 大きい方からl+r個見て、l個は左、r個右
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));

    REP(i, N) {
        ll p = A[i].first;
        int idx = (int)A[i].second;
        REP(l, i+1){
            int r = i - l;
            dp[l+1][r] = max(dp[l+1][r], dp[l][r] + p * abs(idx - l));
            dp[l][r+1] = max(dp[l][r+1], dp[l][r] + p * abs(N-1-r - idx));
        }
    }
//    print(dp);

    ll ans = 0;
    REP(i, N){
        ans = max(ans, dp[i][N-i]);
    }

    print(ans);

    return 0;
}
