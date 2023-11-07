#include <iostream>
#include <vector>
using namespace std;

// Hàm lấy chữ cái thứ i từ một chuỗi
char getchar(const string& str, int index) {
    if (index >= 0 && index < str.length()) {
        return str[index];
    }
    return '\0';
}

// Hàm sắp xếp các tin nhắn theo kí tự ở vị trí cần xét
void radixSort(vector<string>& mes, int pos) {
    const int numChars = 256;
    vector<int> count(numChars, 0);


    for (const string& message : mes) {
        char ch = getchar(message, pos);
        count[ch]++;
    }

    vector<int> startIndex(numChars, 0);
    int sum = 0;
    for (int i = 0; i < numChars; i++) {
        startIndex[i] = sum;
        sum += count[i];
    }

    vector<string> sortedMes(mes.size());

    for (const string& message : mes) {
        char ch = getchar(message, pos);
        int index = startIndex[ch];
        sortedMes[index] = message;
        startIndex[ch]++;
    }

    // Sao chép các tin nhắn từ mảng tạm và gán lại vào mảng ban đầu
    mes = sortedMes;
}

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    vector<string> mes(n);

    for (int i = 0; i < n; i++) {
        cin >> mes[i];
    }
    for (int i = k - 1; i >= k - t; i--) {
        radixSort(mes, i);
    }
    for (const string& message : mes) {
        cout << message << "\n";
    }
    return 0;
}