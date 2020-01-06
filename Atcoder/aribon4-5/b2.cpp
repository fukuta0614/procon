// aribon4-5_b
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

//-------------------------------------------------------

string S;
int ptr,L;


pair<int,int> hoge() {
    if(ptr>=L) return {0,99};
    int x=ptr;
    if(S[x]=='0') {
        ptr++;
        return {0,0};
    }
    else if(S[x]>='1' && S[x]<='9') {
        ptr++;
        if(x==L-1) {
            return {S[x]-'0',(S[x]-'0')*10+9};
        }

        if(S[ptr]>='0' && S[ptr]<='9') {
            ptr++;
            return {(S[x]-'0')*10+(S[x+1]-'0'),(S[x]-'0')*10+(S[x+1]-'0')};
        }
        else {
            return {S[x]-'0',S[x]-'0'};
        }
    }
    else if(S[x]=='^' || S[x]=='_') {
        ptr++;
        ptr++;
        if(ptr>=L) return {0,99};
        auto lh=hoge(),rh=lh;
        ptr++;
        if(ptr>=L) rh={0,99};
        else rh=hoge();

        ptr++;
        if(S[x]=='^') return {max(lh.first,rh.first),max(lh.second,rh.second)};
        else return {min(lh.first,rh.first),min(lh.second,rh.second)};
    }

}


int main(int argc,char** argv){
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int Q;
    cin >> Q;
    REP(_, Q) {
        cin >> S;
        REPN(i, 1, S.size() + 1) {
            ptr = 0;
            L = i;
            auto ret = hoge();
            if (ret.first == ret.second) {
                cout << ret.first << " " << i << endl;
                break;
            }
        }
    }

    return 0;
}
