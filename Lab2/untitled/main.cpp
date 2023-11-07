#include <iostream>
using namespace std;

int xorArray(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    int A, B, C, a1, a2;
    cin >> A >> B >> C >> a1 >> a2;

    int* c = new int[n];
    c[0] = a1;
    c[1] = a2;

    for (int i = 2; i < n; i++) {
        c[i] = c[i - 2] * A + c[i - 1] * B + C;
    }

    // Tìm phần tử có bậc thứ n-k trong mảng c
    int index = n - k - 1;
    int pivot = c[index];

    // Tìm các phần tử lớn hơn phần tử chốt
    int* arr = new int[k];
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (c[i] > pivot) {
            arr[j] = c[i];
            j++;
            if (j == k) {
                break;
            }
        }
    }

    // Tính kết quả XOR của các phần tử trong mảng arr
    int result = xorArray(arr, k);
    cout << result << endl;

    delete[] c;
    delete[] arr;

    return 0;
}
