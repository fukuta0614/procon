// abc157_c
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

    int N, M;
    cin >> N >> M;

    vector<int> d(N, -1);

    REP(i, M) {
        int s, c;
        cin >> s >> c;
        s--;
        if (s >= N) {
            print(-1);
            return 0;
        }

        if (d[s] == -1){
            d[s] = c;
        } else{
            if (d[s] != c){
                print(-1);
                return 0;
            }
        }
    }

    if (N == 1){
        int x = d[0] != -1 ? d[0] : 0;
        print(x);
        return 0;
    }

    if (d[0] == 0){
        print(-1);
        return 0;
    }

    int ans = 0;
    REP(i, N){
        int x;
        if (i == 0){
            x = d[i] != -1 ? d[i] : 1;
        } else{
            x = d[i] != -1 ? d[i] : 0;
        }
        ans = ans * 10 + x;
    }
    print(ans);


    return 0;
}
