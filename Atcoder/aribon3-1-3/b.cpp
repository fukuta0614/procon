// aribon3-1-3_b
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

int N;
vector<ll> A;
vector<ll> cumsum;


bool subproblem(ll x){

    REP(i, N){
        auto begin_it = cumsum.begin() + i;
        auto end_it = begin_it + N;

        auto it1 = lower_bound(begin_it, end_it, x + *begin_it);
        auto it2 = lower_bound(it1, end_it, x + *it1);

        if (*end_it - *it2 >= x){
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N;
    A.resize(2 * N);
    cumsum.resize(2 * N + 1);

    REP(i, N) {
        ll a;
        cin >> a;
        A[i] = A[N+i] = a;
    }

    REP(i, 2 * N){
        cumsum[i + 1] = cumsum[i] + A[i];
    }

    ll ok = 0;
    ll ng = cumsum[N];

    while (ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if (subproblem(mid)){
            ok = mid;
        } else {
            ng = mid;
        }
    }
    print(ok);

    return 0;
}
