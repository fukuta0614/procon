// aribon2-2_f
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
int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int W, H;
vector<vector<int>> C;

void dfs(int h, int w){
    C[h][w] = 0;
    REP(i, 8){
        int nh = h + dx[i];
        int nw = w + dy[i];
        if (C[nh][nw] == 0) continue;
        dfs(nh, nw);
    }
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    while (true){
        cin >> W >> H;
        if (W == 0 && H == 0) return 0;

        C.assign(H+2, vector<int>(W+2, 0));
        REP(i, H) REP(j, W){
            cin >> C[i+1][j+1];
        }

        int ans = 0;
        REPN(i, 1, H+1) REPN(j, 1, W+1){
            if (C[i][j] == 0) continue;
            dfs(i, j);
            ans++;
        }

        COUT(ans);
    }
}
