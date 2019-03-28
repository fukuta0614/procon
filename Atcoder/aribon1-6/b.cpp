// aribon1-6_b
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define all(x) x.begin(), x.end()
#define INF ((1 << 16)-1)
#define MOD (1000000007)
#define print(arr, n) REP(i, n) cout << arr[i] << " ";

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll calc_dist(pair<int, int> p1, pair<int, int> p2){
    ll dist = 0;
    dist += (p1.first - p2.first) * (p1.first - p2.first);
    dist += (p1.second - p2.second) * (p1.second - p2.second);
    return dist;
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<pair<int, int>> pos;

    REP(i, N){
        int x, y;
        cin >> x >> y;
        pos.emplace_back(make_pair(x, y));
    }

    ll max_dist = 0;
    REP(i, N){
        REPN(j, i+1, N){
            ll dist = calc_dist(pos[i], pos[j]);
            max_dist = max(max_dist, dist);
        }
    }
    cout << sqrt((double)max_dist) << endl;

    return 0;
}


