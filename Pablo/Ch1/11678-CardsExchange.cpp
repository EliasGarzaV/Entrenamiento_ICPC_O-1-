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
#define fun(a,b) ((a<b)?a:b)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

int main(){
sync;

int a = 1,b = 1;
cin>>a>>b;
while(a != 0 && b != 0){
    int arr1[a], arr2[b];
    FOR(i,0,a,1)cin>>arr1[i];
    FOR(i,0,b,1)cin>>arr2[i];

    sort(arr1, arr1 + a);
    sort(arr2, arr2 + b);

    vi unionV(a+b);  
    
    vi::iterator it = set_union(arr1, arr1 + a, arr2, arr2 + b, unionV.begin()), st;
    unionV.erase( unique( unionV.begin(), unionV.end() ), unionV.end() );

    vi interV(a+b);  
    
    it = set_intersection(arr1, arr1 + a, arr2, arr2 + b, interV.begin());

    interV.erase( unique( interV.begin(), interV.end() ), interV.end() );

    vi differV(a+b);  

    it = set_difference(unionV.begin(), unionV.end(), interV.begin(), interV.end(), differV.begin());

    differV.erase( unique( differV.begin(), differV.end() ), differV.end() );
    differV.erase(remove(differV.begin(), differV.end(), 0), differV.end());


    vi differ1(a + b);
    set_difference(differV.begin(), differV.end(), arr1, arr1 + a, differ1.begin());

    vi differ2(a + b);
    set_difference(differV.begin(), differV.end(), arr2, arr2 + a, differ2.begin());

    differ1.erase( unique( differ1.begin(), differ1.end() ), differ1.end() );
    differ1.erase(remove(differ1.begin(), differ1.end(), 0), differ1.end());
    
 

    differ2.erase( unique( differ2.begin(), differ2.end() ), differ2.end() );
    differ2.erase(remove(differ2.begin(), differ2.end(), 0), differ2.end());


    cout<<fun(min(differ1.size(), differ2.size()), fun(a,b))<<endl;

cin>>a>>b;
}

return 0;
}