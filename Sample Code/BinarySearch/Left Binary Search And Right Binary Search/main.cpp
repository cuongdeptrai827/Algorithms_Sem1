#include <iostream>

int leftBinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid; // Ghi nhận vị trí của phần tử tìm thấy
            right = mid - 1; // Tiếp tục tìm ở bên trái (để tìm vị trí đầu tiên)
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}
int rightBinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid; // Ghi nhận vị trí của phần tử tìm thấy
            left = mid + 1; // Tiếp tục tìm ở bên phải (để tìm vị trí cuối cùng)
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}
int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    int leftmostIndex = leftBinarySearch(arr, size, target);
    std::cout << "Leftmost occurrence index: " << leftmostIndex << std::endl;
    int rightmostIndex = rightBinarySearch(arr, size, target);
    std::cout << "Rightmost occurrence index: " << rightmostIndex << std::endl;
    return 0;
}