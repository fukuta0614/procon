// abc149_b
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    REP(i, H) REP(j, W) {
        char x; cin >> x;
        A[i][j] = x == '#' ? 1 : 0;
    }

    vector<bool> row(H);
    vector<bool> col(W);

    REP(i, H){
        int num = 0;
        REP(j, W) num += A[i][j];
        row[i] = num > 0;
    }

    REP(j, W){
        int num = 0;
        REP(i, H) num += A[i][j];
        col[j] = num > 0;
    }

    vector<string> ans;
    REP(i, H) {
        if (row[i] == false) continue;

        string s;
        REP(j, W){
            if (col[j] == false) continue;
            s += A[i][j] ? '#' : '.';
        }
        ans.emplace_back(s);
    }

    REP(i, ans.size()) print(ans[i]);


    return 0;
}
