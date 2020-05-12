// gcj2020_c
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

    int T;
    cin >> T;

    REP(t, T){

        int N;
        cin >> N;
        vector<tuple<int, int, int>> A(N);
        REP(i, N){
            int s, e;
            cin >> s >> e;
            A[i] = {s, e, i};
        }

        sort(ALL(A), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
            return get<0>(a) < get<0>(b);
//            return get<1>(a) != get<1>(b) ?
//                   get<1>(a) < get<1>(b) :
//                   get<0>(a) < get<0>(b);
        });

//        print(A);

        int tmp1 = 0;
        int tmp2 = 0;
        vector<string> ans(N);
        REP(i, N){
            int s, e, idx;
            tie(s, e, idx) = A[i];
            if (tmp1 <= s){
                tmp1 = e;
                ans[idx] = "C";
            } else if (tmp2 <= s){
                tmp2 = e;
                ans[idx] = "J";
            } else{
                ans.clear();
                break;
            }
        }


        if (ans.empty()){
            printf("Case #%d: IMPOSSIBLE\n", t+1);
        } else {
            string ans2;
            REP(i, N) ans2 += ans[i];
            printf("Case #%d: %s\n", t+1, ans2.c_str());
        }

    }


    return 0;
}
