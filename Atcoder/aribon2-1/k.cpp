// asdf_k
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
#define INF ((1 << 29)-1)

#define COUT(x) cout << x << endl
int dx[4]={ 1, 0, -1, 0 };
int dy[4]={ 0, 1, 0, -1 };

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int H, W;
    cin >> H >> W;

    vector<vector<char>> graph;
    graph.assign(H, vector<char>(W, '#'));

    int sx, sy;
    int gx, gy;
    REP(i, H) REP(j, W){
        cin >> graph[i][j];
        if (graph[i][j] == 's') {
            sx = i; sy = j;
        }
        if (graph[i][j] == 'g') {
            gx = i; gy = j;
        }
    }

    // sの範囲探索
    queue<P> Q;
    Q.push(P(sx, sy));
    while (Q.size()){
        P p = Q.front(); Q.pop();
        REP(i, 4){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx < 0 || H <= nx || ny < 0 || W <= ny) continue;
            if (graph[nx][ny] == 's' || graph[nx][ny] == '#') continue;

            if (graph[nx][ny] == 'g'){
                COUT("YES");
                return 0;
            }
            graph[nx][ny] = 's';
            Q.push(P(nx, ny));
        }
    }

    // gの探索
    priority_queue<PP, vector<PP>, greater<PP>> pQ;
    pQ.push(PP(0, P(gx, gy)));

    vector<vector<int>> dist;
    dist.assign(H, vector<int>(W, INF));
    dist[gx][gy] = 0;

    while (!pQ.empty()){
        PP pp = pQ.top(); pQ.pop();

        REP(i, 4){
            int cost = pp.first;
            int nx = pp.second.first + dx[i];
            int ny = pp.second.second + dy[i];
            if (nx < 0 || H <= nx || ny < 0 || W <= ny) continue;

            if (graph[nx][ny] == 's'){
                COUT("YES");
                return 0;
            }

            if (graph[nx][ny] == '#') {
                cost++;
            }

            if (cost < dist[nx][ny] && cost <= 2){
                dist[nx][ny] = cost;
                pQ.push(PP(cost, P(nx, ny)));
            }
        }
    }
    COUT("NO");

    return 0;
}
