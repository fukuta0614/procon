// abc206_f
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

vector<vector<int>> memo;
int N;
vector<int> L, R;

int grundy(int l, int r){
    if (memo[l][r] != -1) return memo[l][r];

    set<int> s;
    REP(i, N){
        if (l <= L[i] && R[i] <= r){
            int tmp = grundy(l, L[i]) ^ grundy(R[i], r);
            s.emplace(tmp);
        }
    }

    int g = 0;
    while (s.find(g) != s.end()) g++;

    return memo[l][r] = g;

}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;
    while (T--){
        cin >> N;
        L.assign(N, 0);
        R.assign(N, 0);
        REP(i, N) cin >> L[i] >> R[i];
        memo.assign(101, vector<int>(101, -1));

        int g = grundy(0, 100);

        if (g != 0){
            print("Alice");
        } else {
            print("Bob");
        }
    }

    return 0;
}
