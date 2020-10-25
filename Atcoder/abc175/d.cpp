// abc175_d
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

    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    REP(i, N) {cin >> P[i]; P[i]--;}
    vector<ll> C(N);
    REP(i, N) cin >> C[i];

    vector<int> loop_idx(N, -1);
    int idx = 0;
    vector<vector<ll>> loops;
    REP(i, N){

        if (loop_idx[i] != -1){
            continue;
        }

        int x = i;
        vector<ll> loop;
        while (loop_idx[x] == -1){
            loop_idx[x] = idx;
            x = P[x];
            loop.emplace_back(C[x]);
        }
        loops.emplace_back(loop);
        idx++;
    }

//    print(loops);

    ll ans = -INF;
    for (auto& loop: loops){

        ll sm = accumulate(ALL(loop), 0ll);
        sm = max(sm, 0ll);
        int n = loop.size();

        REP(i, n){
            loop.emplace_back(loop[i]);
        }

        REP(i, n) {
            ll tmp = 0;
            REP(j, n) {
                if (j >= K) break;

                tmp += loop[i + j];
                int res = K - j - 1;
                ans = max(ans, tmp + sm * (res / n));
//                print(i, j, tmp, sm * (res/n));
            }
        }
//        print(loop, ans);
    }

    print(ans);


    return 0;
}
