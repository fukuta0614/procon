// arc119_b
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

    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    {
        int s=0, t=0;
        REP(i, N){
            s += S[i] - '0';
            t += T[i] - '0';
        }
        if (s != t){
            print(-1);
            return 0;
        }
    }

//    vector<int> vs(N), vt(N);
//    int s = -1, t = -1;
//    REP_REV(i, N){
//        if (S[i] == '0'){
//            s = i;
//        }
//        if (T[i] == '0'){
//            t = i;
//        }
//        vs[i] = s;
//        vt[i] = t;
//    }
//    reverse(ALL(S));
//    reverse(ALL(T));
//    print(S);
//    print(T);

    int cnt = 0;
    REP(i, N){
        if (S[i] != T[i] && S[i] == '0'){
            cnt++;
        }
    }
    print(cnt);

    int ans = 0;
    int s_idx = 0;
    int t_idx = 0;
    REP(i, N){
        if (S[i] != T[i]){
            if (S[i] == '1'){
                REPN(j, max(i, s_idx), N){
                    if (S[j] == '0'){
                        s_idx = j;
                        break;
                    }
                }
                swap(S[i], S[s_idx]);
            } else {
                REPN(j, max(i, t_idx), N){
                    if (T[j] == '0'){
                        t_idx = j;
                        break;
                    }
                }
                swap(T[i], T[t_idx]);
            }
            ans++;

//            print(i, s_idx, t_idx);
//            print(S);
//            print(T);
        }

    }

    assert(S == T);

    print(ans);




    return 0;
}
