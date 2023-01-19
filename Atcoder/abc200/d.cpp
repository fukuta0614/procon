// abc200_d
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

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) {cin >> A[i]; A[i] %= 200;}

    vector<int> dp(200, -1);
    dp[0] = N;
    vector<int> ans1, ans2;
    REP(i, N){
        auto prev = dp;
        REP(j, 200){
            int nj = (j + A[i]) % 200;
            if (0 <= prev[j] && prev[j] <= N) {
                if (0 <= prev[nj] && prev[nj] < N){
                    int x = nj;

                    while (true){
                        ans1.emplace_back(prev[x] + 1);
                        if (prev[x] != N){
                            assert(prev[x] >= 0);
                            x = (200 + x - A[prev[x]]) % 200;
                            if (x == 0){
                                break;
                            }
                        }
                    }

                    x = j;
                    ans2.emplace_back(i + 1);
                    while (x != 0){
                        ans2.emplace_back(prev[x] + 1);
                        if (prev[x] != N){
                            assert(prev[x] >= 0);
                            x = (200 + x - A[prev[x]]) % 200;
                            if (x == 0){
                                break;
                            }
                        }
                    }

                    break;
                } else {
                    dp[nj] = i;
                }
            }
        }

        if (not ans1.empty()){
            break;
        }
    }

    if (ans1.empty()){
        print("No");
        return 0;
    }

    print("Yes");

    reverse(ALL(ans1));
    reverse(ALL(ans2));

    cout << ans1.size() << " ";
    print_line(ans1, ans1.size());
    cout << ans2.size() << " ";
    print_line(ans2, ans2.size());

    return 0;
}
