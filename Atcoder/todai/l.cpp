// todai_l
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define all(x) x.begin(), x.end()
#define INF ((1 << 16)-1)
#define MOD (1000000007)
struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

typedef priority_queue<int> pqi;
#define MAX_N 100000

int C[MAX_N], par[MAX_N], depth[MAX_N] = {0};
vector<int> G[MAX_N];
pqi pq[MAX_N];

void meld(pqi &a, pqi &b){
    if (a.size() < b.size()) swap(a, b);
    // a > b
    while (!b.empty()){
        a.push(b.top());
        b.pop();
    }
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N >> C[0];
    par[0] = -1;

    REPN(i, 1, N) {
        cin >> par[i] >> C[i]; par[i]--;
        G[par[i]].emplace_back(i);
        depth[i] = depth[par[i]] + 1;
        C[i] += depth[i]; // これによりじょうしょうの定義が ~より大きい -> ~以上に（コストは変わらない)
    }

    ll ans = 0;
    REP_REV(i, N){
        for (auto v: G[i]) meld(pq[i], pq[v]);
        pq[i].push(C[i]);
        pq[i].push(C[i]);
        ans += pq[i].top() - C[i];
        pq[i].pop();
    }

    cout << ans << endl;
}

