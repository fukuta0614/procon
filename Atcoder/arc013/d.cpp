// arc013_d
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF ((1 << 16)-1)
struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

#define MAX_V (16002)

// dinic
struct Dinic {
    struct edge { int to; ll cap; int rev; };
    vector<edge> G[MAX_V];
    vector<int> itr, level;

    void add_edge(int from, int to, ll cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(MAX_V, -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &e: G[v]) {
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    ll dfs(int v, int t, ll f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll max_flow(int s, int t) {
        ll ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(MAX_V, 0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};

unordered_set<int> volumes;
set<pair<int, int>> volume_pairs;

void addbox(int x1, int y1, int z1, int x2, int y2, int z2) {
    int v1 = x1 * y1 * z1;
    int v2 = x2 * y2 * z2;
    volumes.insert(v1);
    volumes.insert(v2);
    volume_pairs.insert(make_pair(v1,v2));
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    int X, Y, Z;

    cin >> N;

    REP(i, N) {
        cin >> X >> Y >> Z;
        REPN(x, 1, X) addbox(x, Y, Z, X - x, Y, Z);
        REPN(y, 1, Y) addbox(X, y, Z, X, Y - y, Z);
        REPN(z, 1, Z) addbox(X, Y, z, X, Y, Z - z);
    }

    Dinic dinic;
    for (auto &v: volumes) {
        dinic.add_edge(0, v, 1);
        dinic.add_edge(8000 + v, 16001, 1);
    }

    for (auto &p: volume_pairs) {
        dinic.add_edge(p.first, 8000 + p.second, 1);
    }

    ll ret = dinic.max_flow(0, 16001);
    cout << volumes.size() * 2 - ret << endl;

    return 0;
}


