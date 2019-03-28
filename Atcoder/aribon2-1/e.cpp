// aribon2-1_e
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define all(x) x.begin(), x.end()
#define INF ((1 << 16)-1)
#define MOD (1000000007)
#define COUT(x) cout << x << endl
struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;
int dx[4]={ 1, 0, -1, 0 };
int dy[4]={ 0, 1, 0, -1 };

vector<vector<char>> C;

bool reached = false;
void dfs(int x, int y){
    C[x][y] = '#';
    REP(i, 4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (C[nx][ny] == '#') continue;
        if (C[nx][ny] == 'g') {reached = true; return;}
        dfs(nx, ny);
    }
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int H, W;
    cin >> H >> W;
    C.assign(H+2, vector<char>(W+2, '#'));

    int sx, sy;
    REP(i, H) REP(j, W) {
        cin >> C[i+1][j+1];
        if (C[i+1][j+1] == 's') {sx = i + 1; sy = j + 1;}
    }

//    REP(i, H+2) { REP(j, W+2) cout << C[i][j] << " "; cout << endl; }

    dfs(sx, sy);
    COUT((reached ? "Yes" : "No"));

    return 0;
}


