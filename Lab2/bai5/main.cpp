#include <iostream>
using namespace std;

// Hàm merge() thực hiện việc gộp hai mảng con đã sắp xếp thành một mảng con sắp xếp và đếm số lượng cặp không tuân thủ.
long long merge(int a[], int temp[], int l, int m, int r) {
    int i = l, j = m + 1;
    long long inversions = 0; // Biến này lưu trữ số lượng cặp không tuân thủ.

    // Gộp hai dãy con và đếm số lượng cặp không tuân thủ.
    int k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            // Nếu a[i] > a[j], thì tất cả các phần tử từ i đến mid đều sẽ tạo thành cặp không tuân thủ với a[j].
            inversions += m - i + 1;
        }
    }

    // Sao chép các phần tử còn lại của mảng con trái (nếu có).
    while (i <= m) {
        temp[k++] = a[i++];
    }

    // Sao chép các phần tử còn lại của mảng con phải (nếu có).
    while (j <= r) {
        temp[k++] = a[j++];
    }

    // Sao chép các phần tử từ mảng tạm thời trở lại mảng chính a.
    for (int i = l; i <= r; ++i) {
        a[i] = temp[i];
    }

    return inversions; // Trả về số lượng cặp không tuân thủ.
}

// Hàm mergeSort() sắp xếp mảng và đếm số lượng cặp không tuân thủ.
long long mergeSort(int a[], int temp[], int l, int r) {
    if (l >= r) {
        return 0; // Trường hợp cơ sở: mảng chỉ chứa một phần tử hoặc không có phần tử nào.
    }

    int m = l + (r - l) / 2;
    long long inversions = 0;

    // Đệ quy sắp xếp hai nửa của mảng và đếm số lượng cặp không tuân thủ.
    inversions += mergeSort(a, temp, l, m);
    inversions += mergeSort(a, temp, m + 1, r);

    // Gộp hai mảng đã sắp xếp và đếm số lượng cặp không tuân thủ.
    inversions += merge(a, temp, l, m, r);

    return inversions; // Trả về tổng số lượng cặp không tuân thủ của toàn bộ mảng.
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int temp[n]; // Mảng tạm thời để lưu trữ giá trị khi merge các phần tử.

    // Nhập dãy số từ input.
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Gọi hàm mergeSort() để sắp xếp mảng và đếm số lượng cặp không tuân thủ.
    long long inversions = mergeSort(a, temp, 0, n - 1);

    // Xuất số lượng cặp không tuân thủ ra output.
    cout << inversions << endl;

    return 0;
}
