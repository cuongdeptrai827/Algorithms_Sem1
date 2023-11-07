#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<long long> &arr, long long low, long long high) {
    if (low < high) {
        long long pivot = arr[high];
        long long i = low - 1;
        for (long long j = low; j <= high - 1; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        long long pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(vector<long long> &arr, long long target) {
    long long left = 0, right = arr.size() - 1;
    long long result = -1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result + 1;
}

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> woman(n);
    vector<long long> man(n);

    for (int i = 0; i < n; ++i) {
        cin >> woman[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> man[i];
    }

    quickSort(woman, 0, n - 1);
    quickSort(man, 0, n - 1);

    long long left = 1, right = woman[n - 1] + man[n - 1];
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            long long j = binarySearch(man, mid - woman[i]);
            count += j;
        }

        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
    return 0;
}
