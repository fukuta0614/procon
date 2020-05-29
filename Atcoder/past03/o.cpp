// past03_o
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> P;

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

    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    vector<ll> R(3);
    REP(i, 3) cin >> R[i];

    vector<vector<ll>> scores(N, vector<ll>(3, 0));
    REP(i, 3) REP(j, N){
        scores[j][i] = (ll)(A[j] * pow(B[j], (i+1))) % R[i];
    }

    REP(i, 2) print(scores[i]);

    set<P> st;
    REP(i, 3) REP(j, N){
        st.emplace(scores[j][i]  - (A[j] * pow(B[j], 1)), N*i+j);
    }

    for (auto e: st){
        print(e);
    }

    vector<int> X(3);
    vector<vector<int>> cnt(N, vector<int>(3, 0));

    ll ans = 0;
    REP(m, 3*M){
        P p = *st.rbegin();
        st.erase(p);
        ll score = p.first;
        int x = p.second;
        int i = x / N;
        int j = x % N;
        print(i, j, score);
        if (X[i] == M) {
            m--;
            continue;
        }

        cnt[j][i]++;
        X[i]++;
        int n = cnt[j][0] + cnt[j][1] + cnt[j][2];

        REP(k, 3){
            P p0 = P(scores[j][k] + A[j] * pow(B[j], n-1) - (A[j] * pow(B[j], n)), N*k+j);
            if (n == 1){
                p0 = P(scores[j][k] - (A[j] * pow(B[j], n)), N*k+j);
            }
            if (st.find(p0) != st.end()) st.erase(p0);
            P p1 = P(scores[j][k] + A[j] * pow(B[j], n) - (A[j] * pow(B[j], n+1)), N*k+j);
            if (X[k] != M) st.emplace(p1);
        }

        ans += score;
    }
    print(cnt);

    print(ans);



    return 0;
}
