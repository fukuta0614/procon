// abc138_e
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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<deque<int>> A;
    A.assign(N, deque<int>(N-1, 0));
    REP(i, N) REP(j, N-1){
        cin >> A[i][j]; A[i][j]--;
    }

    int ans = 0;
    while (true) {
        set<P> st;
        bool continuing = false;
        bool updating = false;
        REP(i, N) {
            if (A[i].size() == 0) continue;

            continuing = true;
            P p = i < A[i][0] ? P(i, A[i][0]) : P(A[i][0], i);
            if (st.find(p) != st.end()) {
                A[p.first].pop_front();
                A[p.second].pop_front();
                updating = true;

//                while (true) {
//                    P p = i < A[p.first][0] ? P(p.first, A[p.first][0]) : P(A[p.first][0], p.first);
//                    if (st.find(p) != st.end()){
//
//                    }
//                }
            } else {
                st.insert(p);
            }
        }
        if (not continuing) break;

        if (not updating){
            print(-1);
            return 0;
        }
        ans++;

        if (ans > 10000){
            print(N * (N-1) / 2);
            return 0;
        }
    }

    print(ans);

    return 0;
}
