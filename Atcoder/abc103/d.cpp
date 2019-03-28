// abc103_d
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define ALL(x) x.begin(), x.end()

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;

    vector<P> D;
    REP(i, M){
        int a,b;
        cin >> a >> b;
        D.emplace_back(P(a,b));
    }
    D.emplace_back(P(N,N));
    sort(ALL(D));

    int ans = 0;
    int tmp = N + 1;
    for (auto p: D){
        if (tmp <= p.first) {
            ans++;
            tmp = p.second;
        } else {
            tmp = min(tmp, p.second);
        }
    }

    cout << ans << endl;
    return 0;
}


