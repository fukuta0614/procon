// zone2021_c
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

string to_bin(int n){ std::stringstream ss; ss << std::bitset<6>(n); return ss.str(); }


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<vector<ll>> T(N, vector<ll>(5, 0));
    REP(i, N) REP(j, 5) cin >> T[i][j];


    auto valid = [&](ll x){

        vector<bool> exists(1<<5);
        vector<int> power(N);

        REP(i, N){
            int tmp = 0;
            REP(j, 5){
                if (T[i][j] >= x){
                    tmp |= 1 << j;
                }
            }
            power[i] = tmp;

            REP(k, 1 << 5){
                exists[tmp & k] = true;
            }
//            print(to_bin(tmp));
        }
//        print(exists);

        REP(i, N) REPN(j, i+1, N){

            int p = power[i] | power[j];
            int need = 0b11111 ^ p;

            if (exists[need]){
                return true;
            }
        }

        return false;
    };

    ll ok = 0;
    ll ng = 2e9;
    while (ng - ok > 1){
        ll x = (ok + ng) / 2;

        if (valid(x)){
            ok = x;
        } else {
            ng = x;
        }
    }

    print(ok);


    return 0;
}
