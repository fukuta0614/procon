// abc195_e
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
    string S, X;
    cin >> N >> S >> X;

    vector<int> d10(N+1);
    d10[0] = 1;
    REP(i, N){
        d10[i+1] = (d10[i] * 10) % 7;
    }

    vector<pair<char, int>> turn;
    REP(i, N){
        int j = i;
        while (X[j] == X[j+1]){
            j++;
        }
        turn.emplace_back(X[i], j-i+1);
        i = j;
    }

//    print(turn);

    vector<vector<vector<bool>>> dp(turn.size(), vector<vector<bool>>(7, vector<bool>(7, false)));

    int idx = 0;
    REP(t, turn.size()) {
        auto [c, n] = turn[t];

        REP(k, 7){
            dp[t][k][k] = true;
            REP(i, n){
                auto prev = dp[t][k];
                int m = ((S[idx+i] - '0') * d10[N-1-(idx+i)]) % 7;
                REP(j, 7){
                    dp[t][k][(j+m)%7] = dp[t][k][(j+m)%7] | prev[j];
                }
            }
        }
        idx += n;
    }

//    REP(t, turn.size()){
//        print(dp[t]);
//    }

    vector<bool> target(7);
    if (turn.back().first == 'T'){
        target = {true, false, false, false, false, false, false};
    } else {
        target = {false, true, true, true, true, true, true};
    }

    REP_REV(t, turn.size()){
        vector<bool> ok(7);
        REP(k, 7){
            ok[k] = false;
            REP(q, 7){
                if (target[q] && dp[t][k][q]){
                    ok[k] = true;
                    break;
                }
            }
        }

        REP(i, 7) target[i] = not ok[i];
    }

    // 最終の0がOKなら、先手の勝ち
    if (not target[0]){
        print(turn[0].first == 'T' ? "Takahashi" : "Aoki");
    } else {
        print(turn[0].first == 'T' ? "Aoki" : "Takahashi");
    }


    return 0;
}
