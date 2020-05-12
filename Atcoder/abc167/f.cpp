// abc167_f
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

    int N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) cin >> S[i];

    vector<P> A; // (((, )(((
    vector<P> B; // ))), )))(
    REP(i, N){
        int l=0, r=0; // ), (
        REP(j, S[i].size()){
            if (S[i][j] == '('){
                r++;
            } else {
                if (r > 0){
                    r--;
                } else{
                    l++;
                }
            }
        }
        if (r - l > 0){
            A.emplace_back(l, r);
        } else {
            B.emplace_back(r, l);
        }
    }

    sort(ALL(A));
    sort(ALL(B));

    // ), (
    int tmp = 0; // (( が何
    REP(i, A.size()){

        if (A[i].first > tmp){ // (( を　)) が超えたらだめ
            print("No");
            return 0;
        }
        tmp += A[i].second - A[i].first; // ()))
//        print(i, A[i], tmp);
    }

    // (, )
    int tmp2 = 0;
    REP(i, B.size()){

        if (B[i].first > tmp2){ // )) を　(( が超えたらだめ
            print("No");
            return 0;
        }
        tmp2 += B[i].second - B[i].first; // ()))
//        print(i, B[i], tmp);
    }

    if (tmp == tmp2){
        print("Yes");
    } else {
        print("No");
    }

//    ll r = 0;
//    ll l = 0;
//    REP(i, N){
//
//
//        if (A[i].first == 0){  // ( だけ
//            r += A[i].second;
//        } else if (A[i].second == 0)  {// ) だけ
//            l += A[i].first;
//        } else {
//
//        }
//    }

    return 0;
}
