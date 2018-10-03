
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
#define INF 1<<30
#define LINF 1ll<<60ll
#define MOD 1000000007
#define pb(a) push_back(a)
#define _overload3(_1,_2,_3,_4,name,...) name
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(int i=a, i##_len=(b); i<i##_len; ++i)
#define _repis(i,a,b,s) for(int i=a, i##_len(b); i<i##_len; i+=s)
#define REP(...) _overload3(__VA_ARGS__,_repis,_repi,_rep,)(__VA_ARGS__)
#define REPR(i, n) for(int i = n;i >= 0;--i)
#define REPARR(i, v) for(int i = 0;i < sz(v);++i)
#define all(vec) (vec.begin()),(vec.end())
#define sz(x) ((int)(x).size())
#define bit(n) (1ll<<(n))
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
#define YES(n) cout<<((n)?"YES":"NO")<<endl
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
#define yes(n) cout<<((n)?"yes":"no")<<endl
#define poss(n) cout<<((n)?"possible":"impossible")<<endl
#define Poss(n) cout<<((n)?"Possible":"Impossible")<<endl
#define POSS(n) cout<<((n)?"POSSIBLE":"IMPOSSIBLE")<<endl


int main() {
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());

    int k;
    cin >> k;
    cout << (k / 2) * (k / 2 + k % 2) << endl;
    return 0;
}

