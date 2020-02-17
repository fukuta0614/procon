// abc150_d
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

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i]; A[i] /= 2;
    }

    ll lcm=0;
    REP(i, N){
        if (i == 0){
            lcm = A[i];
        } else {
            ll d = gcd(lcm, A[i]);
            lcm = A[i] * lcm / d;
        }
    }
//    print(lcm);

    bool x = true;
    REP(i, N){
        if ( (lcm / A[i]) % 2 == 0){
            x = false;
            break;
        }
    }

    ll ans;
    if (x) {
        ans = (M + lcm) / (2 * lcm);
    } else {
        ans = 0;
    }

    print(ans);

    return 0;
}
