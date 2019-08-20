// aribon2-3-7_b
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll pf[101][1001];

ll solve(vector<int>& A, vector<int>& B){
    int sm = 0;
    REP(i, B.size()) sm += B[i];

    map<int, int> kg_map;
    for (auto k : A) kg_map[k]++;
    vector<int> kg;
    for(auto item: kg_map) kg.emplace_back( item.second );

    vector<vector<ll>> dp;
    dp.assign(kg.size() + 1, vector<ll>(sm + 1, 0));
    dp[0][0] = 1;
    REP(i, kg.size()) {
        REP(j, sm + 1) {
            REP(k, sm - j + 1) {
                dp[i + 1][j + k] += dp[i][j] * pf[kg[i]][k];
                dp[i + 1][j + k] %= MOD;
            }
        }
    }
    return dp[kg.size()][sm];
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    // jをi分割
    pf[0][0] = 1;
    REPN(i, 1, 101) REPN(j, 0, 1001){
        pf[i][j] = pf[i-1][j] + (j-i>=0 ? pf[i][j-i] : 0);
        pf[i][j] %= MOD;
    }

    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    REP(i, N) cin >> A[i];
    REP(i, M) cin >> B[i];

    ll a = solve(A, B);
    ll b = solve(B, A);

    print(a * b % MOD);

    return 0;
}
