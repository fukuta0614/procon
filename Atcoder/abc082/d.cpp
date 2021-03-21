// abc082_d
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S;
    cin >> S;
    int x, y;
    cin >> x >> y;

    vector<pair<char, int>> T;
    REP(i, S.size()){
        int num = 1;
        while (i < S.size()-1 && S[i] == S[i+1]){ num++; i++;}
        T.emplace_back(S[i], num);
    }

//    print(T);

    vector<vector<int>> v(2);
    int side = 0;
    int first_move_fix = false;
    REP(i, T.size()){
        if (T[i].first == 'F'){
            if (i == 0){
                first_move_fix = true;
            }
            v[side].emplace_back(T[i].second);
        } else {
            if (T[i].second % 2 == 1){
                side = 1 - side;
            }
        }
    }

//    print(v);

    int H = 16002;
    int m = H/2;

    bool ok = true;
    REP(k, 2){
        int t = vector<int>{x, y}[k];

        vector<bool> dp(H, false);
        dp[m] = true;

        REP(i, v[k].size()){
            vector<bool> prev(H);
            swap(prev, dp);

            REP(j, H){
                if (not prev[j]) continue;
                dp[j + v[k][i]] = true;
                if (not (k==0 && first_move_fix && i==0)) dp[j - v[k][i]] = true;
            }
        }
        ok &= dp[m+t];
    }

    print(ok ? "Yes" : "No");


    return 0;
}
