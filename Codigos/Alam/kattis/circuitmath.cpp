#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    char in_raw;
    bool in[n];

    for (int i = 0; i < n; i++) {
        cin >> in_raw;
        in[i] = in_raw == 'T' ? 1 : 0;
    }

    string circuit, item;
    cin.ignore();
    getline(cin, circuit);

    bool left, right;
    istringstream ss(circuit);
    stack<bool> operands;

    while (ss >> item) {
        // cout << "ITEM: " << item << endl;
        if (item <= "Z" && item >= "A") {
            operands.push(in[item[0] - 'A']);
            continue;
        }

        if (item == "-") {
            right = operands.top();
            operands.pop();
            operands.push(!right);
            continue;
        }

        right = operands.top();
        operands.pop();
        left = operands.top();
        operands.pop();

        if (item == "*") {
            operands.push(right && left);
        } else if (item == "+") {
            operands.push(right || left);
        }
    }

    cout << (operands.top() ? "T" : "F") << endl;
}