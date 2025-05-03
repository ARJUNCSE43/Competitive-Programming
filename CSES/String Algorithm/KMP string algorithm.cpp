#include <bits/stdc++.h>
using namespace std;

// Build LPS (longest prefix suffix) array
vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP matching function
int countOccurrences(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = buildLPS(pattern);

    int i = 0, j = 0, count = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            count++;
            j = lps[j - 1]; // allow overlapping
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    cin >> text >> pattern;

    cout << countOccurrences(text, pattern) << '\n';

    return 0;
}
