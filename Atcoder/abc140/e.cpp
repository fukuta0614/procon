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
    vector<pair<int, int>> P(N);
    REP(i, N) {
        cin >> P[i].first;
        P[i].second = i;
    }
    sort(ALL(P), greater<pair<int, int>>());

    multiset<int> st{-1, -1, N, N};

    ll ans = 0;
    REP(i, N){

        ll v = P[i].first;
        ll idx = P[i].second;
        auto it = st.lower_bound(idx);

        ll l2, l1, r2, r1;

        r1 = *it;
        it++;
        r2 = *it;
        it--;
        it--;
        l1 = *it;
        it--;
        l2 = *it;

        ans += v * ((l1 - l2) * (r1 - idx) + (r2 - r1) * (idx - l1));

        st.insert(idx);
    }

    print(ans);

//    N = 5;
//    P = {5, 2, 1, 4, 3};
//    print(P);
//    int ans = 0;
//    REP(i, N-1) REPN(j, i+1, N){
//        auto x = P;
//        sort(x.begin() + i, x.begin() + j+1);
//        print(i, j, x, x[j-1]);
//        ans += x[j-1];
//    }
//    print(ans);


    return 0;
}
