#include <iostream>

using namespace std;

bool meetsCondition(const string& s1, const string& s2, int perm[], int k) {
    bool* removed = new bool[s1.size()]();

    for (int i = 0; i < k; ++i) {
        removed[perm[i] - 1] = true;
    }

    int i = 0, j = 0;

    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j] && !removed[i]) {
            j++;
        }
        i++;
    }

    delete[] removed;
    return j == s2.size();
}

int maxLetters(const string& s1, const string& s2, int perm[]) {
    int l = 0, r = s1.size() + 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (meetsCondition(s1, s2, perm, mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return l - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int* perm = new int[s1.size()];

    for (int i = 0; i < s1.size(); ++i) {
        cin >> perm[i];
    }

    int result = maxLetters(s1, s2, perm);
    cout << result << endl;

    delete[] perm;

    return 0;
}
