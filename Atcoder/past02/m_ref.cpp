// past02_m
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

#define INF (ll)(1e9)
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


        ll D, L, N;
        cin >> D >> L >> N;
        vector<ll> C(D);
        REP(i, D) cin >> C[i];

        C.resize(2 * D);
        REP(i, D) C[i + D] = C[i];
        constexpr int MX = 100000;
        vector<vector<ll>> poss(MX), counts(MX);
        vector<ll> loops(MX);
        REP(i, 2 * D) { poss[C[i] - 1].push_back(i); }
        REP(i, MX) {
            if (poss[i].empty()) continue;
            counts[i].resize(poss[i].size());
            counts[i][0] = 1;
            REP(j, poss[i].size() - 1) {
                counts[i][j + 1] = counts[i][j] + (poss[i][j + 1] - poss[i][j] - 1) / L + 1;
            }
            loops[i] = counts[i][poss[i].size() / 2] - counts[i][0];

//            print(i);
//            print(poss[i]);
//            print(counts[i]);
//            print(loops[i]);
        }

        REP(i, N) {
            ll K, F, T;
            cin >> K >> F >> T;
            K--;
            F--;
            if (poss[K].empty()) {
                print(0);
            } else {
                auto fi = lower_bound(ALL(poss[K]), F);
                ll first = *fi;
                ll waste = (first - F + L - 1) / L;
                T -= waste;
                print(i, T);

                if (T <= 0) {
                    print(0);
                } else {
                    ll ans = 0;
                    ll dec = T / loops[K];
                    ans += dec * (poss[K].size() / 2);
                    T %= loops[K];
                    // debug("dec", dec, fi - poss[K].begin(), T, ans);
                    auto nxt = lower_bound(ALL(counts[K]), counts[K][fi - poss[K].begin()] + T);
                    ans += nxt - counts[K].begin() - (fi - poss[K].begin());
                    print(ans);
                }
            }
        }

    return 0;
}
/*
 *
0
[4, 5, 9, 14, 15, 19, 24, 25, 29]
[1, 2, 3, 5, 6, 7, 9, 10, 11]
4
1
[7, 8, 17, 18, 27, 28]
[1, 2, 5, 6, 9, 10]
4
2
[3, 13, 23]
[1, 4, 7]
3
3
[0, 1, 2, 10, 11, 12, 20, 21, 22]
[1, 2, 3, 5, 6, 7, 9, 10, 11]
4
4
[6, 16, 26]
[1, 4, 7]
3
1
5
1
6
 */