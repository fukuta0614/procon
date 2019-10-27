// edpc_b
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

#define INF (int)(2e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int N, K;
vector<int> H;
vector<int> memo;
//map<int, int> memo;

int dp_func(int i){

    if (i == N-1) return 0;

//    if (memo.find(i) != memo.end()) return memo[i];
//    if (memo.count(i)) return memo[i];
    if (memo[i] != -1) return memo[i];

    int tmp = INF;
    REPN(k, 1, K+1) {
        if (i + k >= N) break;
        tmp = min(tmp, dp_func(i+k) + abs(H[i] - H[i+k]));
    }

    return memo[i] = tmp;
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> K;
    H.assign(N, 0);
    REP(i, N) cin >> H[i];

    memo.assign(N, -1);

    int ans = dp_func(0);
    print(ans);

    return 0;
}

