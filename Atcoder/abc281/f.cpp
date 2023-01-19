// abc281_f
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

ll func(const vector<ll>& x, int d){
    vector<ll> a, b;
    auto idx = lower_bound(ALL(x), 1 << d) - x.begin();
    ll mask = (1 << d) - 1;
    REP(i, x.size()){
        if (i < idx) a.emplace_back(x[i] & mask);
        else b.emplace_back(x[i] & mask);
    }
//    print(d, x);
//    print(a);
//    print(b);

    ll ret = 0;
    if (a.empty()){
        if (d == 0) ret = 0;
        else ret = func(b, d-1);
    } else if (b.empty()){
        if (d == 0) ret = 0;
        else ret = func(a, d-1);
    } else {
        if (d == 0) ret = 1;
        else ret = (1 << d) + min(func(a, d-1), func(b, d-1));
    }
    return ret;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    sort(ALL(A));

    ll ans = func(A, 30);
    print(ans);

    return 0;
}
