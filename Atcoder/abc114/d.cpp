// abc114_d
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

vector<ll> get_divisors(ll n){
    vector<ll> res;
    for (int i = 1; i * i <= n; i++){
        if (i * i == n){
            res.emplace_back(i);
        }
        if (n % i == 0){
            res.emplace_back(i);
            res.emplace_back(n / i);
        }
    }
    sort(ALL(res));
    return res;
}

map<ll, int> factorize(ll n){
    ll tmp = n;
    map<ll, int> res;
    for (ll a = 2; a * a <= n; a++) { int cnt = 0; while (tmp % a == 0){ cnt++; tmp /= a; } if (cnt > 0) res[a] = cnt; }
    if (tmp > 1) res[tmp] = 1;
    return res;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    map<ll, int> f;
    REPN(n, 1, N+1){
        ll tmp = n;
        for (ll a = 2; a * a <= n; a++) { int cnt = 0; while (tmp % a == 0){ cnt++; tmp /= a; } if (cnt > 0) f[a] += cnt; }
        if (tmp > 1) f[tmp] += 1;
    }

    ll ans = 0;
    // 75 = 5 * 5 * 3 = 4 4 2
    for (auto a: f){
        if (a.second < 4) continue;
        for (auto b: f) {
            if (b.first <= a.first) continue;
            if (b.second < 4) continue;
            for (auto c: f) {
                if (c.first == a.first) continue;
                if (c.first == b.first) continue;
                if (c.second < 2) continue;
                ans++;
            }
        }
    }

    // 75 = 15 * 5 = 14 4
    for (auto a: f){
        if (a.second < 14) continue;
        for (auto b: f) {
            if (b.first == a.first) continue;
            if (b.second < 4) continue;
                ans++;
        }
    }

    // 75 = 25 * 3 = 24 2
    for (auto a: f){
        if (a.second < 24) continue;
        for (auto b: f) {
            if (b.first == a.first) continue;
            if (b.second < 2) continue;
            ans++;
        }
    }

    // 75 = 75 = 74
    for (auto a: f){
        if (a.second < 74) continue;
        ans++;
    }

    print(ans);

    return 0;
}
