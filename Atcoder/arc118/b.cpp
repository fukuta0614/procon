// arc118_b
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

    ll K, N, M;
    cin >> K >> N >> M;
    vector<ll> A(K);
    REP(i, K) cin >> A[i];

    vector<ll> B(K);
    ll sm = 0;
    REP(i, K){

        ll tmp1 = M * A[i] / N;
        ll tmp2 = (M * A[i] + N-1) / N;

        ll diff1 = abs(tmp1*N - A[i]*M);
        ll diff2 = abs(tmp2*N - A[i]*M);

        if (diff1 < diff2){
            B[i] = tmp1;
        } else {
            B[i] = tmp2;
        }
        sm += B[i];
    }

    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<>> pq;
    REP(i, K){
        if (sm > M){
            ll diff = abs((B[i]-1)*N - A[i]*M);
            pq.emplace(diff, i);
        } else {
            ll diff = abs((B[i]+1)*N - A[i]*M);
            pq.emplace(diff, i);
        }
    }

//    vector<P> v;
//    auto pq2 = pq;
//    while (not pq2.empty()){v.emplace_back(pq2.top()); pq2.pop();}
//    print(v);
//
//    print(sm);
//    print_line(B, K);

    REP(i, abs(sm-M)){
        auto [diff, idx] = pq.top(); pq.pop();
        if (sm > M){
            B[idx]--;

            ll diff = abs((B[idx]-1)*N - A[i]*M);
            pq.emplace(diff, idx);
        } else {
            B[idx]++;

            ll diff = abs((B[idx]+1)*N - A[i]*M);
            pq.emplace(diff, idx);
        }
    }

    print_line(B, K);

    assert(accumulate(ALL(B), 0ll) == M);


    return 0;
}
