// abc146_d
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

    int N, M, D;
    cin >> N >> M >> D;

    vector<int> amida(N);
    iota(ALL(amida), 0);
    REP(i, M){
        int idx;
        cin >> idx; idx--;
        swap(amida[idx], amida[idx+1]);
    }
    // amida -> [4 1 3 0 2]

    vector<int> single_transition(N);
    REP(i, N){
        int idx = amida[i];
        single_transition[idx] = i;
    }
    // single_transition -> [3 1 4 2 0]

    vector<vector<int>> transition_group;
    vector<bool> used(N);
    REP(i, N){
        if (used[i]) continue;

        vector<int> tmp{i};
        used[i] = true;

        int x = i;
        while (not used[single_transition[x]]){
            x = single_transition[x];
            tmp.emplace_back(x);
            used[x] = true;
        }
        transition_group.emplace_back(tmp);
    }
    // transition_group -> [[0, 3, 2, 4], [1]]

    vector<int> ans(N);
    for (auto transition: transition_group){

        int n = transition.size();
        int shift = D % n;
        REP(i, n){
            ans[transition[i]] = transition[(i + shift)%n];
        }
    }

    REP(i, N){
        print(ans[i]+1);
    }

    return 0;
}
