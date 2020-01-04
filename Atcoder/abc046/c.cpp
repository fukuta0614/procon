// abc046_c
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

#define INF ((1 << 29)-1)
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
    vector<ll> T(N), A(N);
    REP(i, N) cin >> T[i] >> A[i];

    ll t=T[0], a=A[0];
    REPN(i, 1, N){
//        print(t, a);
//        ll x = T[i];
//        ll y = A[i];
//        while (not (t <= x && a <=y)){
//            x += T[i];
//            y += A[i];
//        }
        ll x = ((t + T[i] - 1) / T[i]);
        ll y = ((a + A[i] - 1) / A[i]);
        ll z = max(x, y);

        t = T[i] * z;
        a = A[i] * z;
    }
    ll ans = t + a;
    print(ans);


    return 0;
}
