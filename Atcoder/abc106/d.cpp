// abc106_d
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define INF ((1 << 16)-1)
#define MOD (1000000007)
template <typename T> inline void print(const T& x) {cout << x << '\n';}
template <typename T, typename S> inline void print(const pair<T, S>& p) {cout << p.first << " " << p.second << endl;}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v) {for (auto&& p : v) print(p);}
template <typename T> inline void print(const vector<T>& v, string s = " ") {REP(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int train_map[501][501];
int cumsum[501][501];


int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N, M, Q;
    cin >> N >> M >> Q;

    int l, r;
    REP(i, M) {
        cin >> l >> r;
        train_map[l][r] += 1;
    }

    // 二次元累積和
    REPN(i, 1, N + 1) {
        REPN(j, 1, N + 1) {
            cumsum[i][j] = train_map[i][j] + cumsum[i][j - 1] + cumsum[i - 1][j] - cumsum[i - 1][j - 1];
        }
    }

    int p, q;
    REP(i, Q) {
        cin >> p >> q;
        cout << (cumsum[q][q] - cumsum[p - 1][q]) << endl;
    }

    return 0;
}


