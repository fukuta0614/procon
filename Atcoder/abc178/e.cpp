// abc178_e
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e9)
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

    int N;
    cin >> N;
    vector<P> pos(N);
    REP(i, N) cin >> pos[i].first >> pos[i].second;

    vector<P> cand(4);

    cand[0] = *max_element(ALL(pos), [](P& a, P& b){return a.first + a.second < b.first + b.second;});
    cand[1] = *max_element(ALL(pos), [](P& a, P& b){return a.first + a.second > b.first + b.second;});
    cand[2] = *max_element(ALL(pos), [](P& a, P& b){return a.first - a.second < b.first - b.second;});
    cand[3] = *max_element(ALL(pos), [](P& a, P& b){return a.first - a.second > b.first - b.second;});

    ll ans = 0;
    REP(i, N){
        REP(j, 4){
            ll dist = abs(pos[i].first - cand[j].first) +  abs(pos[i].second - cand[j].second);
            ans = max(ans, dist);
        }
    }
    print(ans);


    return 0;
}
