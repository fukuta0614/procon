// abc161_e
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

    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vector<int> dp(N);
    vector<int> dp_rev(N);

    C++;

    int tmp_max_cnt = 0;
    int max_cnt = 0;
    REP(i, N){
        if (i - C >= 0){
            max_cnt = max(max_cnt, dp[i-C]);
        }

        if (S[i] == 'o'){
            dp[i] = max_cnt + 1;
        } else {
            dp[i] = tmp_max_cnt;
        }
        tmp_max_cnt = max(tmp_max_cnt, dp[i]);
    }

    max_cnt = 0;
    tmp_max_cnt = 0;
    REP_REV(i, N){
        if (i + C < N){
            max_cnt = max(max_cnt, dp_rev[i+C]);
        }

        if (S[i] == 'o'){
            dp_rev[i] = max_cnt + 1;
        } else {
            dp_rev[i] = tmp_max_cnt;
        }
        tmp_max_cnt = max(tmp_max_cnt, dp_rev[i]);
    }

//    print(dp);
//    print(dp_rev);

    REP(i, N) {
        if (S[i] == 'o') {
            if (i == 0){
                if (dp_rev[1] < K) print(i+1);
            } else if ( i == N-1){
                if (dp[N-2] < K) print(i+1);
            } else {
                if (dp[i - 1] + dp_rev[i + 1] < K) print(i+1);
            }
        }

    }
    return 0;



    // 以下WA


//    vector<bool> need(N, true);
//    need[0] = dp_rev[1] < K;
//    need[N-1] = dp[N-2] < K;
    vector<int> need_imos(N, 0);

    if (C == 1) C = 2; //特殊処理
    REP(i, N-C){
        if (dp[i] + dp_rev[i + C] >= K){
//            REPN(j, 1, C){
//                need[i+j] = false;
//            }
            need_imos[i+1] ++;
            need_imos[i+C] --;
        }
    }

    vector<bool> need(N, true);
    int cumsum = 0;
    REP(i, N){
        cumsum += need_imos[i];
        if (cumsum > 0){
            need[i] = false;
        }
    }
    need[0] = dp_rev[1] < K;
    need[N-1] = dp[N-2] < K;

//    print(need);

    REP(i, N){
        if (need[i] && S[i] == 'o'){
            print(i+1);
        }
    }

    return 0;
}
