// abc157_a
#include <bits/stdc++.h>
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

int func(){

    //    call    rand
    //    mov     ecx, eax
    //    mov     eax, 66666667h
    //    imul    ecx
    //    mov     eax, ecx
    //    sar     eax, 1Fh
    //    mov     edi, edx
    //    mov     edx, [esp+1Ch]
    //    sar     edi, 2
    //    sub     edi, eax
    //    lea     edi, [edi+edi*4]
    //    mov     eax, ds:_ZZ4mainE1C[edx*4] ; main::C
    //    add     edi, edi
    //    sub     ecx, edi
    //    test    eax, eax
    //    jg      short loc_8048340
    //
    //    add     edx, 1
    //    xor     ebx, ebx
    //    mov     [esp+1Ch], edx
    //    mov     edi, eax
    //    mov     [esp+18h], ecx

    int eax, ebx, ecx, edx, edi;
    eax = rand();
    ecx = eax;
    eax = 0x66666667;
    ll x = (ll)eax * (ll)ecx;
    edx = (int)(x >> 32);
    eax = ecx;
    eax = eax >> 0x1F;
    edi = edx;

    edi = edi >> 2;

    edi = edi - eax;

    edi = 5 * edi;
    edi = edi + edi;
    ecx = ecx - edi;

    edx = edx + 1;
    ebx = 0;

    return ecx;
}

int main(int argc, char *argv[]) {

    int offset = atoi(argv[1]);
    srand(time(NULL) + offset);

    REP(i, 20){
        int ans = func();
        print(ans);
    }

    return 0;
}
