// abc177_f
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

    int H, W;
    cin >> H >> W;
    vector<int> A(H), B(H);
    REP(i, H) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    set<P> st;
    REP(i, W) st.emplace(i, i);

    multiset<int> diff;
    REP(i, W) diff.insert(0);

    REP(i, H){

        auto it = st.lower_bound(P(A[i], 0));
        int mx = -1;
        while (it != st.end() && it->first <= B[i]+1){
            diff.erase(diff.lower_bound(it->first - it->second));
            mx = max(mx, it->second);
            st.erase(it++);
        }

        if (mx != -1 && B[i] != W-1){
            st.emplace(B[i]+1, mx);
            diff.emplace(B[i]+1-mx);
        }

        if (st.empty()){
            print(-1);
            continue;
        }

        int ans = *diff.begin() + i+1;

        print(ans);
    }

    return 0;
}
