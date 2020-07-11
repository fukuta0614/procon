// agc044_a
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

ll N, A, B, C, D;
map<ll, ll> memo;

ll dfs(ll n){

    if (memo.find(n) != memo.end()){
        return memo[n];
    }

    ll tmp = 1e18;
    if (n < tmp / D) tmp = n * D;

    ll a = n - n % 2;
    tmp = min(tmp, D * (n % 2) + A + dfs(a/2));
    if (n % 2) tmp = min(tmp, D * (2 - (n % 2)) + A + dfs(a/2+1));

    ll b = n - n % 3;
    tmp = min(tmp, D * (n % 3) + B + dfs(b/3));
    if (n % 3) tmp = min(tmp, D * (3 - (n % 3)) + B + dfs(b/3+1));

    ll c = n - n % 5;
    tmp = min(tmp, D * (n % 5) + C + dfs(c/5));
    if (n % 5) tmp = min(tmp, D * (5 - (n % 5)) + C + dfs(c/5+1));

    return memo[n] = tmp;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;
    REP(_, T){
        cin >> N >> A >> B >> C >> D;
        memo.clear();
        memo[1] = D;
        memo[0] = 0;
        ll ans = dfs(N);
        print(ans);
    }

    return 0;
}
