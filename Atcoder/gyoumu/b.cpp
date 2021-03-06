// gyoumu_b
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

    int N = pow(3, 14);
    vector<vector<int>> init(3);
    init[0].emplace_back(1);
    init[1].emplace_back(2);

    REP(i, N){

        int n = i;
        auto tmp = init;
        REP(j, 14){
            tmp[n%3].emplace_back(j+2);
            n /= 3;
        }

        bool flag = true;
        REP(j, 3){
            for (auto x: tmp[j]) {
                for (auto y: tmp[j]){
                    if (std::find(ALL(tmp[j]), x + y) != tmp[j].end()){
                        flag = false;
                        break;
                    }
                }
            }
        }

        if (i % 100000 == 0){
            print(i);
        }
        if (flag){
            print(tmp);
            return 0;
        }
    }

    return 0;
}
