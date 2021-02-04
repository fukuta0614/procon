// abc181_e
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

    int N, M;
    cin >> N >> M;

    vector<ll> H(N), W(M);
    REP(i, N) cin >> H[i];
    REP(i, M) cin >> W[i];
    sort(ALL(H));
    sort(ALL(W));

    vector<ll> diff(N);
    REP(i, N-1){
        diff[i] = H[i+1] - H[i];
    }
//    print(diff);

    vector<ll> diff_sumA(N);
    vector<ll> diff_sumB(N);

    REP(i, N){
        if (i == 0) {
            diff_sumA[i] = diff[i];
            diff_sumB[i] = 0;
        } else if (i == 1){
            diff_sumA[i] = diff_sumA[i-1];
            diff_sumB[i] = diff[i];
        } else if (i % 2 == 0){
            diff_sumA[i] = diff_sumA[i-1] + diff[i];
            diff_sumB[i] = diff_sumB[i-1];
        } else {
            diff_sumA[i] = diff_sumA[i-1];
            diff_sumB[i] = diff_sumB[i-1] + diff[i];
        }
    }

//    print(diff_sumA);
//    print(diff_sumB);

    ll ans = INF;
    int idx = 0;
    REP(i, N){
        if (i % 2 == 1) continue;

        ll tmp = 0;
        if (i > 0) tmp += diff_sumA[i-1];
        if (i < N) tmp += diff_sumB[N-1] - diff_sumB[i];

        while (idx < M-1 && W[idx] <= H[i]){
            ans = min(ans, tmp + abs(H[i] - W[idx]));
            idx++;
        }

        ans = min(ans, tmp + abs(H[i] - W[idx]));
    }

    print(ans);

    return 0;
}
