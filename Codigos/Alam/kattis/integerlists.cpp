#include <deque>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    int t, n, x;
    string program, raw_list, x_token;
    cin >> t;

    while (t--) {
        cin >> program >> n >> raw_list;

        int lst[n];
        deque<int> num;
        istringstream ss(raw_list.substr(1, raw_list.size() - 2));
        while (getline(ss, x_token, ',')) {
            num.push_back(stoi(x_token));
        }

        bool reversed = false, error = false;
        for (int i = 0; i < program.size() && !error; i++) {
            switch (program[i]) {
                case 'R':
                    reversed = !reversed;
                    break;
                case 'D':
                    if (num.empty()) {
                        error = true;
                    } else {
                        if (reversed)
                            num.pop_back();
                        else
                            num.pop_front();
                    }
                    break;
            }
        }

        if (error) {
            cout << "error" << endl;
        } else {
            cout << "[";
            if (reversed) {
                stack<int> aux;
                for (auto it = num.begin(); it != num.end(); it++)
                    aux.push(*it);

                while (!aux.empty()) {
                    cout << aux.top();
                    aux.pop();
                    if (aux.size() > 0) cout << ",";
                }
            } else {
                for (auto it = num.begin(); it != num.end(); it++) {
                    cout << *it;
                    if (it + 1 != num.end()) cout << ",";
                }
            }

            cout << "]" << endl;
        }
    }
}