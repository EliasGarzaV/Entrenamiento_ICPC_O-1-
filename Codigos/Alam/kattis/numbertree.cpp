#include <cmath>
#include <iostream>

using namespace std;

typedef long long ull;

int main() {
    int n, m;
    string path;
    cin >> n;
    getline(cin, path);

    path = path.substr(1, path.size() - 1);

    m = path.size();
    ull index = 1;
    for (auto &s : path) {
        index <<= 1;
        if (s == 'R') index++;
    }

    index = (1 << (n + 1)) - index;

    cout << index << endl;
}