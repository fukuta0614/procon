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

unsigned int xor_shift() {
    static unsigned int y = 2463534242;
    y = y ^ (y << 13);
    y = y ^ (y >> 17);
    return y = y ^ (y << 5);
}

struct Grid {

    const int H, W;
    int S[50][50], T[50][50];
    Timer timer;

    const int di[4]={ 1, 0, 0, -1, };
    const int dj[4]={ 0, 1, -1, 0, };
    [[nodiscard]] bool bound_check(int i, int j) const {return (0 <= i) && (i < H) && (0 <= j) && (j < W);}

    const char order[4] = {'D', 'R', 'L', 'U'};

//    map<char, int> rev = {{'D',0}, {'R',1}, {'L',2}, {'U',3}};

    [[nodiscard]] int hash_func(int i, int j) const {
        return i * W + j;
    }

    [[nodiscard]] tuple<int, int> rev_hash(int h) const{
        int i = h / W;
        int j = h % W;
        return tie(i, j);
    }

    Grid(int H, int W, vector<vector<int>>& S_tmp, vector<vector<int>>& T_tmp): H(H), W(W){
        REP(i, H) REP(j, W){
                S[i][j] = S_tmp[i][j];
                T[i][j] = T_tmp[i][j];
            }
    }

    bool used[2500]{};
    int score = 0;
    int max_score = 0;

    string sequence;
    string ans;

    void dfs_norec(int si, int sj, int& counter) noexcept {

        vector<tuple<int, int, int>> stk;
        stk.emplace_back(si, sj, 0);

        int rev[26];
        rev['D' - 'A'] = 0;
        rev['R' - 'A'] = 1;
        rev['L' - 'A'] = 2;
        rev['U' - 'A'] = 3;

        int i = si;
        int j = sj;
        used[S[i][j]] = true;

        while (not stk.empty()) {
            counter++;
            // auto [pi, pj, k] = stk.back(); stk.pop_back();
            auto [pi, pj, k] = stk.back();

            while (i != pi || j != pj){
                score -= T[i][j];
                used[S[i][j]] = false;

                char c = sequence.back();
                sequence.pop_back();
                i = i - di[rev[c - 'A']];
                j = j - dj[rev[c - 'A']];
            }


            bool is_leaf = true;
            for (int kn=k; kn<4; kn++) {
                int ni = i + di[kn];
                int nj = j + dj[kn];
                if (not bound_check(ni,nj)) continue;
                int idx = S[ni][nj];
                if (used[idx]) continue;

                used[idx] = true;
                is_leaf = false;
                std::get<2>(stk.back()) = kn+1;
                stk.emplace_back(ni,nj,0);
                i=ni;
                j=nj;
                sequence += order[kn];
                score += T[i][j];
                break;
            }
            if (is_leaf) {
                stk.pop_back();
                if (score > max_score){
                    max_score = score;
                    ans = sequence;
                }
            }
            if (counter % 100 == 0 && timer.get_ms() > 1950){
                return;
            }
        }
    }

    string solve(int si, int sj){

        // init
        int mx = 0;
        // REP(i, H) REP(j, W) mx = max(mx, S[i][j]);
        // used.assign(mx+1, false);

        // exec
        timer.init();
        int counter = 0;
        dfs_norec(si, sj, counter);
        cerr << counter << "\n";
//        try{
//            dfs(si, sj);
//        } catch(int& n){
//            ;
//        }
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

    Grid g(50, 50, S, T);

    string ans = g.solve(si, sj);
    print(ans);

#ifdef LOCAL
    print(g.max_score);
#endif

    return 0;
}

