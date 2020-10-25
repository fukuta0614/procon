// abc180_e
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<tuple<int, int, int>> xyz(N);
    REP(i, N){
        int x, y, z;
        cin >> x >> y >> z;
        xyz[i] = tie(x, y, z);
    }

    vector<vector<int>> d(N, vector<int>(N));
    REP(i, N) REP(j, N){

        int a, b, c;
        tie(a, b, c) = xyz[i];

        int p, q, r;
        tie(p, q, r) = xyz[j];

        d[i][j] = abs(p-a) + abs(q-b) + max(0, r-c);
    }

    REP(k, N) REP(i, N) REP(j, N){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    int mx = (1 << N) * (N) + 1;
    vector<int> dist(mx, INF);
    int s = 1 * N + 0;
    dist[s] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, s));

    while (!pq.empty()){

        P p = pq.top(); pq.pop();

        int cost = p.first;
        int node = p.second;
        int x = node / N;
        int u = node % N;

//        print(x, u, cost);

        if (x == ((1<<N)-1) && u == 0){
            print(cost);
            return 0;
        }

        if (dist[node] < cost){
            continue;
        }

        REP(v, N) {
            if (u == v) continue;

            int ncost = cost + d[u][v];
            int nextx = x | (1 << v);
            int nextnode = N * nextx + v;

            if (ncost < dist[nextnode]){
                dist[nextnode] = ncost;
                pq.push(P(ncost, nextnode));
            }
        }
    }

    return 0;
}
