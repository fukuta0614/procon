// aribon2-1_f
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
#define INF ((1 << 31)-1)
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

vector<vector<char>> A;
vector<vector<bool>> visited;

vector<vector<int>> B;
vector<vector<bool>> checked;

void dfs(int x, int y){
    visited[x][y] = 'x';
    REP(i, 4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny]) continue;
        if (A[nx][ny] == 'x') {
            if (!checked[nx][ny]) {
                B[nx][ny] += 1;
                checked[nx][ny] = true;
            }
            continue;
        }
        dfs(nx, ny);
    }
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    A.assign(12, vector<char>(12, 'x'));
    REP(i, 10) REP(j, 10) cin >> A[i+1][j+1];
    visited.assign(12, vector<bool>(12, false));

    B.assign(12, vector<int>(12, 0));
    int count = 0;
    REP(i, 12){
        REP(j, 12){
            if (A[i][j] == 'x' || visited[i][j]) continue;
            checked.assign(12, vector<bool>(12, false));
            dfs(i, j);
            count++;

        }
    }

    REP(i, 12) REP(j, 12){
        if (B[i][j] == count){
            COUT("YES");
            return 0;
        }
    }
    COUT("NO");
    return 0;
}



