// aribon2-3-1_a
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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int dp[201][201];

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int D, N;
    cin >> D >> N;

    vector<int> T(D);
    REP(i, D) cin >> T[i];

    vector<P> AB(N);
    vector<int> C(N);
    REP(i, N) cin >> AB[i].first >> AB[i].second >> C[i];

    REP(i, D){
        REP(j, N){
            if (AB[j].first <= T[i] && T[i] <= AB[j].second){
                if (i == 0){
                    dp[i+1][j] = 0;
                } else {
                    REP(k, N) dp[i+1][j] = max(dp[i+1][j], dp[i][k] + abs(C[j] - C[k]));
                }
            } else {
                dp[i+1][j] = -INF;
            }
        }
    }

    int ans = 0;
    REP(i, N) ans = max(ans, dp[D][i]);
    print(ans);

    return 0;
}
