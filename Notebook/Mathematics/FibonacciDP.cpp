
#define ull unsigned long long
#define mod 1000000007
using namespace std;

const int MAX = 1000001;
ull f[MAX] = {0};
ull fib(ull n){
   if (n == 0)
       return 0;
   if (n == 1 || n == 2)
       return (f[n] = 1);
   if (f[n])
       return f[n];
   ull k = (n & 1)? (n+1)/2 : n/2;
   f[n] = (n & 1)? (fib(k)%mod*fib(k)%mod + fib(k-1)%mod*fib(k-1)%mod)%mod : (2*fib(k-1)%mod + fib(k)%mod)%mod*fib(k)%mod;
   return f[n]%mod;
}
