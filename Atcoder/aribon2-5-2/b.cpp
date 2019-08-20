// aribon2-5-3_b
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

    int N, K;
    cin >> N >> K;

    int dist[100][100];
    REP(i, N) REP(j, N) dist[i][j] = INF;
    REP(i, N) dist[i][i] = 0;

    int a, b, c, d, e, t;
    REP(k, K){
        cin >> t;
        if (t == 0){
            cin >> a >> b; a--; b--;

            if (dist[a][b] == INF){
                print(-1);
            } else {
                print(dist[a][b]);
            }

        } else {
            cin >> c >> d >> e; c--; d--;

            dist[c][d] = min(dist[c][d], e);
            dist[d][c] = dist[c][d];

            REP(i, N) REP(j, N){
                dist[i][j] = min(dist[i][j], dist[i][c] + e + dist[d][j]);
                dist[i][j] = min(dist[i][j], dist[i][d] + e + dist[c][j]);
            }
        }
    }

    return 0;
}
