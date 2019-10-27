// aribon4-2_a
// ARC 038 B マス目と駒
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

vector<vector<bool>> X;
vector<vector<int>> memo;

int dfs(int i, int j){

    if (memo[i][j] != -1) return memo[i][j];

    if (X[i][j]) return true;

    bool ret = false;
    ret |= not dfs(i+1, j);
    ret |= not dfs(i, j+1);
    ret |= not dfs(i+1, j+1);

    return memo[i][j] = (int)ret;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif


    int H, W;
    cin >> H >> W;

    X.assign(H+2, vector<bool>(W+2, true));
    REP(i, H) {
        string s;
        cin >> s;
        REP(j, W) {
            X[i + 1][j + 1] = s[j] == '#';
        }
    }

    memo.assign(H+2, vector<int>(W+2, -1));
    bool first = dfs(1, 1); // i, j で自分の手番が回ってきたときに勝つかどうか

    if (first){
        print("First");
    } else {
        print("Second");
    }


    return 0;
}
