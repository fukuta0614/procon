// Round641_c
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

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    vector<ll> gcd_l(N+1, 0), gcd_r(N+1, 0);
    REP(i, N){
        gcd_l[i+1] = gcd(gcd_l[i], A[i]);
        gcd_r[i+1] = gcd(gcd_r[i], A[N-i-1]);
    }

//    print(gcd_l);
//    print(gcd_r);

    vector<ll> gcd_rest(N);
    REP(i, N){
        gcd_rest[i] = gcd(gcd_l[i], gcd_r[N-i-1]);
    }

//    print(gcd_rest);

    ll lcm = 1;
    REP(i, N){
        lcm = (lcm * gcd_rest[i]) / gcd(lcm, gcd_rest[i]);
    }

    print(lcm);

    return 0;
}
