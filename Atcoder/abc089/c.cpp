// abc089_c
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

struct CombinationGenerator {
    ll sup, ret;
    bool first;
    CombinationGenerator(int n, int k): sup(1ll<<n), ret((1ll<<k)-1) {first = true;}
    ll operator()(){
        if (first) {first = false; return ret;}
        if (ret == 0) return -1;
        ll x = ret & -ret, y = ret + x;
        ret = ((ret & ~y) / x >> 1) | y;
        return ret < sup ? ret : -1;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    map<char, int> mp{{'M',0},{'A',1},{'R',2}, {'C', 3}, {'H',4}};
    vector<int> cnt(5);
    REP(i, N){
        string s; cin >> s;
        if (mp.find(s[0]) != mp.end()){
            cnt[mp[s[0]]]++;
        }
    }

    ll ans = 0;
    CombinationGenerator g(5, 3);
    while (true){
        ll mask = g();
        if (mask < 0) break;

        ll tmp = 1;
        REP(p, 5) if (mask & (1 << p)) {
            tmp *= cnt[p];
        }
        ans += tmp;
    }

    print(ans);


    return 0;
}
