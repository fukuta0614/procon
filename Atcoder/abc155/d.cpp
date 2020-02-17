// abc155_d
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    vector<ll> plus, minus, minus_inv;
    ll zero_n=0;
    REP(i, N) {
        if (A[i] > 0){
            plus.emplace_back(A[i]);
        } else if (A[i] < 0){
            minus.emplace_back(A[i]);
            minus_inv.emplace_back(-A[i]);
        } else {
            zero_n++;
        }
    }

    sort(ALL(A));
    sort(ALL(plus));
    sort(ALL(minus));
    sort(ALL(minus_inv));
    ll plus_n = plus.size();
    ll minus_n = minus.size();

//    print(plus_n, plus);
//    print(minus_n, minus);

    auto is_valid = [&](ll x){
        ll cnt = 0;

        if (x >= 0){
            REP(i, plus_n){
                ll p = upper_bound(ALL(plus), x / plus[i]) - plus.begin();
                ll n = minus_n;
                cnt += min((ll)i, p) + n;
//                print(x, plus[i], x / plus[i], p, min((ll)i, p));
            }

            REP(i, minus_n){
                ll n = upper_bound(ALL(minus_inv), x / minus_inv[i]) - minus_inv.begin();
                cnt += min((ll)i, n);
//                print(x, minus_inv[i], x / minus_inv[i], n, min((ll)i, n));
            }

            cnt += (zero_n * (plus_n + minus_n)) + zero_n * (zero_n - 1) / 2;
        } else {

            REP(i, plus_n){
                ll n = upper_bound(ALL(minus),  - ((-x + plus[i] - 1) / plus[i])) - minus.begin();
                cnt += n;
//                print(x, plus[i], - ((-x + plus[i] - 1) / plus[i]), n);
            }
        }
//        print(x, cnt);

        return cnt >= K;
    };


    ll ok = 1e18;
    ll ng = -1e18;
    while (ok - ng > 1){

        ll mid = (ok + ng) / 2;

        if (is_valid(mid)){
            ok = mid;
        } else {
            ng = mid;
        }
    }

    print(ok);


//    vector<int> test;
//    REP(i, N) REPN(j, i+1, N){
//            test.emplace_back(A[i] * A[j]);
//        }
//
//    sort(ALL(test));
//    print(test);
//    print(test[K-1]);

//    if (ok == 0){
//        print(0);
//    }
//    else if (ok > 0){
//        ll ans = -INF;
//        REP(i, plus_n){
//            auto it = lower_bound(ALL(plus), (ok + plus[i] - 1) / plus[i]);
//            if (it == plus.end()) continue;
//            ll p = *it * plus[i];
//            if (abs(p - ok) < abs(ans - ok)){
//                ans = p;
//            }
//        }
//
//        REP(i, minus_n){
//            auto it = lower_bound(ALL(minus_inv), (ok + minus_inv[i] - 1) / minus_inv[i]);
//            if (it == minus_inv.end()) continue;
//            ll p = *it * minus_inv[i];
//            if (abs(p - ok) < abs(ans - ok)){
//                ans = p;
//            }
//        }
//
//        print(ans);
//
//    } else {
//        ll ans = INF;
//        REP(i, plus_n){
//            ll p = *lower_bound(ALL(minus),  - (-ok / plus[i])) * plus[i];
//            if (abs(p - ok) < abs(ans - ok)){
//                ans = p;
//            }
//        }
//        print(ans);
//    }




//    vector<int> v{1, 2, 3, 3, 4};
//    auto it = upper_bound(ALL(v), 3);
//    int x = it - v.begin();
//    print(x);

    return 0;
}
