// abc177_e
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
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int gcd(int a,int b){return b?gcd(b,a%b):a;}


struct FastFactorization{
    vector<int> smallest_divisor;

    FastFactorization(int N): smallest_divisor(N+1, -1){
        smallest_divisor[1] = 1;
        for (int n=2; n<=N; n++){
            if (smallest_divisor[n] != -1) continue;
            for (int x = n; x <= N; x+=n) smallest_divisor[x] = n;
        }
    }

    map<int, int> operator()(int N){
        map<int, int> res;
        int n = N;
        while (n > 1) {
            int d = smallest_divisor[n];
            res[d]++;
            n /= d;
        }
        return res;
    };
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    vector<int> A(N);
    REP(i, N) cin >> A[i];

    int mx = 1e6;
    FastFactorization f(mx);

    vector<int> res(mx+1, false);
    bool pairwise = true;
    REP(i, N){

        auto tmp = f(A[i]);

        for (auto e: tmp){
            int d = e.first;
            if (res[d]){
                pairwise = false;
                break;
            }
            res[d] = true;
        }
        if (not pairwise) break;
    }

//    print(res);

//    vector<int> res(1e6+1);
//    REP(i, N){
//        ll tmp = A[i];
//        for (ll a = 2; a * a <= A[i]; a++) {
//            int cnt = 0;
//            while (tmp % a == 0){ cnt++; tmp /= a; }
//            if (cnt > 0) {
//                if (res[a] > 0) {
//                  pairwise = false;
//                  break;
//                }
//                res[a]++;
//            }
//        }
//        if (tmp > 1) {
//            if (res[tmp] > 0) {
//                pairwise = false;
//                break;
//            }
//            res[tmp]++;
//        }
//
//        if (pairwise == false) break;
//    }
//    print(res);

//    for (auto e: res){
//        if (e.second >= 2){
//            pairwise = false;
//            break;
//        }
//    }

    if (pairwise){
        print("pairwise coprime");
        return 0;
    }

    int d = 0;
    REP(i, N){
        d = gcd(A[i], d);
    }

//    print(d);

    if (d == 1){
        print("setwise coprime");
    } else {
        print("not coprime");
    }


    return 0;
}
