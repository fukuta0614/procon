// arc080_f
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
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

bool is_prime(int n){
    if (n == 1) return false;
    for (int a=2; a*a <= n; a++) if (n % a == 0) return false;
    return true;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> X(N);
    REP(i, N) cin >> X[i];
    sort(ALL(X));

    vector<int> M;
    REP(i, N){
        M.emplace_back(X[i]);
        while (i < N-1 && X[i]+1 == X[i+1]) i++;
        M.emplace_back(X[i]+1);
    }

    int m = M.size();
    Dinic<> flow(m+2);
    int s = m, t = s+1;

    int me=0, mo=0;
    REP(i, m) {

        if (M[i] % 2 == 0) {
            flow.add_edge(s, i, 1);
            me++;

            REP(j, m){
                int diff = abs(M[i] - M[j]);
                if (diff >= 3 && is_prime(diff)){
                    flow.add_edge(i, j, 1);
                }
            }

        } else {
            flow.add_edge(i, t, 1);
            mo++;
        }
    }

    int k = flow.max_flow(s, t);

    int ans = 0;
    ans += k;
    ans += ((me-k)/2 + (mo-k)/2) * 2;
    ans += (me-k) % 2 == 0 ? 0 : 3;

    print(ans);

    return 0;
}
