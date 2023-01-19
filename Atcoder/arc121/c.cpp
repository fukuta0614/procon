// arc121_c
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

bool dfs(const vector<int>& origin, vector<int>& p, vector<int>& ans, int depth){
    bool b = true;
    bool c = true;
    REP(i, min(int(p.size()), 4)) {
        b &= p[i] == i;
        c &= p[i] == origin[i];
    }
    if (b){
        return true;
    }

    if (depth > 0 && c){
        return false;
    }

    if (depth > 10){
        return false;
    }

    for (int i = (ans.size() % 2 == 0 ? 0 : 1); i < min(int(p.size()), 3); i += 2) {
        swap(p[i], p[i+1]);
        ans.emplace_back(i+1);
        bool res = dfs(origin, p, ans, depth+1);
        if (res) return true;
        ans.pop_back();
        swap(p[i], p[i+1]);
    }

    return false;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        vector<int> p(N);
        REP(i, N) cin >> p[i], p[i]--;
//        std::mt19937 mt(T);
//        int N = mt() % 100;
//        vector<int> p(N);
//        iota(ALL(p), 0);
//        shuffle(ALL(p), mt);

        auto q = p;
//        print(p);

        vector<int> ans;
        REPN_REV(i, 4, N){

            int idx = -1;
            REP(j, N){
                if (p[j] == i){
                    idx = j;
                    break;
                }
            }
            if (idx == i) continue;
//            print(i, ans.size() % 2, p);

            if ((ans.size() % 2) != (idx % 2)) {
                int tmp = ans.size() % 2;
                if (tmp+1 == idx){
                    tmp += 2;
                }
                ans.emplace_back(tmp+1);
                swap(p[tmp], p[tmp+1]);
            }

            while (idx != i){
                swap(p[idx], p[idx+1]);
                ans.emplace_back(idx+1);
                idx++;
            }
        }

        vector<int> origin(4);
        REP(i, min(4, int(p.size()))) origin[i] = p[i];
        dfs(origin, p, ans, 0);

        vector<int> v(N);
        iota(ALL(v), 0);
        assert(v == p);

        REP(i, ans.size()){
            assert(((ans[i]-1) % 2) == (i % 2));
            swap(q[ans[i]-1], q[ans[i]]);
        }
        assert(q == p);
        assert(ans.size() <= N*N);

        print(ans.size());
        if (not ans.empty()) {
            print_line(ans, ans.size());
        } else {
            print("");
        }
    }


    return 0;
}
