#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> chain[n];
    string s[n];
    
    int non_empty = 0, a, b;

    for (int i = 0; i < n; i++) 
        cin >> s[i];
    
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        
        a--;
        b--;
        non_empty = a;
        chain[a].push_back(b);
        chain[a].splice(chain[a].end(), chain[b]);
    }

    cout << s[non_empty];
    for (auto &item : chain[non_empty]) {
        cout << s[item]; 
    }
    cout << endl;
}