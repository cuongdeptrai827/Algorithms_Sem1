#include <iostream>
#include <stack>
#include <map>
#include <vector>
using namespace std;

string expand_formula(string formula) {
    stack<int> counts;
    map<char, int> element_counts;
    vector<int> element_order(128, 0);

    for (char c : formula) {
        if (isdigit(c)) {
            counts.top() *= (c - '0');
        } else if (isalpha(c)) {
            element_counts[c] += (counts.empty() ? 1 : counts.top());
            counts.top() = 1;
        } else if (c == '(') {
            counts.push(1);
        } else if (c == ')') {
            int count = counts.top();
            counts.pop();
            for (auto it = element_counts.begin(); it != element_counts.end(); ++it) {
                element_order[it->first] += (count * it->second);
                it->second = 0;
            }
            if (!counts.empty()) {
                counts.top() = 1;
            }
        }
    }

    string expanded_formula;
    for (int i = 0; i < 128; ++i) {
        if (element_order[i] > 0) {
            expanded_formula += char(i) + to_string(element_order[i]);
        }
    }

    return expanded_formula;
}

int main() {
    string formula;
    cout << "Nhập công thức hóa học: ";
    cin >> formula;

    string expanded_formula = expand_formula(formula);
    cout << "Công thức đã mở rộng: " << expanded_formula << endl;

    return 0;
}
