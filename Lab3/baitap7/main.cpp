#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Chia mảng thành hai phần và lấy chỉ số chốt
        int pivot = arr[low];
        int l = low + 1;
        int r = high;

        // Di chuyển các phần tử nhỏ hơn pivot vào bên trái và các phần tử lớn hơn pivot vào bên phải
        while (l <= r) {
            if (arr[l] > pivot && arr[r] < pivot) {
                // Hoán đổi arr[left] và arr[right]
                int temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
            }
            if (arr[l] <= pivot) {
                l++;
            }
            if (arr[r] >= pivot) {
                r--;
            }
        }

        // Hoán đổi pivot vào đúng vị trí
        int temp = arr[low];
        arr[low] = arr[r];
        arr[r] = temp;

        // Sắp xếp các phần tử ở bên trái và bên phải của pivot
        quickSort(arr, low, r - 1);
        quickSort(arr, r + 1, high);
    }
}

bool canPlace(int distance, int K, int seats[], int N) {
    int count = 1;
    int lastSeat = seats[0];
    for (int i = 1; i < N; ++i) {
        if (seats[i] - lastSeat >= distance) {
            count++;
            lastSeat = seats[i];
        }
    }
    return count >= K;
}

int binarySearch(int left, int right, int K, int seats[], int N) {
    int result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlace(mid, K, seats, N)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    int seats[n];
    for (int i = 0; i < n; ++i) {
        cin >> seats[i];
    }

    // Sắp xếp mảng sử dụng Quick Sort
    quickSort(seats, 0, n - 1);

    int left = 1;
    int right = seats[n - 1] - seats[0];
    int result = binarySearch(left, right, k, seats, n);

    cout << result << std::endl;

    return 0;
}
