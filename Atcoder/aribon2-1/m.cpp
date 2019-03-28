// asdf_m
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define COUT(x) cout << x << endl

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
int visited_count = 0;
int ans = 0;

void dfs(int src){
    visited[src] = true;
    visited_count++;
    for (auto dst: graph[src]) {
        if (visited[dst]) continue;
        dfs(dst);
    }
    if (visited_count == N){
        ans++;
    }
    visited[src] = false;
    visited_count--;
}

int main() {
    cin >> N >> M;

    graph.assign(N, vector<int>{});
    REP(i, M){
        int a, b;
        cin >> a >> b; a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    visited.assign(N, false);
    dfs(0);

    COUT(ans);

    return 0;
}
