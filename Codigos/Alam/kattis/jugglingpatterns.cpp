#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    string p;

    while (cin >> p) {
        n = p.size();
        int pattern[n], sum = 0;
        for (int i = 0; i < n; i++) {
            pattern[i] = p[i] - '0';
            sum += pattern[i];
        }

        if (sum % n != 0) {
            cout << p << ": invalid # of balls" << endl;
            continue;
        }

        priority_queue<int, vector<int>, greater<int>> throws_pq;
        for (int i = 0; i < n; i++) {
            throws_pq.push((i + pattern[i]) % n);
        }

        bool pos = 1;
        while (!throws_pq.empty() && pos) {
            auto top = throws_pq.top();
            throws_pq.pop();
            if (!throws_pq.empty() && top == throws_pq.top()) {
                pos = 0;
            }
        }

        if (pos) {
            cout << p << ": valid with " << sum / n << " balls" << endl;
        } else {
            cout << p << ": invalid pattern" << endl;
        }
    }
}