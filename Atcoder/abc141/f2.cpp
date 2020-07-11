// abc141_f
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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


ull func(vector<ull> a){
    int n = a.size();
    int rank = 0;
    REP_REV(i, 60) {
        int j;
        for (j = rank; j < n; j++) {
            if (a[j] & (1ull << i)) break;
        }
        if (j == n) continue;

        if (j > rank) a[rank] ^= a[j];

        for (j = 0; j < n; j++) {
            if (j == rank) continue;
            if (a[j] & (1ull << i)) a[j] ^= a[rank];
        }

        rank++;
    }
    ull x = 0;
    REP(i, n) {
        x ^= a[i];
    }

    return x;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<ull> A(N);
    REP(i, N) cin >> A[i];

    ull allxor = 0;
    REP(i, N) allxor ^= A[i];
    REP(i, N) A[i] &= ~allxor;

    ull res = allxor + 2 * func(A);
    print(res);

    return 0;
}
