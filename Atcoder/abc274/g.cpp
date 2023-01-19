// abc274_g
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

// dinic
template <typename T = long long>
struct Dinic {
    struct edge { int to; T cap; int rev;};

    int n;
    vector<vector<edge>> G;
    T inf;
    vector<int> itr, level;

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
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    int n = 0;
    vector<vector<int>> hid(H, vector<int>(W, -1));
    vector<vector<int>> wid(H, vector<int>(W, -1));
    REP(i, H) {
        REP(j, W){
            if (S[i][j] == '#'){
                n++;
            } else {
                wid[i][j] = n;
            }
        }
        n++;
    }
    int nw = n;
    REP(j, W) {
        REP(i, H){
            if (S[i][j] == '#'){
                n++;
            } else {
                hid[i][j] = n;
            }
        }
        n++;
    }
    int s = n + 1;
    int t = s + 1;

    Dinic g(t+1);
    REP(i, nw) g.add_edge(s, i, 1);
    REPN(j, nw, n) g.add_edge(j, t, 1);
    REP(i, H) REP(j, W){
        if (wid[i][j] == -1 or hid[i][j] == -1) continue;
        g.add_edge(wid[i][j], hid[i][j], INF);
    }

    ll ans = g.max_flow(s, t);
    print(ans);

    return 0;
}
