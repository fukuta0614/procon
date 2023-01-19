// tessoku_a_021
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

vector<int> P, A;
vector<vector<int>> memo;

int func(int l, int r){

    if (memo[l][r] != -1){
        return memo[l][r];
    }
    if (l == r){
        return 0;
    }

    int a = func(l, r-1) + ((l <= P[r] && P[r] <= r) ?  A[r] : 0);
    int b = func(l+1, r) + ((l <= P[l] && P[l] <= r) ?  A[l] : 0);

    return memo[l][r] = max(a, b);
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    P.assign(N, 0);
    A.assign(N, 0);
    REP(i, N) {cin >> P[i] >> A[i]; P[i]--;}

    memo.assign(N, vector<int>(N, -1));
    int ans = func(0, N-1);
    print(ans);

    return 0;
}
