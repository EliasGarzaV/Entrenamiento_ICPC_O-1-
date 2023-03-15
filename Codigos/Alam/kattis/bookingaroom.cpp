#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, r, a;
    cin >> r >> n;

    vector<bool> rooms(r, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        rooms[a - 1] = 1;
    }

    if (r == n) {
        cout << "too late" << endl;
    } else {
        for (int i = 0; i < r; i++) {
            if (!rooms[i]) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}
