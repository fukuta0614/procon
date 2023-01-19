// abc281_e
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];


    multiset<P> st1;
    multiset<P> st2;

    vector<ll> ans;

    ll sm = 0;
    REP(i, N){
        if (i < K){
            st1.emplace(A[i], i);
            sm += A[i];
        } else if (i < M){
            P p = *st1.rbegin();
            if (A[i] < p.first){
                st1.erase(p);
                st1.emplace(A[i], i);
                st2.emplace(p);
                sm += A[i] - p.first;
            } else {
                st2.emplace(A[i], i);
            }
        } else {
            ans.emplace_back(sm);

            // まずは削除
            int j = i - M;
            auto p_erase = P(A[j], j);
            if (st1.find(p_erase) != st1.end()) {
                st1.erase(p_erase);
                sm -= A[j];

                if (st2.empty()){
                    st1.emplace(A[i], i);
                    sm += A[i];
                    continue;
                }

                P p2 = *st2.begin();
                st2.erase(p2);
                st1.emplace(p2);
                sm += p2.first;
            } else {
                st2.erase(p_erase);
            }

            // で追加
            P p = *st1.rbegin();
            if (A[i] < p.first){
                st1.erase(p);
                st1.emplace(A[i], i);
                st2.emplace(p);
                sm += A[i] - p.first;
            } else {
                st2.emplace(A[i], i);
            }
        }
    }
    ans.emplace_back(sm);
    print_line(ans, N-M+1);

    return 0;
}
