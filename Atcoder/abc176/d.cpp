// abc176_d
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

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

bool bound_check(int i, int j, int N, int M) {return (0 <= i) && (i < N) && (0 <= j) && (j < M);}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W;
    cin >> H >> W;

    int ch, cw;
    cin >> ch >> cw;
    int dh, dw;
    cin >> dh >> dw;
    ch--; cw--; dh--; dw--;

    vector<string> S(H);
    REP(i, H) cin >> S[i];

    using PP = pair<int, pair<int, int>>;

    priority_queue<PP, vector<PP>, greater<PP>> pq;
    pq.push(PP(0, P(ch, cw)));

    vector<vector<int>> dist(H, vector<int>(W, INF));
    dist[ch][cw] = 0;

    while (!pq.empty()){
        PP pp = pq.top(); pq.pop();

        int cost = pp.first;
        int i = pp.second.first;
        int j = pp.second.second;

        if (i == dh && j == dw){
            print(cost);
            return 0;
        }

        REP(k, 4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (not bound_check(ni, nj, H, W)) continue;
            if (S[ni][nj] == '#') continue;

            if (cost < dist[ni][nj]){
                dist[ni][nj] = cost;
                pq.push(PP(cost, P(ni, nj)));
            }
        }

        REPN(k, -2, 2 +1) REPN(l, -2, 2+1){
            int ni = i + k;
            int nj = j + l;
            if (not bound_check(ni, nj, H, W)) continue;
            if (S[ni][nj] == '#') continue;

            int ncost = cost + 1;
            if (ncost < dist[ni][nj]){
                dist[ni][nj] = ncost;
                pq.push(PP(ncost, P(ni, nj)));
            }
        }
    }

    print(-1);

    return 0;
}
