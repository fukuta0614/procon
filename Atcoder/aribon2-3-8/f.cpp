#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

struct ModComb{
    vector<ll> po, inv;
    ll N;

    ModComb(ll n) : N(n), po(n), inv(n) {
        po[0] = 1;
        for(int i = 1; i < N; i++)  po[i] = (po[i-1] * i) % mod;
        inv[N-1] = modpow(po[N-1], mod-2, mod);
        for(int i = N-2; i >= 0; i--)   inv[i] = (inv[i+1] * (i+1)) % mod;
    }

    ll nCk(ll n, ll k){
        if(k == 0)  return 1;
        if(n < k)   return 0;
        return (((po[n]*inv[n-k])%mod)*inv[k])%mod;
    }

    ll nPk(ll n, ll k){
        if(k == 0)  return 1;
        if(n < k)   return 0;
        return (po[n]*inv[n-k])%mod;
    }

    ll nHk(ll n, ll k){
        if(n == 0 && k == 0)    return 1;
        return nCk(n+k-1, k-1);
    }
};

#include <bits/stdc++.h>
#include "../cxx-prettyprint/prettyprint.hpp"
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

int main(){
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    ll n, m;
    cin >> n >> m;
    ModComb mc(2*m+1);
    bool minus = n < 0;
    n = abs(n);
    ll ans = 1;
    for(int i = 2; i*i <= n; i++){
        int cnt = 0;
        while(n%i == 0) n /= i, cnt++;
        if(cnt) ans = ans * mc.nHk(cnt, m) % mod;
    }
    print(ans);

    if(n != 1)  ans = ans * mc.nHk(1, m) % mod;
    ll mul = 0;
    int x = minus ? 1 : 0;
    while(x <= m){
        mul += mc.nCk(m, x);
        mul %= mod;
        x += 2;
    }
    print(mul);

    cout << ans*mul%mod << endl;
    return 0;
}
500500000
344211605