// abc153_e
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

    ll H, N;
    cin >> H >> N;
//    vector<P> AB(N);
//    REP(i, N) cin >> AB[i].first >> AB[i].second;
    vector<ll> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];

    ll mx = *max_element(ALL(A));

    vector<ll> dp(H+mx, INF);
    dp[0] = 0;
    REP(i, N){
        REPN(j, A[i], H+mx){
            dp[j] = min(dp[j], dp[j-A[i]] + B[i]);
        }
//        print(dp);
    }

    ll ans = INF;
    REPN(i, H, H+mx){
        ans = min(ans, dp[i]);
    }
    print(ans);

    return 0;
}
