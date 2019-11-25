// abc144_f
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


struct Graph {

    int n;

    vector<vector<int>> edges;
    vector<double> exp;
    vector<P> candidate;

    Graph(int n): n(n), edges(n){}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
    }

    double calc(){

        exp.assign(n, INF);
        exp[n-1] = 0;


        REP_REV(v, n-1){
            exp[v] = 0;
            int tmp = -1;
            double mx = 0;
            for (auto e: edges[v]){
                exp[v] += exp[e];
                if (exp[e] > mx){
                    tmp = e;
                    mx = exp[e];
                }
            }
            candidate.emplace_back(v, tmp);
            exp[v] /= edges[v].size();
            exp[v] += 1;
        }
        return exp[0];
    }

    double calc2(){

        double ans = INF;
        for (auto p: candidate){
            int u = p.first;
            int t = p.second;

            REP_REV(v, n-1){
                exp[v] = 0;
                int num = 0;
                for (auto e: edges[v]){
                    if (v == u && e == t) continue;
                    exp[v] += exp[e];
                    num++;
                }
                exp[v] /= num;
                exp[v] += 1;
            }
            ans = min(ans, exp[0]);
        }

        return ans;
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;

    Graph g(N);
    REP(i, M){
        int s,t;
        cin >> s >> t; s--; t--;
        g.add_edge(s, t);
    }

    bool flag = false;
    REP(i, N){
        if (g.edges[i].size() > 1){
            flag = true;
            break;
        }
    }
    double tmp = g.calc();

    if (not flag) {
        print(tmp);
        return 0;
    }

    double ans = g.calc2();
    print(ans);



    return 0;
}
