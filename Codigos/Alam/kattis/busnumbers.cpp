#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a;
    cin >> n;

    vector<bool> bus(1002, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        bus[a] = 1;
    }

    int contiguous = 0;
    for (int i = 0; i <= 1001; i++) {
        if (!bus[i]) {
            if (contiguous > 2)
                cout << "-" << i - 1 << " ";
            else if (contiguous > 1)
                cout << " " << i - 1 << " ";
            else if (contiguous > 0)
                cout << " ";

            contiguous = 0;
            continue;
        }

        if (contiguous == 0) cout << i;
        contiguous++;
    }
}
