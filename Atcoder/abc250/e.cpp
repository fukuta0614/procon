// abc250_e
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

#define INF (ll)(1e9)
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

    int N, Q;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    vector<int> B(N);
    REP(i, N) cin >> B[i];

    map<int, int> rev_mapA;
    REP_REV(i, N) rev_mapA[A[i]] = i;

    map<int, int> rev_mapB;
    REP_REV(i, N) rev_mapB[B[i]] = i;

    vector<int> tableA(N);
    REP(i, N){
        if (rev_mapB.find(A[i]) != rev_mapB.end()){
            tableA[i] = rev_mapB[A[i]];
        } else {
            tableA[i] = INF;
        }
    }

    vector<int> tableB(N);
    REP(i, N){
        if (rev_mapA.find(B[i]) != rev_mapA.end()){
            tableB[i] = rev_mapA[B[i]];
        } else {
            tableB[i] = INF;
        }
    }

    vector<int> max_tableA(N);
    REP(i, N){
        if (i == 0) {
            max_tableA[i] = tableA[i];
        } else {
            max_tableA[i] = max(max_tableA[i-1], tableA[i]);
        }
    }
    vector<int> max_tableB(N);
    REP(i, N){
        if (i == 0) {
            max_tableB[i] = tableB[i];
        } else {
            max_tableB[i] = max(max_tableB[i-1], tableB[i]);
        }
    }

//    print(max_tableA);
//    print(max_tableB);

    cin >> Q;
    REP(i, Q){
        int x, y;
        cin >> x >> y;
        x--; y--;

        if (max_tableA[x] <= y and max_tableB[y] <= x){
            print("Yes");
        } else {
            print("No");
        }
    }

    return 0;
}
