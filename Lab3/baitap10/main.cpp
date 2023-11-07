#include <iostream>
#include <vector>

using namespace std;

// Đặt count_copy1 và count_copy2 ở đây để chúng trở thành biến toàn cục
vector<int> countcopy1;
vector<int> countcopy2;
const int MAX_DAMAGE = 100000;
void countingSort(vector<pair<int, string>>& card, int n) {

    vector<int> count(MAX_DAMAGE + 1, 0);

    for (int i = 0; i < n; ++i) {
        count[card[i].first]++;
    }

    countcopy1 = count;

    for (int i = 1; i <= MAX_DAMAGE; ++i) {
        count[i] += count[i - 1];
    }

    countcopy2 = count;

    vector<pair<int, string>> output(n);
    for (int i = n - 1; i >= 0; --i) {
        int index = count[card[i].first] - 1;
        output[index] = card[i];
        count[card[i].first]--;
    }

    for (int i = 0; i < n; ++i) {
        card[i] = output[i];
    }
}

int main() {
    // Nhập và sắp xếp dữ liệu
    int n;
    cin >> n;
    vector<int> damages(n);
    vector<string> names(n);

    for (int i = 0; i < n; ++i) {
        cin >> damages[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    vector<pair<int, string>> card(n);
    for (int i = 0; i < n; ++i) {
        card[i] = make_pair(damages[i], names[i]);
    }
    countingSort(card, n);

    // Xuất danh sách sắp xếp
    for (int i = 0; i < n; ++i) {
        cout << card[i].first;
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << card[i].second;
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    // Xử lý truy vấn
    int q;
    cin >> q;

    long long prefixSum[MAX_DAMAGE + 1] = {};
    long long prefixXor[MAX_DAMAGE + 1] = {};
    int result_xor = 0;

    for (long long i = 1; i <= MAX_DAMAGE; i++) {
        prefixSum[i] = prefixSum[i - 1] + countcopy1[i] * i;
        prefixXor[i] = prefixXor[i - 1] ^ ((countcopy1[i] & 1) ? i : 0);
    }

    for (long long i = 0; i < q; i++) {
        string command;
        long long l, r;
        cin >> command >> l >> r;

        if (r > MAX_DAMAGE ) r = MAX_DAMAGE;
        if (l < 1) l = 1;

        if (command == "Count") {
            cout << countcopy2[r] - countcopy2[l - 1] << '\n';
        }

        if (command == "Sum") {
            cout << prefixSum[r] - prefixSum[l - 1] << '\n';
        }

        if (command == "Xor") {
            result_xor = prefixXor[r] ^ prefixXor[l - 1];
            cout << result_xor << '\n';
        }
    }

    return 0;
}
