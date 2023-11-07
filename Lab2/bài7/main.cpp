#include <iostream>

using namespace std;

struct Lab {
    int time;
    int deadline;
};

void quicksort(Lab arr[], int low, int high) {
    if (low < high) {
        int i = low - 1;
        int pivot = arr[high].deadline;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j].deadline <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    Lab labs[n];
    for (int i = 0; i < n; ++i) {
        cin >> labs[i].time >> labs[i].deadline;
    }

    // Sắp xếp các công việc theo thời gian kết thúc tăng dần sử dụng quicksort
    quicksort(labs, 0, n - 1);

    int currentTime = 0;
    int totalPoints = 0;
    for (int i = 0; i < n; ++i) {
        if (labs[i].time >= currentTime) {
            currentTime += labs[i].deadline;
            totalPoints += labs[i].deadline;
        }
    }

    cout << totalPoints << endl;
    return 0;
}
