

#include "../template.cpp"

void buildPi(string& p, vi& pi) {
    pi = vi(p.length());
    int k = -2;
    for (int i = 0; i < p.length(); i++) {
        while (k >= -1 && p[k + 1] != p[i]) k = (k == -1) ? -2 : pi[k];
        pi[i] = ++k;
    }
}

/** Finds all occurrences of the pattern string p within the
 * text string t.
 * Running time is O(n + m), where n and m are the lengths
 * of p and t, respectively.
 */
int KMP(string& t, string& p) {
    vi pi;
    buildPi(p, pi);
    int k = -1;
    for (int i = 0; i < t.length(); i++) {
        while (k >= -1 && p[k + 1] != t[i]) k = (k == -1) ? -2 : pi[k];
        k++;
        if (k == p.length() - 1) {
            // p matches t[i-m+1, ..., i]
            cout << "matched at index " << i - k << ": ";
            cout << t.substr(i - k, p.length()) << endl;
            k = (k == -1) ? -2 : pi[k];
        }
    }
    return 0;
}