// asdf_i
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
#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define ALL(x) x.begin(), x.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define CHAR2INT(c) (c - '0')
#define COUT(x) cout << x << endl
#define COUT_2DARR(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }

int mod_pow(ll a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={ 1, 0, -1, 0 };
int dy[4]={ 0, 1, 0, -1 };

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int R, C, sx, sy, gx, gy;
    cin >> R >> C;
    cin >> sx >> sy;
    cin >> gx >> gy;

    vector<vector<char>> graph;
    graph.assign(R+2, vector<char>(C+2, '#'));
    REP(i, R) REP(j, C){
        cin >> graph[i+1][j+1];
    }

    queue<P> Q;
    Q.push(P(sx, sy));

    vector<vector<int>> dist;
    dist.assign(R+2, vector<int>(C+2, INF));

    graph[sx][sy] = '#';
    dist[sx][sy] = 0;

    while (Q.size()){
        P p = Q.front(); Q.pop();

        REP(i, 4){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx == gx && ny == gy){
                COUT(dist[p.first][p.second] + 1);
                return 0;
            }
            if (graph[nx][ny] == '#') continue;

            Q.push(P(nx, ny));
            dist[nx][ny] = dist[p.first][p.second] + 1;
            graph[nx][ny] = '#';
        }

    }
    return 0;
}
