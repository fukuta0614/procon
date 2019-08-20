// aribon3-3_c
// E - Papple Sort
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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct BIT { // 1-index
    int sz;
    vector<int> tree;

    BIT(int n) {
        sz = n;
        tree.resize(n+1);
    }

    ll sum(int i){
        ll sm = 0;
        while (i > 0){
            sm += tree[i];
            i -= i & -i;
        }
        return sm;
    }

    void add(int i, int x){
        while (i <= sz){
            tree[i] += x;
            i += i & -i;
        }
    }
};

typedef enum {
    LEFT = 1,
    MIDDLE,
    RIGHT
} ePOS;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S;
    cin >> S;
    int n = S.size();

    map<char, int> mp;
    for (auto c: S){ mp[c]++; }

    // できるかどうかcheck
    int odd_cnt = 0;
    for (auto p: mp){ if (p.second % 2 == 1) odd_cnt++; }
    if ((n % 2 == 0 && odd_cnt > 0) || (n % 2 == 1 && odd_cnt > 1)) {
        print(-1);
        return 0;
    }

    // 左側と右側に分ける
    map<char, int> mp_tmp;
    vector<int> pos(n);
    deque<char> left, right;
    REP(i, n){
        char c = S[i];
        mp_tmp[c]++;
        if (2 * mp_tmp[c] - 1  < mp[c]) {
            pos[i] = LEFT;
            left.emplace_back(c);
        } else if (2 * mp_tmp[c] - 1  == mp[c]) {
            pos[i] = MIDDLE;
        } else {
            pos[i] = RIGHT;
            right.emplace_front(c);
        }
    }

    ll ans = 0;

    // 000012222 となるまでの転倒数カウント
    auto bit = BIT(n+1);
    REP_REV(i, n){
        ans += bit.sum(pos[i] - 1);
        bit.add(pos[i], 1);
    }

    int n2 = left.size();

    // left->rightのindexテーブル
    map<char, deque<int>> mp_table;
    REP(i, n2){
        mp_table[right[i]].emplace_back(i+1); // あとでbitが1-indexでいけるようにi+1
    }
    vector<int> table(n2);
    REP(i, n2){
        table[i] = mp_table[left[i]][0];
        mp_table[left[i]].pop_front();
    }

    // left -> rightの転倒数カウント
    auto bit2 = BIT(n2+1);
    REP_REV(i, n2){
        ans += bit2.sum(table[i] - 1);
        bit2.add(table[i], 1);
    }

    print(ans);

    return 0;
}
