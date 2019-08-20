// aribon3-2-8_c
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

int split_cards(vector<P>& cards, int split_sm){
    int sz = cards.size();
    int sm = 0;
    REP(i, sz){
        int cnt = cards[i].second - cards[i].first + 1;

        if (split_sm == sm + cnt){
            return i;
        }
        if (split_sm < sm + cnt){
            P tmp = cards[i];
            cards.erase(cards.begin() + i);
            cards.insert(cards.begin() + i, P(tmp.first, tmp.first + split_sm - sm - 1));
            cards.insert(cards.begin() + i+1, P(tmp.first + split_sm - sm, tmp.second));
            return i;
        }
        sm += cnt;
    }
    return -1;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    int p, q, r;
    cin >> p >> q >> r;

    vector<P> cards;
    cards.emplace_back(1, N);
    REP(m, M){
        int x, y;
        cin >> x >> y;
        int idx1 = split_cards(cards, x);
        int idx2 = split_cards(cards, y);

        vector<P> tmp;
        tmp.insert(tmp.end(), cards.begin() + idx2+1, cards.end());
        tmp.insert(tmp.end(), cards.begin() + idx1+1, cards.begin() + idx2+1);
        tmp.insert(tmp.end(), cards.begin(), cards.begin() + idx1+1);
        swap(tmp, cards);
    }

    int ans = 0;
    int idx1 = split_cards(cards, p-1);
    int idx2 = split_cards(cards, q);

    REPN(i, idx1+1, idx2+1){
        if (cards[i].first <= r){
            ans += min(r, cards[i].second) - cards[i].first + 1;
        }
    }

    print(ans);

    return 0;
}
