// arc121_a
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

    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    vector<tuple<int, int, int>> p(N), q(N);
    REP(i, N) {
        cin >> X[i] >> Y[i];
        p[i] = {X[i], Y[i], i};
        q[i] = {Y[i], X[i], i};
    }
    sort(ALL(p));
    sort(ALL(q));


    vector<tuple<int, int, int>> v;

    auto f = [&](int i, int j){
        auto [x1, y1, idx1] = p[i];
        auto [x2, y2, idx2] = p[j];
        return tuple<int, int, int>{abs(x1 - x2), idx1, idx2};
    };

    auto g = [&](int i, int j){
        auto [y1, x1, idx1] = q[i];
        auto [y2, x2, idx2] = q[j];
        return tuple<int, int, int>{abs(y1 - y2), idx1, idx2};
    };

    v.emplace_back(f(0, N-1));
    v.emplace_back(f(0, N-2));
    v.emplace_back(f(1, N-1));
    v.emplace_back(g(0, N-1));
    v.emplace_back(g(0, N-2));
    v.emplace_back(g(1, N-1));

    sort(ALL(v), greater<>());

    auto [s, i1, j1] = v[0];
    auto [t, i2, j2] = v[1];

    int ans;
    if (i1 == i2 && j1 == j2) {
        ans = get<0>(v[2]);
    } else {
        ans = get<0>(v[1]);
    }

    print(ans);

    return 0;
}
