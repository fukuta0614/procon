// abc059_c
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
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

//    print(A);

    ll tmp = 0;
    ll cand1 = 0;
    REP(i, N) {
        tmp += A[i];
//        print(i, A[i], tmp);
        if (tmp == 0 || (i % 2 == 0) != (tmp > 0)){
            ll next_tmp = (i % 2 == 0) ? 1 : -1;
            cand1 += abs(tmp - next_tmp);
            tmp = next_tmp;
        }
//        print("cand1", cand1);
    }

    ll cand2 = 0;
    tmp = 0;
    REP(i, N) {
        tmp += A[i];
//        print(i, A[i], tmp);
        if (tmp == 0 || (i % 2 == 0) != (tmp < 0)){
            ll next_tmp = (i % 2 == 0) ? -1 : 1;
            cand2 += abs(tmp - next_tmp);
            tmp = next_tmp;
        }
//        print("cand2", cand2);
    }

    ll ans = min(cand1, cand2);
    print(ans);

    return 0;
}
