// m-solutions2020_d
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

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

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    set<P> st;
    st.emplace(1000ll, 0ll);

    REP(i, N){

        set<P> new_st;
        for (auto e: st){
            ll m = e.first;
            ll s = e.second;
            new_st.emplace(m + s * A[i], 0);
            new_st.emplace(m % A[i], s + m / A[i]);
            new_st.emplace(m, s);
        }
        st.clear();

        for (auto e: new_st){
            bool need = true;
            for (auto f: new_st){
                if (e.first < f.first and e.second < f.second){
                    need = false;
                    break;
                }
            }
            if (need){
                st.emplace(e);
            }
        }

    }

    ll ans = 1000;
    for (auto e: st){
        ans = max(ans, e.first);
    }
    print(ans);


    return 0;
}
