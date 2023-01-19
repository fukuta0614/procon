// arc118_c
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

    vector<int> prime{2, 3, 5};
    vector<int> A;
    REPN(i, 1, 10000){
        if (i % 5 != 0 && 2*3*i <= 10000){
            A.emplace_back(2*3*i);
        }

        if (i % 3 != 0 && 2*5*i <= 10000){
            A.emplace_back(2*5*i);
        }

        if (i % 2 != 0 && 3*5*i <= 10000){
            A.emplace_back(3*5*i);
        }

        if (2*3*5*i <= 10000){
            A.emplace_back(2*3*5*i);
        }
    }

    print_line(A, N);

    int d = 0;
    REP(i, N) {
        assert(A[i] <= 10000);
        d = gcd(d, A[i]);
        REPN(j, i+1, N){
            assert(gcd(A[i], A[j]) > 1);
            assert(A[i] != A[j]);
        }
    }
    assert(d == 1);

    return 0;
}
