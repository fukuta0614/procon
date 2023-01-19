// arc121_b
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

#define INF (ll)(1e18)
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
    map<char, int> mp{{'R',0}, {'G', 1}, {'B', 2}};
    vector<vector<ll>> v(3);
    REP(i, 2*N){
        ll a; char c;
        cin >> a >> c;
        v[mp[c]].emplace_back(a);
    }

    vector<ll> A, B;
    REP(i, 3){
        if (v[i].size() % 2 != 0){
            if (A.empty()){
                A = v[i];
            } else {
                B = v[i];
            }
        }
    }

    if (A.empty() && B.empty()){
        print(0);
        return 0;
    }

    assert(not A.empty() || not B.empty());

    vector<ll> C;
    REP(i, 3){
        if (v[i] != A and v[i] != B){
            C = v[i];
        }
    }

    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(C));

    ll ans = INF;
    for (auto a: A){
        auto idx = lower_bound(ALL(B), a) - B.begin();
        if (idx < B.size()){
            ans = min(ans, abs(B[idx] - a));
        }
        if (idx > 0){
            ans = min(ans, abs(B[idx-1] - a));
        }
    }

    {
        ll tmp1=INF, tmp2=INF;
        for (auto a: A){
            auto idx = lower_bound(ALL(C), a) - C.begin();
            if (idx < C.size()){
                tmp1 = min(tmp1, abs(C[idx] - a));
            }
            if (idx > 0){
                tmp1 = min(tmp1, abs(C[idx-1] - a));
            }
        }

        for (auto b: B){
            auto idx = lower_bound(ALL(C), b) - C.begin();
            if (idx < C.size()){
                tmp2 = min(tmp2, abs(C[idx] - b));
            }
            if (idx > 0){
                tmp2 = min(tmp2, abs(C[idx-1] - b));
            }
        }
        ans = min(ans, tmp1 + tmp2);
    }


    print(ans);

    return 0;
}
