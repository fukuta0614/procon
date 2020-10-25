// abc164_f
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
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

void invalid(){
    print(-1);
    exit(0);
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<ull> S(N), T(N), U(N), V(N);
    REP(i, N) cin >> S[i]; // row, 0: AND 1: OR
    REP(i, N) cin >> T[i]; // col, 0: AND 1: OR

    REP(i, N) cin >> U[i]; // row
    REP(i, N) cin >> V[i]; // col

    vector<vector<ull>> ans(N, vector<ull>(N, 0));

    REP(d, 64){
//        print(d);
        vector<bool> u(N), v(N);
        REP(i, N) {
            u[i] = (U[i] >> d) & 1;
            v[i] = (V[i] >> d) & 1;
        }

        vector<vector<int>> A(N, vector<int>(N, -1));

        // 確定row
        REP(i, N){
            if (S[i] == 0 && u[i] == 1){ // AND = 1
                REP(j, N){
                    A[i][j] = 1;
                }
            }

            if (S[i] == 1 && u[i] == 0){ // OR = 0
                REP(j, N){
                    A[i][j] = 0;
                }
            }
        }

        // 確定col
        REP(j, N){
            if (T[j] == 0 && v[j] == 1){ // AND = 1
                REP(i, N){
                    if (A[i][j] == 0) invalid();
                    A[i][j] = 1;
                }
            }

            if (T[j] == 1 && v[j] == 0){ // OR = 0
                REP(i, N){
                    if (A[i][j] == 1) invalid();
                    A[i][j] = 0;
                }
            }
        }

        // 縦横の条件が OR=1かつOR=1　もしくはAND=0かつAND=0のセルは、
        // この時点で確定させてしまって良い。このせいで矛盾が生まれることが絶対ないため
        REP(i, N) REP(j, N) {
            if (S[i] == T[j] && u[i] == v[j]) {
                A[i][j] = u[i];
            }
        }


        // この時点で、AND=0 かつ OR=1 のセルだけが未確定
        // AND=0の行で、まだ0がない場合、OR=1の列のどれかを0にする。
        // OR=1の列で、すでに条件を満たしている列は優先的に選択する。（この場合1がすでにある）
        // すでに条件を満たしている列がない場合も、結局どれを選んでも等価なので、貪欲に選び、
        // 最後に選べなくなったらアウト

        // まず、各列がすでに条件を満たしているかどうかを確認
        vector<bool> satisfied(N, false);
        REP(j, N){
            if (T[j] == 0 && v[j] == 1) satisfied[j] = true; // AND = 1
            if (T[j] == 1 && v[j] == 0) satisfied[j] = true; // OR = 0

            if (T[j] == 0 && v[j] == 0) { // AND = 0
                REP(i, N) {
                    if (A[i][j] == 0) satisfied[j] = true;
                }
            }
            if (T[j] == 1 && v[j] == 1) { // OR = 1
                REP(i, N) {
                    if (A[i][j] == 1) satisfied[j] = true;
                }
            }
        }

        // 行ごとに貪欲に決めていく
        REP(i, N){
            if (S[i] == 0 && u[i] == 1) continue; // AND = 1
            if (S[i] == 1 && u[i] == 0) continue; // OR = 0

            int x = u[i];
            bool sat = false;

            // すでに満たしてるか
            REP(j, N) {
                if (A[i][j] == x) sat = true;
            }

            // すでに満たしている列を利用して満たせるか
            if (not sat){
                REP(j, N) {
                    if (A[i][j] == -1 && satisfied[j]) {
                        A[i][j] = x;
                        sat = true;
                        break;
                    }
                }
            }

            // 満たしていないけどとりあえず満たせるようにする
            if (not sat){
                REP(j, N) {
                    if (A[i][j] == -1) {
                        A[i][j] = x;
                        sat = true;
                        break;
                    }
                }
            }

            // それでもだめなら終了
            if (not sat) invalid();

            // 確定していないやつを有利な方に帰る
            REP(j, N){
                if (A[i][j] == -1){
                    A[i][j] = v[j];
                    satisfied[j] = true;
                }
            }
        }

        // まだ満たしていない列があったらアウト
        REP(j, N){
            if (not satisfied[j]) invalid();
        }

        // ここまで来たら全部確定している
        REP(i, N) REP(j, N){
            ans[i][j] |= (ull)A[i][j] << d;
        }
    }

    REP(i, N){
        print_line(ans[i], N);
    }

    return 0;
}
