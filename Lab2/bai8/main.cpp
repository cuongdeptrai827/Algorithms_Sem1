#include <iostream>
using namespace std;
void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        quicksort(arr, left, j);
        quicksort(arr, i, right);
    }
}

int main() {
    int N;
    cin >> N;
    int values[N];

    for (int i = 0; i < N; ++i) {
        cin >> values[i];
        values[i] += i; // Bước 1
    }

    // Bước 2: Sử dụng quicksort
    quicksort(values, 0, N - 1);

    // Bước 3
    for (int i = 0; i < N; ++i) {
        values[i] -= i;
    }

    // Bước 4
    bool sorted = true;
    for (int i = 1; i < N; ++i) {
        if (values[i] < values[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        for (int i = 0; i < N; ++i) {
            cout << values[i] << " ";
        }
    } else {
        cout << ":(";
    }

    return 0;
}
