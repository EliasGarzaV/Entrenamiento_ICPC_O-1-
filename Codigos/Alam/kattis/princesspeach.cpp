#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, a;
    cin >> n >> k;

    vector<bool> found(n, 0);
    for (int i = 0; i < k; i++) {
        cin >> a;
        found[a] = 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!found[i])
            cout << i << endl;
        else
            count++;
    }

    cout << "Mario got " << count << " of the dangerous obstacles." << endl;
}