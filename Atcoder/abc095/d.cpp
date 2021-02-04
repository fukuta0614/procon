// abc095_d
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

#define INF (ll)(1e9)
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

    ll N, C;
    cin >> N >> C;
    vector<ll> X(N), V(N);
    REP(i, N) cin >> X[i] >> V[i];

    vector<ll> cw(N), ccw(N);
    ll sm = 0;
    REP(i, N){
        sm += V[i];
        cw[i] = sm - X[i];
    }

    sm = 0;
    REP_REV(i, N){
        sm += V[i];
        ccw[i] = sm - (C - X[i]);
    }
//
//    print(cw);
//    print(ccw);

    ll ans = 0;
    ll tmp = 0;
    ll ccw_mx = 0;
    REP_REV(i, N){
        tmp = cw[i];
        ans = max(ans, tmp);
        if (i != N-1){
            tmp -= X[i];
            ccw_mx = max(ccw_mx, ccw[i+1]);
            tmp += ccw_mx;
        }
        ans = max(ans, tmp);
    }
    tmp = max(ccw_mx, ccw[0]);
    ans = max(ans, tmp);

    ll cw_mx = 0;
    REP(i, N){
        tmp = ccw[i];
        ans = max(ans, tmp);
        if (i != 0){
            tmp -= C - X[i];
            cw_mx = max(cw_mx, cw[i-1]);
            tmp += cw_mx;
        }
        ans = max(ans, tmp);
    }
    tmp = max(cw_mx, cw[N-1]);
    ans = max(ans, tmp);

    print(ans);

    return 0;
}
