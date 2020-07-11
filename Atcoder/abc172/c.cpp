// abc172_c
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    vector<ll> cumsumA(N+1), cumsumB(M+1);
    REP(i, N) {
        cin >> A[i];
        cumsumA[i+1] = cumsumA[i] + A[i];
    }
    REP(i, M) {
        cin >> B[i];
        cumsumB[i+1] = cumsumB[i] + B[i];
    }

//    print(cumsumA, cumsumB);

    ll ans = 0;
    REPN(i, 0, N+1){
        ll k = K - cumsumA[i];
        if (k < 0) continue;

        ll x = upper_bound(ALL(cumsumB), k) - cumsumB.begin();
//        print(i, k, x-1);
        ans = max(ans, i + x-1);
    }
    print(ans);



    return 0;
}
