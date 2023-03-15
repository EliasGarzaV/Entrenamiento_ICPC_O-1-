#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    string line, name, word;
    cin.ignore();

    unordered_set<string> all_words;
    unordered_map<string, unordered_set<string>> words_by_user;
    unordered_map<string, int> word_counts;
    for (int i = 0; i < n; i++) {
        getline(cin, line);

        stringstream ss(line);
        ss >> name;

        while (ss >> word) {
            words_by_user[name].insert(word);
            all_words.insert(word);
            word_counts[word]++;
        }
    }

    for (auto& [name, user_words] : words_by_user) {
        for (auto it = all_words.begin();
             !all_words.empty() && it != all_words.end();) {
            if (user_words.find(*it) == user_words.end()) {
                it = all_words.erase(it);
                continue;
            }

            it++;
        }
    }

    if (all_words.empty()) {
        cout << "ALL CLEAR" << endl;
        return 0;
    }

    typedef pair<string, int> psi;
    vector<psi> ordered_words;

    for (auto& word : all_words)
        ordered_words.push_back({word, word_counts[word]});

    sort(ordered_words.begin(), ordered_words.end(),
         [](const psi& a, const psi& b) {
             if (a.second == b.second) return a.first < b.first;
             return a.second > b.second;
         });

    for (auto& [word, _] : ordered_words) {
        cout << word << endl;
    }
}