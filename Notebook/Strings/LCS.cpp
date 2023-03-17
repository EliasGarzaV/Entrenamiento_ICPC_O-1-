#include <bits/stdc++.h>
using namespace std;
 
// Function to find the length of the
// longest LCS
//O(n * m)
int LCSubStr(string str1, string str2, int N, int M)
{
    int LCSuff[N + 1][M + 1];
    int mx = 0;    
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
              if (i == 0 || j == 0){
                LCSuff[i][j] = 0;
              }
 
            else if (str1[i - 1] == str2[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                mx = max(mx, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return mx;
}
 
// Driver Code
int main()
{
    string X = "OldSite:GeeksforGeeks.org";
    string Y = "NewSite:GeeksQuiz.com";
 
    int n = X.length();
    int m = Y.length();
 
    cout << LCSubStr(X, Y, n, m);
    return 0;
    cout << "GFG!";
    return 0;
}