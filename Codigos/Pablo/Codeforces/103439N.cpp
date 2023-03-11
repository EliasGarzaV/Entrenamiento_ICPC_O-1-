#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u) 
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

struct nodo{
    double a = 0, b = 0, c = 0, op = 0;

};

bool fun(nodo uno, nodo dos){
    if(uno. )
    return uno.a + uno.b < dos.a + dos.b;
    //float distUno = hypot(uno.a, uno.b);

    //float distDos = hypot(dos.a, dos.b);

    //return distUno > distDos; 

    //return uno.c < dos.c;

    //return uno.op < dos.op;
    //return max(uno.a, uno.b) > max(dos.a, dos.b);
}

long long calc(nodo a, nodo b){
    //cout<<a.op <<" , "<<b.op<<" , "<<abs(a.c - b.c)<<endl;
 
    long long uno = abs(a.a - b.a);
    long long dos = abs(a.a - b.b);
    long long tres = abs(a.b - b.a);
    long long cuatro = abs(a.b - b.b);
 
    return max(uno, max(dos, max(tres, cuatro)));
    //return (abs(a.c - b.c) + a.op + b.op);
}

int main(){
sync;

long long n; cin>>n;

vector<nodo> v;

FOR(i,0,2*n,1){
    float a, b; cin>>a>>b;
    nodo aux; 
    aux.a = a; 
    aux.b = b; 
    aux.c = (a + b) / 2;
    aux.op = abs(a - b) / 2;

    v.pb(aux);

}



//sort(v.begin(), v.end(), fun);

long long res = 0; 
/*
FOR(i,0,2 * n, 1){
    FOR(j,0,2*n,1){
        if(i != j){
            nodo grande = v[i];
            nodo chico = v[j];
            cout<<i <<" ... "<<j<<" = "<<calc(chico, grande)<<endl;        
        }
    }
}
*/

FOR(i,0,n,1){

    //v[i] con v[2*n - i - 1]
    //res += max(abs(v[i].a - v[2*n - i - 1].a), max(abs(v[i].a - v[2*n - i - 1].b),max(abs(v[i].b - v[2*n - i - 1].a), abs(v[i].b - v[2*n - i - 1].b))));

    nodo grande = v[2 * n - i - 1];
    nodo chico = v[i];

    res += calc(chico, grande);

    //cout<<i <<" ... "<<2*n - i - 1<<" = "<<calc(chico, grande)<<endl;

}


cout<<res<<endl;
return 0;
}

/*
3
1 2
3 4
5 6
7 8
9 10
11 12
*/