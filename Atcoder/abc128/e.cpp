// abc128_e
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

struct Kouji {
    int s, t, x;
};
ostream& operator <<(ostream& os, Kouji p) { return os << "(" << p.s << ", " << p.t << ", " << p.x << ")"; }

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, Q;
    cin >> N >> Q;

    vector<Kouji> koujis(N);
    REP(i, N) {
        cin >> koujis[i].s >> koujis[i].t >> koujis[i].x;
        koujis[i].s -= koujis[i].x;
        koujis[i].t -= koujis[i].x;
    }
    sort(ALL(koujis), [](const Kouji& a, const Kouji& b) { return a.s < b.s; });

    vector<int> D(Q);
    REP(i, Q) cin >> D[i];
    sort(ALL(D));

    // 小さい方から出てくる
    auto comp = [](const Kouji& a, const Kouji& b) { return a.x > b.x; };
    priority_queue<Kouji, vector<Kouji>, decltype(comp)> pq(comp);

    int kouji_idx = 0;
    REP(i, Q) {
        int d = D[i];

        for (; kouji_idx < N; kouji_idx++){
            if (d < koujis[kouji_idx].s) {
                break;
            }
            pq.push(koujis[kouji_idx]);
        }

//        auto tmp = pq;
//        cout << kouji_idx << ", "; while (!tmp.empty()) {cout << tmp.top() << " "; tmp.pop();} print("");

        while (!pq.empty()) {
            Kouji tp = pq.top();
            if (d < tp.t) {
                print(tp.x); break;
            } else {
                pq.pop();
            }
        }

        if (pq.empty()) {
            print(-1);
        }
    }

    return 0;
}
