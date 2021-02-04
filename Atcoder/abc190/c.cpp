// abc190_c
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

    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    REP(i, M) cin >> A[i] >> B[i];

    int K;
    cin >> K;
    vector<int> C(K), D(K);
    REP(i, K) cin >> C[i] >> D[i];

    int ans = 0;
    REP(p, 1 << K){

        set<int> st;
        REP(i, K){
            if ((p >> i) & 1){
                st.emplace(C[i]);
            } else {
                st.emplace(D[i]);
            }
        }

        int tmp = 0;
        REP(i, M){
            if (st.count(A[i]) > 0 && st.count(B[i]) > 0){
                tmp++;
            }
        }

//        print(p, st, tmp);

        ans = max(ans, tmp);
    }

    print(ans);


    return 0;
}
