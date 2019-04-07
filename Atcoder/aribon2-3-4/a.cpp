// aribon2-3-4_a
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

#define INF ((1ll << 31)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll dp[2001];

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int N, K;
    cin >> N >> K;
    vector<int> A(N+1, 0);
    REPN(i, 1, N+1) cin >> A[i];

    REP(i, N+1) dp[i] = INF;
    dp[0] = 0;
    dp[1] = 1;

    ll sm = A[1];

    REPN(i, 2, N+1){
        int a = A[i];
        REPN_REV(n, 1, i+1){
            ll tmp = ((ll)(sm + a) * dp[n-1] + sm) / sm;
            if (tmp - dp[n-1] > a) continue;

            dp[n] = min(tmp, dp[n]);
        }
        sm += a;
    }

    if (sm == K) {
        print(1);
        return 0;
    }

    int ans = 0;
    REP_REV(i, N+1){
        if (dp[i] <= K){
            ans = max(ans, i);
        }
    }

    print(ans);

    return 0;
}
