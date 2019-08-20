// aribon3-1-4_d
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


struct BIT {
    int sz;
    vector<int> tree;

    BIT(int n) {
        sz = n;
        tree.resize(n+1);
    }

    ll sum(int i){
        ll sm = 0;
        while (i > 0){
            sm += tree[i];
            i -= i & -i;
        }
        return sm;
    }

    void add(int i, int x){
        while (i <= sz){
            tree[i] += x;
            i += i & -i;
        }
    }
};



int main() {
#ifdef LOCAL
    ifstream in("../b05.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, K;
    cin >> N >> K;

    vector<ll> A(N);
    int a;
    REP(i, N) {
        cin >> a;
        A[i] = a - K;
    }

    vector<ll> cumsum(N+1, 0);
    REP(i, N){
        cumsum[i+1] += A[i] + cumsum[i];
    }

    vector<int> cumsum_zip(N+1);
    iota(ALL(cumsum_zip), 1);
    stable_sort(ALL(cumsum_zip), [&](int i, int j){
        return cumsum[i-1] < cumsum[j-1];
    });

    auto bit = BIT(N+2);
    ll ans = 0;
    REP(i, N+1){
        ans += bit.sum(cumsum_zip[i]);
        bit.add(cumsum_zip[i], 1);
    }

    print(ans);

    return 0;
}
