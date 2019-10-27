// edpc_j
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

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int N;
vector<int> A;
double memo[301][301][301];
//map<ll, double> memo;

double dfs(int a, int b, int c, int d){

    if (a < 0 || b < 0 || c < 0) return 0;
    if (d == N) return 0;

    if (memo[a][b][c] != -1) return memo[a][b][c];
//    ll h = ((ll)a << 30) + ((ll)b << 20) + ((ll)c << 10) + (ll)d;
//    if (memo.count(h)) return memo[h];

    double e3 = dfs(a-1, b+1, c, d) * a / N;
    double e2 = dfs(a, b-1, c+1, d) * b / N;
    double e1 = dfs(a, b, c-1, d+1) * c / N;

    double e = (1 + (e1 + e2 + e3)) / (1 - double(d) / N);

//    return memo[h] = e;
    return memo[a][b][c] = e;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N;
    map<int, int> x;
    x[0]=x[1]=x[2]=x[3]=0;
    REP(i, N) {
        int a; cin >> a;
        x[a]++;
    }

    fill(memo[0][0], memo[0][0]+301*301*301, -1);
    double ans = dfs(x[3], x[2], x[1], x[0]);
    print(ans);

    return 0;
}
