// abc132_f
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
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    ll N, K;
    cin >> N >> K;

    ll sqrt_n = (ll)sqrt(N);
    set<ll> st;
    REPN(i, 1, sqrt_n+1){
        st.insert(i);
        st.insert(N/i);
    }
    ll n = st.size();

    vector<ll> nums(ALL(st));

    vector<ll> cnt(n);
    cnt[0] = 1;
    REP(i, n - 1){
        cnt[n-i-1] = nums[n-i-1] - nums[n - i - 2];
        cnt[n-i-1] %= MOD;
    }

    vector<ll> dp(n);
    dp[0] = 1;

    REP(k, K){
        vector<ll> prev = dp;
        ll sm = 0;
        REP(i, n) {
            sm = (sm + prev[i]) % MOD;
            dp[n-1-i] = (sm * cnt[n-1-i]) % MOD;
        }
    }

    ll ans = 0;
    REP(i, n){
        ans += dp[i];
        ans %= MOD;
    }
    print(ans);




    return 0;
}