// abc150_c
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

    int N;
    cin >> N;
    vector<int> P(N);
    REP(i, N) cin >> P[i];
    vector<int> Q(N);
    REP(i, N) cin >> Q[i];

    vector<int> A(N);
    iota(ALL(A), 1);

    int a=0, b=0;
    int k = 0;
    do {
        bool same;

        same = true;
        REP(i, N){
            if (A[i] != P[i]) {
                same = false;
                break;
            }
        }
        if (same) a = k;

        same = true;
        REP(i, N){
            if (A[i] != Q[i]) {
                same = false;
                break;
            }
        }
        if (same) b = k;

        k++;

    } while( next_permutation(ALL(A)));


    int ans = abs(a - b);
    print(ans);

    return 0;
}
