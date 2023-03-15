#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string s;

    unordered_map<string, int> votes;
    int max_votes = 0;
    string max_votes_id;
    bool is_tie = 0;
    while (getline(cin, s)) {
        if (s == "***") break;
        votes[s]++;
        if (votes[s] == max_votes) {
            is_tie = 1;
        } else if (votes[s] > max_votes) {
            max_votes = votes[s];
            max_votes_id = s;
            is_tie = 0;
        }
    }

    if (is_tie)
        cout << "Runoff!" << endl;
    else
        cout << max_votes_id << endl;
}