// abc170_f
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

bool bound_check(int i, int j, int N, int M) {return (0 <= i) && (i < N) && (0 <= j) && (j < M);}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W, K;
    cin >> H >> W >> K;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
//    vector<vector<bool>> S(H, vector<bool>(W, true));
    vector<string> S(H);
    REP(i, H) cin >> S[i];


    vector<int> dist(H*W, INF);
    dist[sx*W+sy] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, sx*W+sy));

    vector<vector<vector<bool>>> search_num(H, vector<vector<bool>>(W, vector<bool>(4, true)));

    while (!pq.empty()){

        P p = pq.top(); pq.pop();

        int cost = p.first;
        int k = p.second;
        int i = k / W;
        int j = k % W;
//        print(i+1, j+1, cost);

        if (i == gx && j == gy){
//            REP(u, 3) {
//                REP(v, 5){
//                    cout << dist[u*W+v] << " ";
//                }
//                cout << endl;
//            }
            print(cost);
            return 0;
        }

        REP(d, 4){
            if (not search_num[i][j][d]) continue;

            int n = 1;
            while (true) {
                int ni = i + dx[d] * n;
                int nj = j + dy[d] * n;

                if (not bound_check(ni, nj, H, W)) break;
                if (S[ni][nj] == '@') break;

                int ncost = cost + (n + K - 1) / K;
                int v = ni * W + nj;
                if (ncost < dist[v]){
                    dist[v] = ncost;
                    pq.push(P(ncost, v));
                    // 今進んできた方向は探す必要ない。
                    search_num[ni][nj][d] = false;
                    search_num[ni][nj][(d+2)%4] = false;
                } else if (ncost == dist[v]) {
                    ;
                } else {
                    break;
                }
                n++;
            }
        }
    }

    print(-1);


    return 0;
}
