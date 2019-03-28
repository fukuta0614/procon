// arc092_c
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define INF ((1 << 16)-1)
#define MOD (1000000007)
#define print(arr, n) REP(i, n) cout << arr[i] << " ";

struct PreMain {
    PreMain() {
        std::cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} premain;

#define MAX_V 202

struct Dinic {
    struct edge {
        int to;
        ll cap;
        int rev;
    };
    vector<edge> G[MAX_V];
    vector<int> itr, level;

    void add_edge(int from, int to, ll cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size() - 1});
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
        for (int &i = itr[v]; i < (int) G[v].size(); ++i) {
            edge &e = G[v][i];
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

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N, x, y;
    cin >> N;

    Dinic dinic;
    int s = 0;
    int t = 2 * N + 1;

    vector<pair<int, int>> reds;

    REP(i, N) {
        cin >> x >> y;
        dinic.add_edge(s, i + 1, 1);
        reds.emplace_back(make_pair(x, y));
    }

    REP(j, N) {
        cin >> x >> y;
        dinic.add_edge(N + j + 1, t, 1);
        REP(i, N) {
            auto p = reds[i];
            if (p.first < x && p.second < y) dinic.add_edge(i + 1, N + j + 1, 1);
        }
    }

    ll ans = dinic.max_flow(s, t);
    cout << ans << endl;

    return 0;
}


