// agc044_b
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

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};
bool bound_check(int i, int j, int N, int M) {return (0 <= i) && (i < N) && (0 <= j) && (j < M);}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> A(N*N);
    REP(i, N*N) {cin >> A[i]; A[i]--;}

    vector<vector<int>> D(N, vector<int>(N, 0));
    REP(i, N) REP(j, N){
        D[i][j] = min(min(i, j), min(N-i-1, N-j-1));
    }

    vector<vector<bool>> occupied(N, vector<bool>(N, true));
    int ans = 0;
    REP(x, N*N){
        int xi = A[x] / N;
        int xj = A[x] % N;

        ans += D[xi][xj];
        occupied[xi][xj] = false;
        queue<P> q;
        q.emplace(xi, xj);
        while (not q.empty()){
            P p = q.front(); q.pop();
            int i = p.first;
            int j = p.second;
            REP(k, 4){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (not bound_check(ni, nj, N, N)) continue;
                if (D[i][j] + occupied[i][j] < D[ni][nj]){
                    D[ni][nj] = D[i][j] + occupied[i][j];
                    q.emplace(ni, nj);
                }
            }
        }
    }

    print(ans);


    return 0;
}
