#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, a;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        unordered_set<int> jacks;
        for (int i = 0; i < n; i++) {
            cin >> a;
            jacks.insert(a);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            cin >> a;
            if (jacks.find(a) != jacks.end()) count++;
        }

        cout << count << endl;
    }
}
