// past02_e
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
    vector<int> A(N);
    REP(i, N) {cin >> A[i]; A[i]--;}

    vector<vector<int>> loops(100);
    vector<int> indices(N, -1);

    vector<int> ans(N);
    int idx = 0;
    REP(i, N){

        if (indices[i] != -1){
            ans[i] = (loops[indices[i]].size());
            continue;
        }

        int x = i;
        loops[idx].emplace_back(x);
        indices[x] = idx;
        while (true){
            x = A[x];
            if (indices[x] != -1){
                break;
            } else {
                loops[idx].emplace_back(x);
                indices[x] = idx;
            }
        }
        ans[i] = (loops[idx].size());
        idx++;
    }

    print_line(ans, N);


    return 0;
}
