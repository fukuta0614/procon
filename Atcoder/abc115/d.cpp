// abc115_d
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



int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, X;
    cin >> N >> X;

    vector<ll> B(N+1), P(N+1);

    B[0] = 1;
    P[0] = 1;
    REP(i, N) {
        B[i + 1] = 2 * B[i] + 3;
        P[i + 1] = 2 * P[i] + 1;
    }

    int i = N;
    ll ans = 0;
    while (true){
        if (X == 1){
            if (i == 0) ans++;
            ans += 0;
            break;
        } else if (X <= B[i-1] + 1){
            X -= 1;
            ans += 0;
        } else if (X == B[i-1] + 2){
            ans += P[i-1] + 1;
            break;
        } else if (X <= 2 * B[i-1] + 2){
            X -= B[i-1] + 2;
            ans += P[i-1] + 1;
        } else {
            ans += 2 * P[i-1] + 1;
            break;
        }
        i--;
    }

    print(ans);


    return 0;
}
