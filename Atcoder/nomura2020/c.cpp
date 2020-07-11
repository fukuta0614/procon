// nomura2020_c
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

    ll N;
    cin >> N;
    vector<ll> A(N+1);
    REP(i, N+1) cin >> A[i];

    vector<ll> max_num(N+1);
    max_num[0] = 1;
    REPN(i, 1, N+1){
        max_num[i] = min((ll)1e17, 2 * max_num[i-1]) - A[i];
        if (max_num[i] < 0){
            print(-1);
            return 0;
        }
    }
    //    print(max_num);

    vector<ll> vec_num(N+1);
    vec_num[N] = A[N];
    REPN_REV(i, 1, N+1){

        ll n = max_num[i-1];

        if (vec_num[i] > 2 * n){
            print(-1);
            return 0;
        } else{
            vec_num[i-1] = min(n, vec_num[i]) + A[i-1];
        }
//        print(i, n, vec_num[i], vec_num[i-1]);
    }

//    print(vec_num);

    if (vec_num[0] > 1){
        print(-1);
        return 0;
    }
    ll ans = accumulate(ALL(vec_num), 0ll);
    print(ans);


    return 0;
}
