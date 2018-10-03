//
// Created by Fukuta Keisuke on 1/13/17.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i, n) for(int i = 0 ; i < n ; i++)

int p[100010];
int c[100010];

int root(int x) {
    return p[x] == x ? x : p[x] = root(p[x]);
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    c[x] += c[y];
    p[y] = p[x];
}

signed main() {
    rep(i, 100010) p[i] = i, c[i] = 1;

    int N, M;
    cin >> N >> M;
    vector <array<int, 5>> q;
    for (int i = 0; i < M; i++) {
        int a, b, y;
        cin >> a >> b >> y;
        --a, --b, y--;
        q.push_back({-y, 0, a, b, -1});
    }
    int Q;
    cin >> Q;
    rep(i, Q) {
        int v, w;
        cin >> v >> w;
        --v;
        q.push_back({-w, 1, v, v, i});
    }
    vector<int> res(Q);
    sort(q.begin(), q.end());
    for (auto i : q) {
        if (i[1] == 0) {
            unite(i[2], i[3]);
        } else {
            res[i[4]] = c[root(i[2])];
            //cout << c[root(i[2])] << endl;
        }
    }
    rep(i, Q) cout << res[i] << endl;
}