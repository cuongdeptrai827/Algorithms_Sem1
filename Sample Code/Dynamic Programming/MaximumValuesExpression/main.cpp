#include <iostream>

using namespace std;

int maxValueOfExpression(int a[], int n) {
    // Khởi tạo ma trận d[i][j]
    int d[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                d[i][j] = a[i];
            } else {
                d[i][j] = INT_MIN;
            }
        }
    }

    // Tính toán d[i][j]
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++) {
                d[i][j] = max(d[i][j], max(d[i][k] + d[k + 1][j], d[i][k] * d[k + 1][j]));
            }
        }
    }

    // Trả về kết quả
    return d[0][n - 1];
}

int main() {
    // Input the array size
    int n;
    cin >> n;

    // Read the array elements
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Call the function
    int result = maxValueOfExpression(a, n);

    // Print the result
    cout << result << endl;

    return 0;
}