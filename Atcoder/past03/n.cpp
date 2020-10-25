// past03_n
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

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    iota(ALL(A), 1);
    set<int> swaped{N};

    auto swap_func = [&](int x){
        swap(A[x], A[x+1]);
        for (int i = x-1; i <= x+1; ++i) {
            if (i < 0 || N-1 <= i) continue;
            if (A[i] > A[i+1]){
                swaped.insert(i);
            } else {
                swaped.erase(i);
            }
        }

    };

    REP(_, Q){
        int t, x, y;
        cin >> t >> x >> y;
        x--; y--;
        if (t == 1){
            swap_func(x);
        } else {
            int i;
            while (true){
                i = *swaped.lower_bound(x);
                if (y <= i || N-1 <= i) break;
                swap_func(i);
            }
        }
    }

    print_line(A, N);

    return 0;
}
