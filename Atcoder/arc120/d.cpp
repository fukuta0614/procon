// arc120_d
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
using P = pair<int, int>;

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
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> A(2*N);
    REP(i, 2*N) cin >> A[i];

    vector<int> ord(2*N);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&A](int i, int j){
        return A[i] < A[j];
    });

    vector<bool> first_half(2*N);
    REP(i, N) first_half[ord[i]] = true;

    vector<int> stk;
    vector<char> ans(2*N);
    REP(i, 2*N) {
        if (stk.empty()) {stk.emplace_back(i); continue;}

        if (first_half[i] != first_half[stk.back()]){
            ans[stk.back()] = '(';
            ans[i] = ')';
            stk.pop_back();
        } else {
            stk.emplace_back(i);
        }
    }

    string s;
    REP(i, 2*N) s += ans[i];

    print(s);


    return 0;
}
