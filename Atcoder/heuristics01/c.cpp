// heuristics01_c
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


struct Solver {

    int D;
    vector<ll> C;
    vector<vector<ll>> S;
    vector<int> T;

    vector<vector<int>> history;
    ll score = 0;

    Solver(int D_, vector<ll>& C_, vector<vector<ll>>& S_, vector<int>& T_) {
        D = D_;
        C = C_;
        S = S_;
        T = T_;

        history.assign(26, vector<int>{0});
    }

    ll eval_func(){
        vector<int> last(26, 0);
        REPN(d, 1, D+1){
            int x = T[d-1];
            score += S[d-1][x];
            last[x] = d;
            history[x].emplace_back(d);
            REP(j, 26){
                score -= C[j] * (d - last[j]);
            }
        }
        return score;
    }

    ll eval_func_diff(int d, int q){
        score -= S[d-1][T[d-1]];
        score += S[d-1][q];

        int x = T[d-1];
        {
            auto it = lower_bound(ALL(history[x]), d);
            int idx = it - history[x].begin();
            int num;
            if (idx == history[x].size() - 1){ // idxが最後だったら
                num = D+1 - history[x][idx];
            } else {
                num = history[x][idx+1] - history[x][idx];
            }
            int diff = history[x][idx] - history[x][idx-1];
            score -= C[x] * num * diff;
            history[x].erase(it);
            T[d-1] = q;
        }

        {
            auto it = lower_bound(ALL(history[q]), d);
            int num;
            if (it == history[q].end()){ // idxが最後だったら
                num = D+1 - d;
            } else {
                num = *it - d;
            }
            it--;
            int diff = d - *it;
            score += C[q] * num * diff;

            it++;
            history[q].insert(it, d);
        }

        return score;

    }


};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int D;
    cin >> D;
    vector<ll> C(26);
    REP(i, 26) cin >> C[i];
    vector<vector<ll>> S(D, vector<ll>(26, 0));
    REP(i, D) REP(j, 26) cin >> S[i][j];

    vector<int> T(D);
    REP(i, D) {cin >> T[i]; T[i]--;}

    Solver solver(D, C, S, T);

    int M;
    cin >> M;
    vector<int> d(M), q(M);
    REP(i, M) cin >> d[i] >> q[i];

    solver.eval_func();
    REP(i, M){
        q[i]--;
        ll score = solver.eval_func_diff(d[i], q[i]);
//        REP(j, 26){
//            print(solver.history[j]);
//        }
        print(score);
    }

    return 0;
}
