// aribon2-3-5_b
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

struct Pos {
    ll cost;
    ll tree_idx;
    ll elapsed;
    ll height;

    bool operator>( const Pos& other ) const {
        return cost > other.cost;
    }
};

ostream& operator<<(ostream& os, const Pos& pos) {
    os << "[" << pos.tree_idx << ' ' << pos.elapsed << ' ' << pos.height << ' ' << pos.cost <<  "]" << endl;
    return os;
}

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))

#define INF ((1ll << 40)-1)
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    ll N,M,X;
    cin >> N >> M >> X;
    vector<ll> H(N);
    REP(i, N) cin >> H[i];
    vector<P> G[N];

    REP(i, M){
        ll a,b,t;
        cin >> a >> b >> t; a--; b--;
        G[a].emplace_back(P(b, t));
        G[b].emplace_back(P(a, t));
    }

    vector<ll> cost_table(N, INF);
    priority_queue<Pos, vector<Pos>, greater<Pos>> PQ;
    cost_table[0] = 0;
//    cost_table[0] = abs(X - H[N-1]);
    PQ.push((Pos){cost_table[0], 0, 0, X});
    while (!PQ.empty()){
        Pos pos = PQ.top(); PQ.pop();
        if (cost_table[pos.tree_idx] < pos.cost){
            continue;
        }

        if (pos.tree_idx == N - 1){
            print(pos.cost + abs(pos.height - H[N-1]));
            return 0;
        }

        for (auto next_tree : G[pos.tree_idx]){
            ll next_idx = next_tree.first;
            ll span = next_tree.second;

            ll next_height = pos.height - span;
            if (next_height > H[next_idx]){
                span += next_height - H[next_idx];
                next_height = H[next_idx];
            } else if (next_height < 0) {
                ll tmp = 0 - next_height;
                if (pos.height + tmp > H[pos.tree_idx]) {
                    continue;
                }
                span += tmp;
                next_height = 0;
            }

            ll next_elapsed = pos.elapsed + span;
//            ll cost = abs(next_height - H[N-1]) + next_elapsed;
            ll cost = next_elapsed;
            if (cost < cost_table[next_idx]){
                cost_table[next_idx] = cost;
                PQ.push((Pos){cost, next_idx, next_elapsed, next_height});
            }
        }
    }

    print(-1);

    return 0;
}
