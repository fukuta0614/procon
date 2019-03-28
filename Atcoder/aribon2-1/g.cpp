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
int dx[4]={ 1, 0, -1, 0 };
int dy[4]={ 0, 1, 0, -1 };

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


vector<bool> visited;
vector<vector<int>> graph;


bool dfs(int x, int prev){
    visited[x] = true;

    bool isValid = true;
    for (auto v: graph[x]){
        if (v == prev){
            continue;
        }
        if (visited[v]){
            isValid = false;
            continue;
        }
        bool res = dfs(v, x);
        isValid &= res;
    }
    return isValid;

}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    unsigned int N, M;
    cin >> N >> M;

    graph.assign(N, vector<int>());
    REP(i, M){
        int u, v;
        cin >> u >> v;
        graph[u-1].emplace_back(v-1);
        graph[v-1].emplace_back(u-1);
    }

    visited.assign(N, false);
    int ans = 0;
    REP(i, N){
        if (visited[i]) continue;

        bool res = dfs(i, i);
        if (res) ans++;
    }
    COUT(ans);
    return 0;
}
