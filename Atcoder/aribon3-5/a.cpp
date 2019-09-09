// aribon3-5_a
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

// dinic
template <typename T = long long>
struct Dinic {
    struct edge { int to; T cap; int rev; };
    vector<vector<edge>> G;
    vector<int> itr, level;
    int n;
    T inf;

    explicit Dinic(int n): n(n), G(n) {inf=numeric_limits<T>::max();}

    void add_edge(int from, int to, T cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(n, -1);
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

    T dfs(int v, int t, T f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t) {
        T ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(n, 0);
            while ((f = dfs(s, t, inf)) > 0) ret += f;
        }
        return ret;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    REP(i, H) cin >> A[i];

    auto dinic = Dinic<ll>(H+W+2);

    int S=H+W, T=H+W+1;
    int pos_s=0, pos_t=0;
    REP(i, H) REP(j, W) {
        if (A[i][j] == 'S') {
            pos_s = i*W+j;
            dinic.add_edge(S, i, dinic.inf);
            dinic.add_edge(S, H+j, dinic.inf);
        }
        if (A[i][j] == 'T') {
            pos_t = i*W+j;
            dinic.add_edge(i, T, dinic.inf);
            dinic.add_edge(H+j, T, dinic.inf);
        }
        if (A[i][j] == 'o') {
            dinic.add_edge(i, H+j, 1);
            dinic.add_edge(H+j, i, 1);
        }
    }

    if (pos_s/W == pos_t/W || pos_s%W == pos_t%W){
        print(-1);
    } else {
        ll f = dinic.max_flow(S, T);
        print(f);
    }


    return 0;
}