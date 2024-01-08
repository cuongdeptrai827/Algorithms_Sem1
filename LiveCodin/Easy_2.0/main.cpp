#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long int lli;

lli editDistance(const string &s1, const string &s2) {
    lli m = s1.length();
    lli n = s2.length();

    vector<lli> dpPrev(n + 1, 0);

    for (int i = 0; i <= m; ++i) {
        lli prev = dpPrev[0];
        for (int j = 0; j <= n; ++j) {
            lli temp = dpPrev[j];
            dpPrev[j] = (i == 0) ? j : (j == 0) ? i : (s1[i - 1] == s2[j - 1]) ? prev : 1 + min({dpPrev[j], dpPrev[j - 1], prev});
            prev = temp;
        }
    }

    return dpPrev[n];
}

vector<string> getOperations(const string &s1, const string &s2) {
    lli m = s1.length();
    lli n = s2.length();

    vector<string> operations;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = (i == 0) ? j : (j == 0) ? i : (s1[i - 1] == s2[j - 1]) ? dp[i - 1][j - 1] : 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }

    while (m > 0 || n > 0) {
        if (m > 0 && n > 0 && dp[m][n] == dp[m - 1][n - 1] + 1) {
            stringstream ss;
            ss << "change " << s1[m - 1] << " " << s2[n - 1];
            operations.emplace_back(ss.str());
            --m;
            --n;
        } else if (m > 0 && dp[m][n] == 1 + dp[m - 1][n]) {
            operations.emplace_back("delete " + string(1, s1[m - 1]));
            --m;
        } else if (n > 0 && dp[m][n] == 1 + dp[m][n - 1]) {
            operations.emplace_back("add " + string(1, s2[n - 1]));
            --n;
        } else {
            --m;
            --n;
        }
    }

    reverse(operations.begin(), operations.end());

    for (const string &operation : operations) {
        cout << operation << endl;
    }

    return operations;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    // Check if the strings are already equal
    if (s1 == s2) {
        cout << "0\n"; // Output 0 operations
        return 0;
    }

    // Check if either of the strings is empty
    if (s1.empty() || s2.empty()) {
        cout << max(s1.length(), s2.length()) << endl;
        // No need to call getOperations since the strings are either empty or already equal
        return 0;
    }

    lli numOperations = editDistance(s1, s2);

    cout << numOperations << endl;
    getOperations(s1, s2);

    return 0;
}
