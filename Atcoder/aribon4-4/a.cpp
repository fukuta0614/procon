// aribon4-4_a
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

    int N;
    cin >> N;
    vector<int> H(N);
    REP(i, N) cin >> H[i];

    vector<int> L(N), R(N);

    vector<int> stk(N);
    int sz = 0;
    REP(i, N){
        while(sz > 0 && H[stk[sz-1]] >= H[i]) sz--;
        L[i] = sz == 0 ? 0 : stk[sz-1] + 1;
        stk[sz++] = i;
    }

    sz = 0;
    REP_REV(i, N){
        while(sz > 0 && H[stk[sz-1]] >= H[i]) sz--;
        R[i] = sz == 0 ? N : stk[sz-1];
        stk[sz++] = i;
    }

    set<P> st;
    REP(i, N){
        st.insert(P(L[i], R[i]));
    }

    int ans = st.size();
    print(ans);


    return 0;
}
