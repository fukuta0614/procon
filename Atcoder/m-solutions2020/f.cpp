// m-solutions2020_f
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
    vector<int> X(N), Y(N);
    vector<char> U(N);
    REP(i, N){
        cin >> X[i] >> Y[i] >> U[i];
    }

    map<int, set<int>> pos[4];
    map<int, set<int>> neg[4];
    map<int, set<int>> xs[4];
    map<int, set<int>> ys[4];

    map<char, int> enc{{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

    REP(i, N){
        int idx = enc[U[i]];
        xs[idx][X[i]].insert(Y[i]);
        ys[idx][Y[i]].insert(X[i]);

        int t1 = Y[i] - X[i];
        pos[idx][t1].insert(X[i]);

        int t2 = Y[i] + X[i];
        neg[idx][t2].insert(X[i]);
    }

    ll ans = INF;
    REP(i, N){
//        int c = (U[i] == 'U' or U[i] == 'R')
        int t1 = Y[i] - X[i];
        int t2 = Y[i] + X[i];

        if (U[i] == 'U'){
            set<int>& target = xs[enc['D']][X[i]];
            auto it = target.upper_bound(Y[i]);
            if (it != target.end()){
                ans = min(ans, 5ll * (*it - Y[i]));
            }

            set<int>& target2 = pos[enc['L']][t1];
            auto it2 = target2.upper_bound(X[i]);
            if (it2 != target2.end()){
                ans = min(ans, 10ll * (*it2 - X[i]));
            }

        } else if (U[i] == 'R'){
            set<int>& target = ys[enc['L']][Y[i]];
            auto it = target.upper_bound(X[i]);
            if (it != target.end()){
                ans = min(ans, 5ll * (*it - X[i]));
            }

            set<int>& target2 = pos[enc['D']][t1];
            auto it2 = target2.upper_bound(X[i]);
            if (it2 != target2.end()){
                ans = min(ans, 10ll * (*it2 - X[i]));
            }

            set<int>& target3 = neg[enc['U']][t2];
            auto it3 = target3.upper_bound(X[i]);
            if (it3 != target3.end()){
                ans = min(ans, 10ll * (*it3 - X[i]));
            }

//            print("R");

        } else if (U[i] == 'D'){

            set<int>& target3 = neg[enc['L']][t2];
            auto it3 = upper_bound(ALL(target3), X[i]);
            if (it3 != target3.end()){
                ans = min(ans, 10ll * (*it3 - X[i]));
            }

        } else {

        }
    }

    if (ans == INF){
        print("SAFE");
    } else {
        print(ans);
    }

    return 0;
}
