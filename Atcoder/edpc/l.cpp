// edpc_l
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

#define INF (numeric_limits<ll>::max())
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int N;
vector<ll> A;
vector<vector<ll>> memo;

ll dp(int l, int r){

    if (l == r) return N & 1 ? A[l] : -A[l];
    if (l+1 == r) return N & 1 ? min(A[l] - A[r], A[r] - A[l]) : max(A[l] - A[r], A[r] - A[l]);

    if (memo[l][r] != INF) return memo[l][r];

    ll a = A[l] + min(-A[l+1] + dp(l+2, r), -A[r] + dp(l+1, r-1));
    ll b = A[r] + min(-A[l] + dp(l+1, r-1), -A[r-1] + dp(l, r-2));
    ll ret = max(a, b);

    return memo[l][r] = ret;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif


    cin >> N;
    A.assign(N, 0);
    REP(i, N) cin >> A[i];

    memo.assign(N, vector<ll>(N, INF));

    ll ret = dp(0, N-1);
    print(ret);

    return 0;
}
