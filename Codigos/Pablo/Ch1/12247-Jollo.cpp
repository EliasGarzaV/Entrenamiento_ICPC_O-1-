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


int main(){
sync;

int accum = 1;

while(1){
    char cards[52];
    FOR(i,0,52,1){
        cards[i] = 'E';
    }

    accum = 0;

    //princess
    int lec; 
    cin>>lec;
    if(lec == 0) return 0;
    accum += lec;
    cards[lec - 1] = 'P';
    cin>>lec;
    accum += lec;
    cards[lec - 1] = 'P';
    cin>>lec;
    accum += lec;
    cards[lec - 1] = 'P';

    //bob
    cin>>lec;
    accum += lec;
    cards[lec - 1] = 'B';
    cin>>lec;
    accum += lec;
    cards[lec - 1] = 'B';

    if(accum == 0) return 0;

    int res = -1;
    bool foundP = false;
    bool found2P = false;
    bool foundB = false;

    FOR(i,0,52,1){

        if(foundP && cards[i] == 'P'){
            found2P = true;
        }

        if(cards[i] == 'P'){
            foundP = true;
        }

        if(cards[i] == 'B'){
            foundB = true;
        }

        if(foundB && !foundP){
            //caso especial donde debe haber 3 Ps y luego 2 Bs del lado izquierdo
            bool rofFoundP = false, rofFoundB = false, rofFound2P = false, rofFound3P = false;
            ROF(j,0,52,1){

                if(cards[j] == 'P' && rofFoundB){
                    cout<<j<<endl;
                    goto here;
                }
                if(cards[j] == 'B') rofFoundB = 1;
                if(cards[j] == 'P' && !rofFoundB){ // check break
                    cout<<-1<<endl;
                    goto here;
                }
               

            }
            cout<<-1<<endl;
            goto here;
        }

        if(found2P && cards[i] == 'E'){
            cout<<i + 1<<endl;
            goto here;
        }

    }

    cout<<res<<endl;
    here:;
}
return 0;
}