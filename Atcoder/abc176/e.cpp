// abc176_e
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
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W, M;
    cin >> H >> W >> M;

    vector<int> col(W, 0), row(H, 0);
    map<P, int> mp;
    REP(i, M){
        int h, w;
        cin >> h >> w;
        h--; w--;
        row[h]++;
        col[w]++;
        mp[P(h, w)]++;
    }

    vector<int> row_idx(H);
    iota(ALL(row_idx), 0);
    sort(ALL(row_idx), [&](int i, int j){ return row[i] > row[j]; });

    vector<int> col_idx(W);
    iota(ALL(col_idx), 0);
    sort(ALL(col_idx), [&](int i, int j){ return col[i] > col[j]; });

    int rmax = row[row_idx[0]];
    int cmax = col[col_idx[0]];

    int ans = 0;
    REP(i, H) {

        if (row[row_idx[i]] < rmax) break;

        REP(j, W){

            if (col[col_idx[j]] < cmax) break;

            int tmp = row[row_idx[i]] + col[col_idx[j]];
            if (mp[P(row_idx[i], col_idx[j])] > 0){
                tmp -= 1;
                ans = max(ans, tmp);
            }  else{
                print(tmp);
                return 0;
            }
        }
    }

    print(ans);






    return 0;
}
