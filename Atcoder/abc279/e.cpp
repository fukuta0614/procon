// abc279_e
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
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    REP(i, M) {cin >> A[i]; A[i]--;}

    int base = 0;

    vector<int> root(M, -1); // -1じゃない場合、そいつとSが同じ
    vector<int> index(N, -1); // 今Sがiになってるやつのindex
    REP(i, M){
        swap(index[A[i]], index[A[i]+1]);

        if (index[base] == -1){
            index[base] = i;
        } else {
            root[i] = index[base];
        }

        if (A[i] == base){
            base++;
        } else if (A[i] == base - 1){
            base--;
        }
    }

    vector<int> ans(M);
    REP(i, N){
        if (index[i] != -1){
            ans[index[i]] = i+1;
        }
    }
    REP(i, M){
        if (root[i] == -1) {
            print(ans[i]);
        } else {
            print(ans[root[i]]);
        }
    }

    return 0;
}
