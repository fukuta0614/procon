// abc081_d
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

#define INF (ll)(1e9)
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

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    int max_p = 0;
    int max_p_idx = 0;
    int max_n = 0;
    int max_n_idx = 0;
    REP(i, N){
        if (A[i] > max_p){
            max_p = A[i];
            max_p_idx = i;
        }
        if (A[i] < max_n){
            max_n = A[i];
            max_n_idx = i;
        }
    }
//    print(max_p, max_p_idx, max_n, max_n_idx);

    vector<pair<int,int>> ans;

    bool plus = max_p > (abs(max_n));
    if (plus) {
        REP(i, N) ans.emplace_back(max_p_idx, i);
        REP(i, N-1) ans.emplace_back(i, i+1);
    } else {
        REP(i, N) ans.emplace_back(max_n_idx, i);
        REPN_REV(i, 1, N) ans.emplace_back(i, i-1);
    }

//    print(A);
//    print(ans);

    print(ans.size());
    for (auto [a,b] : ans){
        print(a+1, b+1);
//        A[b] += A[a];
//        print(A);
    }

    return 0;
}
