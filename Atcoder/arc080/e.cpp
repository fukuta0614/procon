#include "bits/stdc++.h"
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif

using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }
#define each(it,o) for(auto it = (o).begin(); it != (o).end(); ++ it)

int bipartiteMatching(const vector<vector<int> > &g) {
    int nleft = g.size(), nright = 0;
    each(es, g) if (!es->empty()) nright = max(nright, *max_element(es->begin(), es->end()) + 1);
    vi matchL(nleft, -1), matchR(nright, -1), prev(nleft), seen(nleft, -1);
    rep(i, nleft) {
        vi stk; stk.push_back(i);
        seen[i] = i; prev[i] = -1;
        while (!stk.empty()) {
            int v = stk.back(); stk.pop_back();
            each(ui, g[v]) {
                int u = *ui;
                int j = matchR[u];
                if (j == -1) {
                    while (v != -1) {
                        matchR[u] = v;
                        swap(u, matchL[v]);
                        v = prev[v];
                    }
                    goto break_;
                } else if (seen[j] < i) {
                    seen[j] = i; prev[j] = v;
                    stk.push_back(j);
                }
            }
        }
        break_:;
    }
    return (int)matchL.size() - count(matchL.begin(), matchL.end(), -1);
}

vector<bool> isprime;
vector<int> primes;
void sieve(int n) {
    if ((int)isprime.size() >= n + 1) return;
    isprime.assign(n + 1, true);
    isprime[0] = isprime[1] = false;
    int sqrtn = (int)(sqrt(n * 1.) + .5);
    for (int i = 2; i <= sqrtn; i ++) if (isprime[i]) {
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    primes.clear();
    for (int i = 2; i <= n; i ++) if (isprime[i])
            primes.push_back(i);
}

template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    sieve(10000002);
    int N;
    cin >> N;
    vector<int> xs(N);
    for (int i = 0; i < N; ++ i) cin >> xs[i];

    vector<int> diffs;
    rep(i, N) {
        if (i == 0 || xs[i - 1] != xs[i] - 1)
            diffs.push_back(xs[i]);
        if (i == N - 1 || xs[i + 1] != xs[i] + 1)
            diffs.push_back(xs[i] + 1);
    }
    vector<int> vertices[2];
    for (int x : diffs) vertices[x % 2].push_back(x);

    print(diffs);

    vector<vi> g(vertices[0].size());
    rep(i, vertices[0].size()) rep(j, vertices[1].size()) {
            int x = vertices[0][i], y = vertices[1][j];
            if (isprime[abs(x - y)]) {
                g[i].push_back(j);
                print(x, y);
            }
        }


    int match = bipartiteMatching(g);
    int ans = match;
    int rems = 0;

    rep(k, 2) {
        int rem = (int)vertices[k].size() - match;
        ans += rem / 2 * 2;
        rems += rem % 2;
    }
    print(match);
    ans += rems / 2 * 3;
    printf("%d\n", ans);
    return 0;
}
