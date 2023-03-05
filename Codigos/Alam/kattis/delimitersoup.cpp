#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    string code;
    cin >> n;
    cin.ignore();
    getline(cin, code);

    stack<char> openings;
    bool pos = true;
    for (int i = 0; i < n && pos; i++) {
        switch (code[i]) {
            case '(':
            case '{':
            case '[':
                openings.push(code[i]);
                break;
            case ' ':
                break;
            default: {

                if (openings.empty()) {
                    cout << code[i] << " " << i << endl;
                    pos = false;
                    break;
                }
                char cmp = code[i] == ')' ? '(' : (code[i] == ']' ? '[' : '{');
                if (openings.top() == cmp) {
                    openings.pop();
                } else {
                    cout << code[i] << " " << i << endl;
                    pos = false;
                }
                break;
            }
        }
    }

    if (pos) cout << "ok so far" << endl;
}