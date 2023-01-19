// abc250_c
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

#define print_line1(vec, n) {for(int idx=1;idx<(n);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)] << endl;}

template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N+1);
    iota(ALL(arr), 0);

    unordered_map<int, int> arr_rev;
    REP(i, N+1){
        arr_rev[i] = i;
    }

    REP(i, Q){
        int x;
        cin >> x;

        int x_idx = arr_rev[x];
        int y_idx = x_idx == N ? x_idx - 1 : x_idx + 1;

        int y = arr[y_idx];

        swap(arr[x_idx], arr[y_idx]);
        swap(arr_rev[x], arr_rev[y]);
    }

    print_line1(arr, N);


    return 0;
}
