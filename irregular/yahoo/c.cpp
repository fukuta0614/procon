
#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n,K;
int used[N];

int main(){
  cin>>n>>K;
  for(int i=0,a;i<K;i++)cin>>a,used[a-1]++;

  vector<string> v,v2;
  for(int i=0;i<n;i++) {
    string S;
    cin>>S;
    if(used[i]==1) v.push_back(S);
    else v2.push_back(S);
  }

  string ans=v[0];
  for(int i=0;i<v.size();i++){
    int cnt=0;
    while (cnt<(int)ans.size() && ans[cnt]==v[i][cnt]) cnt++;
    if ((int)ans.size()>cnt) ans=v[i].substr(0,cnt);
    cout << ans << endl;
  }

  int mx=0;
  for(int i=0;i<v2.size();i++){
    int size = 0;
    while(size<ans.size()&&ans[size] == v2[i][size])size++;
    if(size>=(int)ans.size()){cout<<-1<<endl;exit(0);}
    mx = max(size+1,mx);
  }

  cout<<ans.substr(0,mx)<<endl;
  return 0;
}