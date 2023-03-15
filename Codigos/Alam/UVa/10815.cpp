#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    string s;
    set<string> dict;
    while (cin >> s) {
        transform(s.begin(), s.end(), s.begin(), [](const char& c) {
            return c >= 'A' && c <= 'Z' ? tolower(c) : c;
        });

        replace_if(
            s.begin(), s.end(),
            [](const char& c) {
                return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
            },
            '|');

        size_t pos = 0;

        while ((pos = s.find("|")) != std::string::npos) {
            dict.insert(s.substr(0, pos));
            s.erase(0, pos + 1);
        }

        dict.insert(s);
    }

    dict.erase("");

    for (auto& word : dict) {
        cout << word << endl;
    }
}