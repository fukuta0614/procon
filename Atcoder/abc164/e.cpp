// abc164_e
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

#define INF ((ll)1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


struct Graph {

    struct Edge {
        int u, v;
        ll money;
        ll cost;
        Edge() {}
        Edge(int u, int v, ll w, ll t) : u(u), v(v), money(w), cost(t) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {
            cout << "(" << e.u << "->" << e.v << "," << e.money << "," << e.cost << ")"; return os;
        }
    };

    int n;

    vector<vector<Edge>> edges;
    Graph(int n): n(n), edges(n) {}

    void add_edge(int u, int v, ll w, ll t){
        edges[u].emplace_back(u, v, w, t);
        edges[v].emplace_back(v, u, w, t);
    }

    vector<ll> dijkstra(int s, int S, vector<P>& trades){

        // コスト（時間）, (node, 銀貨)
        using PP = pair<ll, pair<int, ll>>;

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push(PP(0, P(s, S)));

        vector<ll> dist(n, INF);
        dist[s] = 0;

        // node, 銀貨に対する最短時間
        map<P, ll> best_costs;
        best_costs[P(s, S)] = 0;

        // 全部たどり着くまでこれは使わない。
        ll now_max_cost = INF;

        while (!pq.empty()){
            PP pp = pq.top(); pq.pop();

            ll cost = pp.first;
            int u = pp.second.first;
            ll money = pp.second.second;

//            print(u, cost, money, now_max_cost, dist);

            // 全部たどり着いていて、かつ現時点で一番時間がかかる地点までの時間よりも超えるなら終わり
            if (now_max_cost != INF && cost > now_max_cost) {
                return dist;
            }

            // 移動
            for (auto edge: edges[u]){

                if (money < edge.money) continue;

                ll nmoney = money - edge.money;
                ll ncost = cost + edge.cost;

                // 状態更新
                if (ncost < dist[edge.v]){
                    dist[edge.v] = ncost;

                    // 全部たどりつけたかチェック & 最低この時間でたどり着けるという時間をセットする
                    now_max_cost = 0;
                    REP(i, n) {
                        now_max_cost = max(dist[i], now_max_cost);
                    }
                }

                // 移動
                P node = P(edge.v, nmoney);
                if (best_costs.find(node) == best_costs.end() || ncost < best_costs[node]) {
                    best_costs[node] = ncost;
                    pq.push(PP(ncost, node));
                }
            }

            // 換金
            ll nmoney = money + trades[u].first;
            ll ncost = cost + trades[u].second;
            P node = P(u, nmoney);
            // 絶対使わない状態ならいらない。
            // 最大でも50都市 x 50枚しか金貨は使わない
            // 全部たどり着いていて、かつ現時点で一番時間がかかる地点までの時間よりも超えるならいらない
            if (money > 2500 || (now_max_cost != INF && ncost > now_max_cost)) {
                continue;
            }

            if (best_costs.find(node) == best_costs.end() || ncost < best_costs[node]) {
                best_costs[node] = ncost;
                pq.push(PP(ncost, node));
            }
        }

        return dist;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../line_2.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M, S;
    cin >> N >> M >> S;

    Graph g(N);
    REP(i, M){
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        g.add_edge(u, v, a, b);
    }

    vector<P> trades(N);
    REP(i, N){
        cin >> trades[i].first >> trades[i].second;
    }

    vector<ll> ans = g.dijkstra(0, S, trades);

    REPN(i, 1, N){
        print(ans[i]);
    }




    return 0;
}


//51000000000
//102000000000
//153000000000
//204000000000
//255000000000
//306000000000
//357000000000
//408000000000
//459000000000
//510000000000
//561000000000
//612000000000
//663000000000
//714000000000
//765000000000
//816000000000
//867000000000
//918000000000
//969000000000
//1020000000000
//1071000000000
//1122000000000
//1173000000000
//1224000000000
//1275000000000
//1326000000000
//1377000000000
//1428000000000
//1479000000000
//1530000000000
//1581000000000
//1632000000000
//1683000000000
//1734000000000
//1785000000000
//1836000000000
//1887000000000
//1938000000000
//1989000000000
//2040000000000
//2091000000000
//2142000000000
//2193000000000
//2244000000000
//2295000000000
//2346000000000
//2397000000000
//2448000000000
//2499000000000
