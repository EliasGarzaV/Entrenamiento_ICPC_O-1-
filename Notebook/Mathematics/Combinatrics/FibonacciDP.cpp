
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

// A utility function to multiply two matrices
// a[][] and b[][].  Multiplication result is
// stored back in b[][]
void multiply(int a[3][3], int b[3][3])
{
    // Creating an auxiliary matrix to store elements
    // of the multiplication matrix
    int mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
 
    // storing the multiplication result in a[][]
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j];  // Updating our matrix
}
 
// Function to compute F raise to power n-2.
int power(int F[3][3], int n)
{
    int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
 
    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    if (n==1)
        return F[0][0] + F[0][1];
 
    power(F, n/2);
 
    multiply(F, F);
 
    if (n%2 != 0)
        multiply(F, M);
 
    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    return F[0][0] + F[0][1] ;
}
 
// Return n'th term of a series defined using below
// recurrence relation.
// f(n) is defined as
//    f(n) = f(n-1) + f(n-2) + f(n-3), n>=3
// Base Cases :
//    f(0) = 0, f(1) = 1, f(2) = 1
int findNthTerm(int n)
{
 
    int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
 
    //Base cases
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
 
    return power(F, n-2);
}
