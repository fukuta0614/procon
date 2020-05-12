// abc149_d
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

    int N, K;
    cin >> N >> K;

    int R, S, P;
    cin >> R >> S >> P;

    string T;
    cin >> T;

    map<char, int> char2idx;
    char2idx['r'] = 0;
    char2idx['s'] = 1;
    char2idx['p'] = 2;

    vector<int> scores{R, S, P};

    ll ans = 0;
    int pre = 0;
    REP(i, K) {
        for (int idx = i; idx < N; idx += K){
            int cur = char2idx[T[idx]];
            int vic = (3 + cur - 1) % 3;

//            print(i, idx, pre, cur, vic);
            if (idx < K || vic != pre){
                ans += scores[vic];
//                print(scores[vic]);
                pre = vic;
            } else {
                if (idx + K < N){
                    int nxt = char2idx[T[idx + K]];
                    int nxt_vic = (3 + nxt - 1) % 3;
                    if (nxt_vic == pre){
                        pre = (pre + 1) % 3;
                    } else {
                        pre = 3 - pre - nxt_vic;
                    }
                }
            }
        }
    }

    print(ans);


    return 0;
}
