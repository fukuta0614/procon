// aribon4-5_a
// D - 薄氷渡り
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

int dx[4]={ 1, 0, -1, 0 };
int dy[4]={ 0, 1, 0, -1 };

int M, N;
vector<vector<int>> S;

int dfs(int i, int j) {

    S[i][j] = 0;

    int cnt = 0;
    REP(k, 4){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (S[ni][nj]) {
            cnt = max(cnt, dfs(ni, nj));
        }
    }

    S[i][j] = 1;
    return cnt+1;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> M >> N;
    S.assign(M+2, vector<int>(N+2));
    REPN(i, 1, M+1) REPN(j, 1, N+1){
        cin >> S[i][j];
    }

    int ans = 0;
    REPN(i, 1, M+1) REPN(j, 1, N+1){
        if (S[i][j]) {
            ans = max(ans, dfs(i, j));
        }
    }
    print(ans);

    return 0;
}
