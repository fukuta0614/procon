// agc052_a
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        vector<string> S(3);
        REP(i, 3) cin >> S[i];

        vector<string> cands;
        REP(k, 8){
            string tmp;

            int p = k;
            REP(i, N) tmp += p & 1 ? '0' : '1';
            p >>= 1;
            tmp += p & 1 ? '0' : '1';
            p >>= 1;
            REP(i, N) tmp += p & 1 ? '0' : '1';

            cands.emplace_back(tmp);
        }

        print(cands);

        auto check = [](const string& s, const string& tmp){
            int idx = 0;
            bool valid_tmp = false;
            REP(i, s.size()){
                if (tmp[idx] == s[i]){
                    idx++;
                    if (idx == tmp.size()){
                        valid_tmp = true;
                        break;
                    }
                }
            }
            return valid_tmp;
        };

        vector<bool> valids(8, true);
        REP(i, 3){
            string s = S[i] + S[i];

            REP(k, 8){
                bool valid = check(s, cands[k]);
                valids[k] = valids[k] & valid;
            }
        }

        bool done = false;
        REP(k, 8){
            if (valids[k]){
                print(cands[k]);
                done = true;
                break;
            }
        }

        if (not done){
            print(S);
            assert(false);
        }
    }

    return 0;
}
