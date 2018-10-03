#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
typedef long long ll;
using namespace std;

const int N=1010;
int n;
ll x[N],y[N];
vector<ll>d;

int main(){
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());

    cin >> n;

    rep(i,1,n){
        cin>>x[i]>>y[i];
        if (((abs(x[i])+abs(y[i]))&1) != ((abs(x[1])+abs(y[1]))&1)){ puts("-1"); return 0; }
    }
    for (int i=30; ~i; i--) d.push_back(1ll<<i);
    if (!((abs(x[1])+abs(y[1]))&1)) d.push_back(1);
    cout<<d.size()<<endl;
    for (int i=0; i<(int)d.size(); i++) cout<<d[i]<<" ";
    puts("");
    rep(i,1,n){
        ll X=x[i],Y=y[i];
        string s="";
        for (int j=0; j<(int)d.size(); j++)
            s+=(abs(X)>abs(Y)) ? (X>0?(X-=d[j],"R"):(X+=d[j],"L")) : (Y>0?(Y-=d[j],"U"):(Y+=d[j],"D"));
        cout<<s<<endl;
    }
    return 0;
}
