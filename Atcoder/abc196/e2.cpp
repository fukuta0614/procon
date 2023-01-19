// abc196_e
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

void solve(){
    ll N;
    cin >> N;
    vector<ll> A(N), T(N);
    REP(i, N) cin >> A[i] >> T[i];

    ll Q;
    cin >> Q;
    vector<ll> X(Q);
    REP(i, Q) cin >> X[i];

    ll sm = 0;
    ll sup=INF, inf=-INF;
    REP(i, N){

        if (T[i] == 1){
            sm += A[i];
            sup += A[i];
            inf += A[i];
        } else if (T[i] == 2){
            inf = max(inf, A[i]);
            sup = max(sup, A[i]);
        } else {
            sup = min(sup, A[i]);
            inf = min(inf, A[i]);
        }
    }

    REP(i, Q){
        ll ans = max(min(X[i] + sm, sup), inf);
        print(ans);
    }
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    solve();

    return 0;
}