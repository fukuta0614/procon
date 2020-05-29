// past03_g
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

int dx[6]={ 1, 0,-1, 1, -1, 0};
int dy[6]={ 1, 1, 1, 0, 0, -1};

bool bound_check(int i, int j, int N, int M) {return (0 <= i) && (i < N) && (0 <= j) && (j < M);}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, X, Y;
    cin >> N >> X >> Y;
    X += 300; Y += 300;

    vector<vector<bool>> S(600, vector<bool>(600, true));
    REP(i, N){
        int x, y;
        cin >> x >> y;
        S[x+300][y+300] = false;
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, 300 * 600 + 300);

    vector<vector<int>> dist(600, vector<int>(600, INF));
    dist[300][300] = 0;

    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        int cost = p.first;
        int pos = p.second;

        int i = pos / 600;
        int j = pos % 600;

        if (i == X && j == Y){
            print(cost);
            return 0;
        }

//        print(i, j, cost);

        REP(k, 6){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (not bound_check(ni, nj, 600, 600)) continue;
            if (not S[ni][nj]) continue;

            int ncost = cost + 1;
            if (ncost < dist[ni][nj]){
                dist[ni][nj] = ncost;
                pq.emplace(ncost, ni * 600 + nj);
            }
        }
    }
    print(-1);

    return 0;
}
