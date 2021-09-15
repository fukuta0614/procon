// ahc002_a
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
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

#include <chrono>
struct Timer {
    std::chrono::time_point<std::chrono::system_clock> begin;

    void init() {
        begin = std::chrono::system_clock::now();
    }

    int get_ms() {
        auto cur = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(cur - begin).count();
    }
};

struct Grid {

    const int H, W;
    int S[52][52], T[50][50];
    Timer timer;

    const int di[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
    const int dj[8]={ 0, 1, 0, -1, -1, -1, 1, 1};
    bool bound_check(int i, int j) const {return (0 <= i) && (i < H) && (0 <= j) && (j < W);}

    const char order[4] = {'D', 'R', 'U', 'L'};

    [[nodiscard]] int hash_func(int i, int j) const {
        return i * W + j;
    }

    [[nodiscard]] tuple<int, int> rev_hash(int h) const{
        int i = h / W;
        int j = h % W;
        return tie(i, j);
    }

    Grid(int H, int W): H(H), W(W){}

    vector<bool> used;
    int score = 0;
    int max_score = 0;

    string sequence;
    string ans;

    int cnt = 0;

    void dfs(int i, int j){
        cnt++;

        used[S[i][j]] = true;
        score += T[i][j];

        if (score > max_score){
            max_score = score;
            ans = sequence;
        }

        if (timer.get_ms() > 1900){
            throw 1;
        }

        REP(k, 4){
            int ni = i + di[k];
            int nj = j + dj[k];
//            if (not bound_check(ni, nj)) continue;
            if (used[S[ni][nj]]) continue;

            sequence += order[k];
            dfs(ni, nj);
            sequence.pop_back();
        }

        score -= T[i][j];
        used[S[i][j]] = false;

    }

    void dfs_norec(int si, int sj){

        vector<tuple<int, int, int, int>> stk;
        stk.emplace_back(0, 0, si, sj);

        while (not stk.empty()) {
            auto [idx, k, i, j] = stk.back(); stk.pop_back();

            used[S[i][j]] = true;
            score += T[i][j];

            if (score > max_score){
                max_score = score;
                ans = sequence;
            }

            if (timer.get_ms() > 1900){
                throw 1;
            }

            REP(k, 4){
                int ni = i + di[k];
                int nj = j + dj[k];
                if (not bound_check(ni, nj)) continue;
                if (used[S[ni][nj]]) continue;

                sequence += order[k];
                dfs(ni, nj);
                sequence.pop_back();
            }

            score -= T[i][j];
            used[S[i][j]] = false;
        }


    }

    string solve(int si, int sj, vector<vector<int>>& S_org, vector<vector<int>>& T_org){

        // init
        int mx = 0;
        REP(i, H) REP(j, W){
            mx = max(mx, S_org[i][j]);

            S[i+1][j+1] = S_org[i][j];
            T[i][j] = T_org[i][j];
        }

        mx++;
        REP(i, H) S[i][0] = S[i][W+1] = mx;
        REP(j, W) S[0][j] = S[H+1][j] = mx;

        used.assign(mx+1, false);
        used[mx] = true;

        si++; sj++;

        // exec
        timer.init();
        try{
            dfs(si, sj);
        } catch(int& n){
            ;
        }
        return ans;
    }

};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int si, sj;
    cin >> si >> sj;

    vector<vector<int>> S(50, vector<int>(50)), T(50, vector<int>(50));
    REP(i, 50) REP(j, 50) cin >> S[i][j];
    REP(i, 50) REP(j, 50) cin >> T[i][j];

    Grid g(50, 50);

    string ans = g.solve(si, sj, S, T);
    print(ans);

#ifdef LOCAL
    print(g.max_score);
    print(g.cnt);
#endif

    return 0;
}
