// arc092_c
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF ((1 << 16)-1)
#define all(x) x.begin(), x.end()
struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N, x, y;
    cin >> N;

    int s = 0;
    int t = 2 * N + 1;

    vector<pair<int, int>> reds;
    vector<pair<int, int>> blues;

    REP(i, N) {
        cin >> x >> y;
        reds.emplace_back(make_pair(x, y));
    }
    REP(i, N) {
        cin >> x >> y;
        blues.emplace_back(make_pair(x, y));
    }

    sort(all(reds));
    sort(all(blues));

    multiset<int> tmp;
    int ans = 0;
    int idx = 0;
    for (auto q: blues) {
        while(idx < N) {
            auto p = reds[idx];
            if (p.first >= q.first) break;

            tmp.insert(p.second);
            idx++;
        }

        auto lb = tmp.lower_bound(q.second);
        if (lb != tmp.begin()) {
            ans++;
            tmp.erase(prev(lb));
        }
    }

    cout << ans << endl;

    return 0;
}


