// aribon4-2_c
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

#define INF ((1 << 30)-1)
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

    int N;
    cin >> N;


    int grundy = 0;

    REP(i, N){
        vector<int> XYZ(3);
        cin >> XYZ[0] >> XYZ[1] >> XYZ[2];
        int M;
        cin >> M;

        vector<int> mn{INF, INF, INF};
        vector<int> mx{0, 0, 0};

        REP(j, M) {
            vector<int> xyz(3);
            cin >> xyz[0] >> xyz[1] >> xyz[2];
            REP(k, 3){
                mn[k] = min(mn[k], xyz[k]);
                mx[k] = max(mx[k], xyz[k]);
            }
        }

        REP(k, 3){
            grundy ^= XYZ[k] - mx[k] - 1;
            grundy ^= mn[k];
        }
    }

    if (grundy == 0){
        print("LOSE");
    } else{
        print("WIN");
    }


    return 0;
}
