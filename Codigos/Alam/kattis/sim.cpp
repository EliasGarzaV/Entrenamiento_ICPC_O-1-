#include <iostream>
#include <list>

using namespace std;

int main() {
    int t;
    string in;

    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, in);
        list<char> buffer;
        auto cursor = buffer.end();

        for (auto& key : in) {
            switch (key) {
                case '<':
                    if (cursor != buffer.begin()) {
                        cursor--;
                        cursor = buffer.erase(cursor);
                    }
                    break;
                case '[':
                    cursor = buffer.begin();
                    break;
                case ']':
                    cursor = buffer.end();
                    break;
                default:
                    buffer.insert(cursor, key);
                    break;
            }
        }

        for (auto& ch : buffer) cout << ch;
        cout << endl;
    }
}
