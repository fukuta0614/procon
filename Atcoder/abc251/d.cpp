// abc251_d
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
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
    int W;
    cin >> W;
    int N = 300;

    vector<int> dp(W+1, 0);
    vector<int> ans;

    int n = 1;
    int max_n = 0;

    while (n <= W) {
        if (dp[n] == 0){
            ans.emplace_back(n);

            REPN_REV(j, 1, W-n+1){
                if (0 < dp[j] and dp[j] < 3) {
                    dp[j + n] = dp[j] + 1;
                }
            }
            dp[n] = 1;
        }
        print(n, dp);
        n++;

    }

    print(ans);


//    vector<int> ans{1};
//    int a = 1;
//    REPN(i, 1, N){
//        ans.emplace_back(ans.back() + a++);
//    }
//    print(ans);

    return 0;
}
