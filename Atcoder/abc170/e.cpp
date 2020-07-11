// abc170_e
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

    int N, Q;
    cin >> N >> Q;
    int M = 2e5;
    vector<int> A(N), B(N);

    vector<multiset<int>> st(M);
    vector<int> belong(N);
    REP(i, N) {
        cin >> A[i] >> B[i];
        B[i]--;
        st[B[i]].insert(A[i]);
        belong[i] = B[i];
    }

    multiset<int> minset;
    REP(i, M){
        if (st[i].empty()) continue;
        minset.insert(*st[i].rbegin());
    }


    auto erase = [](multiset<int> &s, int v){
        auto itr = s.find(v);
        if(itr!=s.end()){
            s.erase(itr);
        }
    };

    REP(i, Q){
        int c, d;
        cin >> c >> d;
        c--; d--;

        int b = belong[c];

        int b_top = *st[b].rbegin();
        erase(minset, b_top);

        if (not st[d].empty()){
            int d_top = *st[d].rbegin();
            erase(minset, d_top);
        }

        erase(st[b], A[c]);
        st[d].insert(A[c]);
        belong[c] = d;

        if (not st[b].empty()){
            int b_top_after = *st[b].rbegin();
            minset.insert(b_top_after);
        }

        int d_top_after = *st[d].rbegin();
        minset.insert(d_top_after);

//        REP(j, 3){
//            print(st[j]);
//        }
//        print(minset);

        int ans = *minset.begin();
        print(ans);
    }




    return 0;
}
