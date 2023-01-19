// abc198_d
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

    string S[3];
    REP(i, 3) cin >> S[i];

    set<char> st;
    REP(i, 3){
        REP(j, S[i].size()){
            st.emplace(S[i][j]);
        }
    }

    if (st.size() > 10){
        print("UNSOLVABLE");
        return 0;
    }

    vector<int> nums(10);
    iota(ALL(nums), 0);

    vector<char> stv(ALL(st));

    do{
        map<char, int> mp;
        REP(i, stv.size()){
            mp[stv[i]] = nums[i];
        }

        vector<ll> N(3);
        bool invalid = false;
        REP(i, 3){
            if (mp[S[i][0]] == 0) {
                invalid = true;
                break;
            }
            REP(j, S[i].size()){
                N[i] = N[i] * 10 + mp[S[i][j]];
            }
        }

        if (invalid) continue;

        if (N[0] + N[1] == N[2]){
            REP(i, 3) print(N[i]);
            return 0;
        }

    } while(next_permutation(ALL(nums)));

    print("UNSOLVABLE");

    return 0;
}
