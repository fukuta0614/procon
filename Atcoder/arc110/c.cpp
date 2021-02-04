// arc110_c
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
    vector<int> P(N);
    REP(i, N) {cin >> P[i]; P[i]--;}

    vector<bool> done(N, false);
    vector<int> ans;
    vector<int> state(N);
    REP(i, N){
        state[i] = P[i] - i;
    }

    vector<int> cand;
    REP(i, N-1){
        if (state[i] > 0 && state[i+1] < 0){
            cand.emplace_back(i);
        }
    }

//    print(state, P);

    while (not cand.empty()){
        int i = cand.back(); cand.pop_back();
        if (done[i]) continue;

        ans.emplace_back(i);
        done[i] = true;
        swap(P[i], P[i+1]);

        state[i]--;
        state[i+1]++;
        swap(state[i], state[i+1]);

//        print(state, P);

        if (i < N-2 && state[i+1] > 0 && state[i+2] < 0 && not done[i+1]){
            cand.emplace_back(i+1);
        }
        if (i > 0 && state[i-1] > 0 && state[i] < 0 && not done[i-1]){
            cand.emplace_back(i-1);
        }
    }

    if (ans.size() == N-1){
        bool ok = true;
        REP(i, N){
            if (P[i] != i){
                ok = false;
                break;
            }
        }

        if (not ok){
            print(-1);
            return 0;
        }

        REP(i, N-1){
            print(ans[i]+1);
        }
    } else {
        print(-1);
    }


    return 0;
}
