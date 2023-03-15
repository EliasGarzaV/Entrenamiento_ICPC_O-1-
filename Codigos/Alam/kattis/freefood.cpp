#include <iostream>

using namespace std;

bool freefood[365];

int main() {
    int n, s, t;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;

        for (int j = s - 1; j < t; j++) {
            count += freefood[j] == 0;
            freefood[j] = 1;
        }
    }

    cout << count << endl;

}