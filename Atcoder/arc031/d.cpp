// arc031_d
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define INF (1ll << 48)
struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

#define MAX_V (202)

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

int N, M;
int S[100], T[100], K[100];
int A[100][100];
int S_sum = 0;

bool is_valid(ll a, ll b) {

    Dinic dinic;

    int s = 0, t = N + M + 1;
    int v_num = 1;
    REP(i, M) {
        dinic.add_edge(s, v_num, b * T[i]);
        dinic.add_edge(v_num, t, 0);
        v_num++;
    }

    REP(i, N) {
        dinic.add_edge(s, v_num, 0);
        dinic.add_edge(v_num, t, a * S[i]);
        REP(k, K[i]) dinic.add_edge(A[i][k], v_num, INF);
        v_num++;
    }

    ll ret = dinic.max_flow(s, t);
    return a * S_sum - ret > 0;
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> M;
    REP(i, N) cin >> S[i];
    REP(i, M) cin >> T[i];
    REP(i, N) {
        cin >> K[i];
        REP(k, K[i]) cin >> A[i][k];
    }
    S_sum = accumulate(S, S + N, 0);

    ll a = 10000ll;
    ll sup_b = a * 10000ll;
    ll inf_b = 0;

    while (sup_b - inf_b > 1) {
        ll b = (sup_b + inf_b) / 2;
        if (is_valid(a, b))
            inf_b = b;
        else
            sup_b = b;
    }

    cout << (double)inf_b / a << endl;

    return 0;
}


