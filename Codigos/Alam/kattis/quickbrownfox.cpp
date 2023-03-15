#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;

    cin.ignore();
    while (n--) {
        getline(cin, s);
        bitset<26> chars;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
            if (s[i] >= 'a' && s[i] <= 'z') {
                chars.set(s[i] - 'a');
            }
        }

        if (chars.count() == 26) {
            cout << "pangram" << endl;
            continue;
        }

        cout << "missing ";
        for (int i = 0; i < 26; i++) {
            if (!chars[i]) {
                cout << char('a' + i);
            }
        }
        cout << endl;
    }
}