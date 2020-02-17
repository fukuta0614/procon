// csa_200125_d
// Cookie Clicker
// https://csacademy.com/contest/archive/task/cookie-clicker
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

    int N, C, S;
    cin >> N >> C >> S;

    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];


    auto func = [&](int n, vector<int>& order){

        int cookie = 0;
        int t = 0;
        int cpt = S; //cookie per time

        REP(i, n){
            int tmp = (A[order[i]] - cookie + cpt - 1) / cpt;

            t += tmp;
            cookie = cookie + tmp * cpt - A[order[i]];
            cpt += B[order[i]];

            // 次の工場も買えるなら買う。
            while (i < n-1 && cookie >= A[order[i+1]]){
                cookie -= A[order[i+1]];
                cpt += B[order[i+1]];
                i++;
            }
        }

        // もう目標量を超えてる場合は、買わなくていい工場を買っている。（無視）
        if (cookie >= C){
            return t;
        }

        // このペースで C 貯まるまで待つ。
        int tmp = (C - cookie + cpt - 1) / cpt;
        t += tmp;

//        print(n, order, t);

        return t;
    };


    vector<int> order(N);
    iota(ALL(order), 0);

    int ans = INF;
    do {
        REP(n, N+1){ // 工場を0個買う ~ N個買う

            int t = func(n, order);
            ans = min(ans, t);
        }
    } while(next_permutation(ALL(order)));


    print(ans);



    return 0;
}
