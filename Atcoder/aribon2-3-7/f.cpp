#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define ALL(x) begin(x), end(x)
using namespace std;
#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

constexpr int mod = 1e9 + 7;

int func(vector<int> const & kill, int sum_death) {
    int n = kill.size();
    vector<int> cur(sum_death + 1);  // main DP
    vector<int> prv(sum_death + 1);
    cur[0] = 1;
    REP (l, n) {
        int r = l + 1;
        while (r < n and kill[l] == kill[r]) ++ r;
        cur.swap(prv);
        REP (j, min(r - l, sum_death + 1)) {
            cur[j] = prv[j];
        }
        REP3 (j, r - l, sum_death + 1) {
            cur[j] = cur[j - (r - l)] + prv[j];
            if (cur[j] >= mod) cur[j] -= mod;
        }
        print(cur);

    }

    return cur[sum_death];
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    // input
    int n, m; cin >> n >> m;
    vector<int> kill_a(n); REP (i, n) cin >> kill_a[i];
    vector<int> kill_b(m); REP (i, m) cin >> kill_b[i];
    // solve
    int sum_kill_a = accumulate(ALL(kill_a), 0);
    int sum_kill_b = accumulate(ALL(kill_b), 0);
    int x = func(kill_a, sum_kill_b);
    int y = func(kill_b, sum_kill_a);
    int result = x *(long long) y % mod;
    // output
    cout << result << endl;
    return 0;
}