#include <iomanip>
#include <iostream>

using namespace std;

typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s;

    cin >> s;
    int counts[5] = {0, 0, 0, 0};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '_')
            counts[0]++;
        else if (s[i] >= 'a' && s[i] <= 'z')
            counts[1]++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            counts[2]++;
        else
            counts[3]++;
    }

    cout << fixed << setprecision(15);
    for (int i = 0; i < 4; i++) cout << ld(counts[i]) / ld(s.size()) << endl;
}