// abc197_f
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

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll base1=1009,  base2=1007,  mod1=1000000007,  mod2=1000000009;
using hash_type = pair<ll,ll>;

// ハッシュ値がh1の文字列の末尾に、長さh2_lenでハッシュ値がh2をくっつけた文字列のハッシュ値
hash_type hash_func(hash_type h1, char x) {
    ll t1 = (h1.first * base1 + x) % mod1;
    ll t2 = (h1.second * base2 + x) % mod2;
    return make_pair(t1, t2);
}

struct Graph {


    int n;
    vector<vector<pair<int, char>>> edges;

    Graph(int n_) : n(n_), edges(n_) {}

    void add_edge(int u, int v, char c) {
        edges[u].emplace_back(v, c);
        edges[v].emplace_back(u, c);
    }

    void solve(){

        using P = pair<int, hash_type>;

        queue<P> q1, q2;

        q1.emplace(0, hash_type(0, 0));
        q2.emplace(n-1, hash_type(0, 0));

        vector<set<hash_type>> memo1(n), memo2(n);

        int ans = INF;
        while (true){

            if (not q1.empty()){

                P node = q1.front(); q1.pop();
                int u = node.first;
                auto h = node.second;

                bool update = false;
                for (auto edge: edges[u]){
                    int v = edge.first;
                    auto nh = hash_func(h, edge.second);
                    if (memo1[v].find(nh) != memo1[v].end()){
                        q1.emplace(v, nh);
                        memo1[v].emplace(nh);
                        update = true;

                        if (memo2[v].find(nh) != memo2[v].end()){
                            ans = min(ans, )
                        }
                    }
                }
                if (update){
                    q1.emplace(node);
                }
            }

            if (not q2.empty()){

                P node = q2.front(); q2.pop();
                int u = node.first;
                auto h = node.second;

                bool update = false;
                for (auto edge: edges[u]){
                    int v = edge.first;
                    auto nh = hash_func(h, edge.second);
                    if (memo2[v].find(nh) != memo2[edge.first].end()){
                        q2.emplace(v, nh);
                        memo2[v].emplace(nh);
                        update = true;
                    }
                }
                if (update){
                    q2.emplace(node);
                }
            }
        }





    }

};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;

    Graph g(N);
    REP(i, M){
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        g.add_edge(a, b, c);
    }






    return 0;
}
