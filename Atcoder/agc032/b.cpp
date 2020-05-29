// agc032_b
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

    REP(p, 1 << 10){
        vector<vector<int>> edge(5);
        int c = 0;
        REP(i, 5) REPN(j, i+1, 5){
            if ((p >> c) & 1) {
                edge[i].emplace_back(j+1);
                edge[j].emplace_back(i+1);
            }
            c++;
        }

        int S = 0;
        bool valid = true;
        REP(i, 5){
            int sm = 0;
            for (auto j: edge[i]){
                sm += j;
            }

            if (i == 0){
                S = sm;
            } else {
                if (S != sm){
                    valid = false;
                    break;
                }
            }
        }

        if (valid){
            REP(i, 5) print(i+1, edge[i]);
        }
    }


    return 0;
}
