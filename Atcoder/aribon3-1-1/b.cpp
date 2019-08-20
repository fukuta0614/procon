// aribon3-1-1_b
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

int N, K;
vector<ll> A, B;

bool is_valid(ll x){

    int sm = 0;
    REP(i, N){
        ll a = A[i];

        if (x < a * B[0]) {
            break;
        }

        if (a * B[N-1] <= x) {
            sm += N;
            continue;
        }
        int ok = 0;
        int ng = N - 1;
        while (ng - ok > 1){
            int mid = (ok + ng) / 2;
            if (a * B[mid] <= x){
                ok = mid;
            } else {
                ng = mid;
            }
        }
        sm += ok + 1;
    }

    return sm >= K;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> K;

    A.resize(N);
    B.resize(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    sort(ALL(A));
    sort(ALL(B));


    ll ng = -1;
    ll ok = 1ll << 60;
    while (ok - ng > 1){

        ll mid = (ok + ng) / 2;

        // xより小さい数がK個あるかどうか
        if (is_valid(mid)){
            ok = mid;
        } else {
            ng = mid;
        }
    }

    print(ok);

    return 0;
}
