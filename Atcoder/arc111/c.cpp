// arc111_c
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

    int N;
    cin >> N;

    vector<int> A(N), B(N), P(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) {cin >> P[i]; P[i]--;}

    vector<int> Q(N);
    REP(i, N) Q[P[i]] = i;

    bool noneed = true;
    REP(i, N) if (i != P[i]) noneed = false;
    if (noneed){
        print(0);
        return 0;
    }

    REP(i, N) if (A[i] <= B[P[i]] && i != P[i]){
        print(-1);
        return 0;
    }

    // ループ検出
    vector<int> loop_idx(N, -1);
    vector<vector<int>> loops;
    REP(i, N){
        if (loop_idx[i] != -1) continue;

        auto idx = static_cast<int>(loops.size());

        int x = i;
        vector<int> loop;
        while (loop_idx[x] == -1){
            loop_idx[x] = idx;
            loop.emplace_back(x);

            x = P[x];
        }
        loops.emplace_back(loop);
    }

    int K = N - loops.size();
    print(K);
    REP(i, loops.size()){
        sort(ALL(loops[i]), [&A](int a, int b){
            return A[a] < A[b];
        });

        REP(j, loops[i].size()-1){
            int x = loops[i][j];
            print(x+1, Q[x]+1);
            int tmp = P[x];
            swap(P[x], P[Q[x]]);
            Q[tmp] = Q[x];
        }
    }


    return 0;
}
