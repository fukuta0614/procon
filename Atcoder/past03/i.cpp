// past03_i
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
    ll N, Q;
    cin >> N >> Q;

    bool transpose = false;
    vector<ll> C(N), R(N);
    iota(ALL(C), 0);
    iota(ALL(R), 0);
    REP(q, Q){

        int t; cin >> t;

        if (t == 1){
            int a, b; cin >> a >> b;
            a--; b--;
            if (transpose){
                swap(C[a], C[b]);
            } else {
                swap(R[a], R[b]);
            }
//            print("swap 1");
        } else if (t == 2){
            int a, b; cin >> a >> b;
            a--; b--;
            if (transpose){
                swap(R[a], R[b]);
            } else {
                swap(C[a], C[b]);
            }
//            print("swap 2");
        } else if (t == 3){
            transpose = not transpose;
//            print("transpose");
        } else {
            int a, b; cin >> a >> b;
            a--; b--;
            ll ans = 0;
            if (transpose){
                ans = R[b] * N + C[a];
            } else {
                ans = R[a] * N + C[b];
            }
//            print(R, C, a, b, transpose);
            print(ans);
        }
    }

    return 0;
}
