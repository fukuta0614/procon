// abc073_d
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

#define INF (ll)(1e15)
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

    ll N, M, R;
    cin >> N >> M >> R;
    vector<ll> r_list(R);
    REP(i, R) {cin >> r_list[i]; r_list[i]--;}

    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    REP(i, M){
        ll a, b, c;
        cin >> a >> b >> c; a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    // warshall-floyd
    REP(k, N) REP(i, N) REP(j, N){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    sort(ALL(r_list));

    //
    ll ans = INF;
    do {
        ll tmp = 0;
        REP(i, R-1){
            tmp += dist[r_list[i]][r_list[i+1]];
        }
        ans = min(ans, tmp);
    } while (next_permutation(ALL(r_list)));

    print(ans);

    return 0;
}
