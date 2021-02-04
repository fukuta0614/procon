// abc188_e
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

struct Graph {

    int n;

    vector<vector<int>> edges;
    vector<set<int>> rev;
    vector<ll> weight;
    vector<ll> mn;

    Graph(int n): n(n), edges(n), rev(n), weight(n), mn(n, INF){}


    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        rev[v].emplace(u);
    }

    ll dfs(){
        queue<int> q;

        REP(i, n){
            if (rev[i].empty()) q.push(i);
        }

        ll ret=-INF;
        while (!q.empty()){
            int u = q.front(); q.pop();

            for (auto v: edges[u]){
                ret = max(ret, weight[v] - mn[u]);
                mn[v] = min(mn[v], mn[u]);

                rev[v].erase(u);
                if (rev[v].empty()){
                    q.push(v);
                }
            }
        }
        return ret;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    Graph g(N);
    REP(i, N) {
        cin >> g.weight[i];
        g.mn[i] = g.weight[i];
    }
    REP(i, M){
        int x, y; cin >> x >> y; x--;y--;
        g.add_edge(x, y);
    }

    ll ans = g.dfs();
    print(ans);

    return 0;
}
