// CPP program to find the sum in a given
// range in an array using sparse table.

#include <bits/stdc++.h>
using namespace std;

// Because 2^17 is larger than 10^5
const int k = 16;

// Maximum value of array
const int N = 1e5;

// k + 1 because we need to access
// table[r][k]
long long table[N][k + 1];

// it builds sparse table.
void buildSparseTable(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		table[i][0] = arr[i];

	for (int j = 1; j <= k; j++)
		for (int i = 0; i <= n - (1 << j); i++)
			table[i][j] = table[i][j - 1] +
			table[i + (1 << (j - 1))][j - 1];
}

// Returns the sum of the elements in the range
// L and R.
long long query(int L, int R)
{
	// boundaries of next query, 0-indexed
	long long answer = 0;
	for (int j = k; j >= 0; j--) {
		if (L + (1 << j) - 1 <= R) {
			answer = answer + table[L][j];

			// instead of having L', we
			// increment L directly
			L += 1 << j;
		}
	}
	return answer;
}

// Driver program.
int main()
{
	int arr[] = { 3, 7, 2, 5, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	buildSparseTable(arr, n);

	cout << query(0, 5) << endl;
	cout << query(3, 5) << endl;
	cout << query(2, 4) << endl;

	return 0;
}
