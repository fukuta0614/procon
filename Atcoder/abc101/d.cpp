// abc101_d
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

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );


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

    int K;
    cin >> K;

    auto func = [](ll n){
        auto s = to_string(n);
        int sm = 0;
        for (auto c: s) sm += c - '0';
        return sm;
    };

    vector<ll> cand;
    REPN(p,1, 9) cand.emplace_back(p);
    REPN(d, 1, 15){
        REPN(p, 1,150){
            ll x = p * (ll)pow(10, d) - 1;
            cand.emplace_back(x);
        }
    }
    sort(ALL(cand));
    UNIQUE(cand);

    vector<ll> ans;
    int N = cand.size();
    REP(i, N) {
        ll n = cand[i];
        ll sn = func(n);

        bool valid = true;
        REPN(j, i+1, N){
            ll m = cand[j];
            ll sm = func(m);
            if (n * sm > m * sn){
                valid = false;
                break;
            }
        }
        if (valid){
            ans.emplace_back(n);
        }
    }

    REP(i, K){
        print(ans[i]);
    }


//    REP(i, K){
//        print(solve(i+1));
//    }

//    vector<int> v;
//    REPN(n, 1, 10000){
//        int sn = func(n);
//        bool valid = true;
//        REPN(m, n+1, 10000){
//            int sm = func(m);
//            if (n * sm > m * sn){
//                valid = false;
//                break;
//            }
//        }
//        if (valid){
//            v.emplace_back(n);
//        }
//    }
//
//    REP(i, v.size()){
//        print(i+1, v[i], solve(i+1));
//    }


    return 0;
}
