// abc165_c
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

int N, M, Q;
vector<int> A;
vector<int> a, b, c, d;
ll ans = 0;

void dfs(){

    if (A.size() == N){
        ll tmp = 0;
        REP(i, Q){
            if (A[b[i]] - A[a[i]] == c[i]){
                tmp += d[i];
            }
        }
        ans = max(tmp, ans);
        return ;
    }

    int d = A.size() == 0 ? 1 : A.back();
    REPN(i, d, M+1){
        A.emplace_back(i);
        dfs();
        A.pop_back();
    }
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> M >> Q;

    a.assign(Q, 0);
    b.assign(Q, 0);
    c.assign(Q, 0);
    d.assign(Q, 0);
    REP(i, Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }

    dfs();
    print(ans);


    return 0;
}
