#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> index;

    queue<pair<string, char>> gen_q;
    int curr_idx = 1;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        gen_q.push({string(1, ch), ch});
    }

    while (!gen_q.empty()) {
        auto front = gen_q.front();
        gen_q.pop();

        index[front.first] = curr_idx++;
        if (front.first.size() >= 5) continue;
        for (char ch = front.second + 1; ch <= 'z'; ch++) {
            gen_q.push({front.first + ch, ch});
        }
    }

    string s;
    while (cin >> s) {
        cout << index[s] << endl;
    }
}
