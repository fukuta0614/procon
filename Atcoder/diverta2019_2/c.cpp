// diverta2019_2_c
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

#define INF ((1 << 30)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    vector<int> A(N);
    REP(i, N) cin >> A[i];
    sort(ALL(A));

    int sm = accumulate(ALL(A), 0);

    int ans = -INF;
    int split_idx = -1;
    int tmp_sm = 0;
    REP(i, N-1){
        tmp_sm += A[i];
        if (sm - 2 * tmp_sm >= ans) {
            ans = sm - 2 * tmp_sm;
            split_idx = i;
        }
    }

    print(ans);

    int x = A[0];
    REPN(i, split_idx+1, N-1){
        printf("%d %d\n", x, A[i]);
        x -= A[i];
    }

    print(A[N-1], x);
    x = A[N-1] - x;

    REPN(i, 1, split_idx+1){
        printf("%d %d\n", x, A[i]);
        x -= A[i];
    }


    return 0;
}
