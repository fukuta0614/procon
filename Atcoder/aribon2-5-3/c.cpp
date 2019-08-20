// aribon2-5-3_c
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, P> PP;

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

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int H, W, sx, sy, gx, gy;
    cin >> H >> W >> sx >> sy >> gx >> gy;

    vector<vector<int>> G;
    G.assign(H+2, vector<int>(W+2, -1));
    int ans = 0;
    REPN(y, 1, H+1) REPN(x, 1, W+1) {cin >> G[y][x]; ans += G[y][x];}

    priority_queue<PP> pq;
    pq.push(PP(0, P(sx, sy)));

    vector<vector<bool>> visited;
    visited.assign(H+2, vector<bool>(W+2, false));

    int x, y;
    while (!pq.empty()){
        PP pp = pq.top(); pq.pop();
        x = pp.second.first; y = pp.second.second;

        if (visited[y][x]) continue;

        visited[y][x] = true;
        ans += pp.first;

        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (visited[ny][nx]) continue;
            if (G[ny][nx] == -1) continue;

            pq.push(PP(G[y][x] * G[ny][nx], P(nx, ny)));
        }

    }

    print(ans);

    return 0;
}
