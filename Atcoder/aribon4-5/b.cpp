// aribon4-5_b
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


pair<int, int> dfs(string& S, int& i, int last_idx){

    if (i > last_idx) return {0, 99};

    if ('0' <= S[i] && S[i] <= '9') {
        int n = S[i] - '0';
        i++;

        if (n == 0) return {0, 0};
        if (i > last_idx) return {n, 10*n+9};

        if ('0' <= S[i] && S[i] <= '9') {
            n = 10 * n + S[i] - '0';
            i++;
        }
        return {n, n};
    } else if (S[i] == '_' || S[i] == '^'){
        bool max_mode = S[i] == '^';

        i += 2;
        auto lhs = dfs(S, i, last_idx); //左辺
        i++;
        auto rhs = dfs(S, i, last_idx); //右辺
        i++;
        if (max_mode) {
            return {max(lhs.first, rhs.first), max(lhs.second, rhs.second)};
        } else {
            return {min(lhs.first, rhs.first), min(lhs.second, rhs.second)};
        };
    } else {
        assert(false); //来ないはず
        return {-1, -1};
    }
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int Q;
    cin >> Q;

    REP(_, Q){
        string S;
        cin >> S;

        int ok = S.size()-1;
        int ng = -1;
        while (ok - ng > 1){
            int last_idx = (ok + ng) / 2;
            int idx = 0;
            auto res = dfs(S, idx, last_idx);
            if (res.first == res.second){
                ok = last_idx;
            } else {
                ng = last_idx;
            }
        }
        int idx=0;
        auto res = dfs(S, idx, ok);
        print(res.first, ok+1);

//        REP(last_idx, S.size()){
//            int idx = 0;
//            auto res = dfs(S, idx, last_idx);
//            if (res.first == res.second){
//                print(res.first, last_idx+1);
//                break;
//            }
//        }

    }

    return 0;
}
