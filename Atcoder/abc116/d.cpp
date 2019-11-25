// abc116_d
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, ll> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
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

    ll N, K;
    cin >> N >> K;
    vector<P> sushi(N);
    REP(i, N) {
        cin >> sushi[i].first >> sushi[i].second;
        sushi[i].first--;
    }

    sort(ALL(sushi), [](const P& a, const P& b){
        return a.second > b.second;
    });

    priority_queue<ll, vector<ll>, greater<ll>> pq_already;
    priority_queue<ll> pq_notyet;
    vector<ll> dp(N+1);

    // 各ネタごとに美味しさ順に
    vector<vector<ll>> values(N);
    REP(i, N){ values[sushi[i].first].emplace_back(i); }

    // 上位K個使ったときの種類と値
    ll sm = 0;
    set<int> kinds;
    REP(i, K){
        sm += sushi[i].second;
        kinds.insert(sushi[i].first);

        // すでに食べた種類なら、削除候補
        if (i != values[sushi[i].first][0]) pq_already.push(sushi[i].second);
    }

    // 各種類の一番大きいやつだけ入れる。
    REPN(i, K, N){
        if (i == values[sushi[i].first][0]) pq_notyet.push(sushi[i].second);
    }

    dp[kinds.size()] = sm;
    ll ans = dp[kinds.size()] + kinds.size() * kinds.size();
    REPN(x, kinds.size()+1, N+1){
        if (pq_already.empty() || pq_notyet.empty()) break;

        ll already = pq_already.top(); pq_already.pop();
        ll notyet = pq_notyet.top(); pq_notyet.pop();
        dp[x] = dp[x-1] - already + notyet;
        ans = max(ans, dp[x] + (ll)x * x);
    }


    print(ans);


    return 0;
}
