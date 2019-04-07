// aribon2-3-5_a
// https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_d
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int N,M,L,X;
    cin >> N >> M >> L >> X;
    int A[10000];
    REP(i, N) cin >> A[i];

    vector<int> dp(M, 0);
    dp[0] = 1;
    REP(i, N){
        vector<int> dp_prev = dp;

        REP(j, M){
            if (dp_prev[j] == 0) continue;
            const int l = j + A[i];
            const int idx = l % M;
            if (dp_prev[idx] == 0) {
                dp[idx] = dp_prev[j] + (l / M);
            } else {
                dp[idx] = min(dp_prev[idx], dp_prev[j] + (l / M));
            }
        }
    }

    if (0 < dp[L] && dp[L] <= X){
        print("Yes");
    } else {
        print("No");
    }

    return 0;
}
