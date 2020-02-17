// csa_200125_c
// Triangular Matrix
// https://csacademy.com/contest/round-59/task/triangular-matrix/
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

    int N;
    cin >> N;
    vector<string> mat(N);
    REP(i, N) cin >> mat[i];

    string ans;
    vector<int> indices;
    REP(i, N){
        auto s = mat[i];

        if (i == 0){
            ans += s[0];
            indices.emplace_back(0);
            continue;
        }

        char min_c = 'z';
        for (auto idx: indices){
            min_c = min(min_c, s[idx]);
            min_c = min(min_c, s[idx+1]);
        }

        vector<int> tmp;
        for (auto idx: indices){
            if (s[idx] == min_c) tmp.emplace_back(idx);
            if (s[idx+1] == min_c) tmp.emplace_back(idx+1);
        }

        sort(ALL(tmp));
        tmp.erase(unique(ALL(tmp)), tmp.end()); // 重複削除
        indices = tmp;

        ans += min_c;
    }

    print(ans);


    return 0;
}
