#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;
struct Contestant {
    int year;
    ull strength;
    bool is_karl;

    Contestant() {}
};

bool operator<(const Contestant& a, const Contestant& b) {
    return a.strength < b.strength;
}

int main() {
    int k, n;
    Contestant karl;
    cin >> k >> n >> karl.year >> karl.strength;
    karl.is_karl = 1;

    int lim = k + n - 2;
    vector<Contestant> contestants(lim);
    for (int i = 0; i < lim; i++) {
        cin >> contestants[i].year >> contestants[i].strength;
    }

    contestants.push_back(karl);

    sort(contestants.begin(), contestants.end(),
         [](const Contestant& a, const Contestant& b) {
             return a.year < b.year;
         });

    lim = contestants.size();
    priority_queue<Contestant> strongest;
    for (int i = 0; i < lim; i++) {
        int curr_year = contestants[i].year, offset = 0;

        while (i + offset < lim && contestants[i + offset].year == curr_year) {
            strongest.push(contestants[i + offset]);
            offset++;
        }
        i += offset - 1;

        if (strongest.top().is_karl) {
            cout << curr_year << endl;
            return 0;
        }

        strongest.pop();
    }

    cout << "unknown" << endl;
}