// abc199_e
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

    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M), Z(M);
    REP(i, M) cin >> X[i] >> Y[i] >> Z[i];

    vector<ll> dp(1<<N, 0);
    dp[0] = 1;
    REP(i, N){
        REP(p, 1 << N){
            if (dp[p] == 0) continue;
            if (__builtin_popcount(p) != i) continue;

            vector<int> tmp;
            REP(j, N) if ((p >> j) & 1) tmp.emplace_back(j+1);

            REP(n, N){
                if ((p >> n) & 1) continue;

                tmp.emplace_back(n+1);

                bool ok = true;
                REP(j, M) if (X[j] == i+1){
                    int cnt = 0;
                    for (auto v: tmp){
                        if (v <= Y[j]) cnt++;
                    }
                    if (cnt > Z[j]) {
                        ok = false;
                        break;
                    }
                }
//                print(i, p, n, tmp, ok);

                if (ok){
                    dp[p | (1 << n)] += dp[p];
                }
                tmp.pop_back();
            }
        }
    }
    print(dp[(1<<N)-1]);


    return 0;
}
