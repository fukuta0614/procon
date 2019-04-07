// abc123_d
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    ull X,Y,Z,K;
    cin >> X >> Y >> Z >> K;

    ull A[1000],B[1000],C[1000];
    REP(i, X) cin >> A[i];
    REP(i, Y) cin >> B[i];
    REP(i, Z) cin >> C[i];

    vector<ull> ab{};
    REP(i, X) REP(j, Y) ab.emplace_back(A[i] + B[j]);
    sort(ALL(ab));

    int k, sz;
    sz = (int) ab.size();
    k = min(sz, 3000);
    vector<ull> abc{};
    REPN_REV(i, sz-k, sz) REP(j, Z) abc.emplace_back(ab[i] + C[j]);
    sort(ALL(abc));

    sz = (int) abc.size();
    k = min(sz, (int)K);
    REPN_REV(i, sz-k, sz) print(abc[i]);

    return 0;
}
