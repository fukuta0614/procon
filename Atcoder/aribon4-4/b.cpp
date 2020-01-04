// aribon4-4_b
// CODE FESTIVAL 2016 Tournament Round 3 A ストラックアウト
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

    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    vector<vector<ll>> dp(K+1, vector<ll>(N, -1));
    dp[0].assign(N, 0);

    vector<deque<ll>> deqs(K+1);
    deqs[0].emplace_back(0);

    REP(i, N){

        REPN_REV(k, 1, K+1) {

            if (deqs[k-1].empty()) continue;

            // スライド最大値
            dp[k][i] = dp[k-1][deqs[k-1].front()] + k * A[i];

            // deque更新
            while (not deqs[k].empty() && dp[k][deqs[k].back()] <= dp[k][i]){
                deqs[k].pop_back();
            }
            deqs[k].emplace_back(i);

            // 先頭からpop
            if (deqs[k].front() == i - M){
                deqs[k].pop_front();
            }
        }

    }

//    REP(k, K+1) { print(k, dp[k]); }

    ll ans = 0;
    REP(i, N){
        ans = max(ans, dp[K][i]);
    }
    print(ans);


    return 0;
}
