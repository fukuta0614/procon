// abc132_e
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

struct Item {
    int cost, v, cnt;
    Item(int cost, int v, int cnt): cost(cost), v(v), cnt(cnt){}
    bool operator>( const Item& other ) const { return cost > other.cost; }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);

    REP(i, M){
        int u, v;
        cin >> u >> v; u--; v--;
        G[u].emplace_back(v);
    }

    int S, T;
    cin >> S >> T; S--, T--;

    vector<vector<int>> dist;
    dist.assign(N, vector<int>(3, INF));
    dist[S][0] = 0;

    priority_queue<Item, vector<Item>, greater<Item>> pq;
    pq.push(Item(0, S, 0));
    while (!pq.empty()){
        Item itm = pq.top(); pq.pop();

        if (itm.v == T && itm.cnt == 0){
            print(itm.cost / 3);
            return 0;
        }

        for (auto n: G[itm.v]){
            int ncost = itm.cost + 1;
            int ncnt = (itm.cnt + 1) % 3;
            if (ncost < dist[n][ncnt]){
                dist[n][ncnt] = ncost;
                pq.push(Item(ncost, n, ncnt));
            }
        }
    }

    print(-1);

    return 0;
}
