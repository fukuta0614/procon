// abc138_e
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
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S, T;
    cin >> S >> T;

    map<char, vector<int>> mp_s;
    REP(i, S.size()){
        char c = S[i];
        mp_s[c].emplace_back(i);
    }

    REP(i, T.size()){
        char c = T[i];
        if (mp_s[c].empty()) {
            print(-1);
            return 0;
        }
    }
//    print(mp_s);

    int idx = -1;
    ll ans = 0;
    REP(i, T.size()){
        char c = T[i];
        auto it = upper_bound(ALL(mp_s[c]), idx);
        if (it != mp_s[c].end()){
            idx = *it;
        } else {
            idx = mp_s[c][0];
            ans += S.size();
        }
    }
    ans += idx + 1;
    print(ans);

    return 0;
}
