#include <iostream>

using namespace std;

void merge(long long assignments[][2], long long l, long long mid, long long r) {
    long long i, j, k;
    long long n1 = mid - l + 1;
    long long n2 = r - mid;

    long long L[n1][2];
    long long R[n2][2];

    // Sao chép dữ liệu vào các mảng tạm thời L và R
    for (i = 0; i < n1; i++) {
        L[i][0] = assignments[l + i][0];
        L[i][1] = assignments[l + i][1];
    }
    for (j = 0; j < n2; j++) {
        R[j][0] = assignments[mid + 1 + j][0];
        R[j][1] = assignments[mid + 1 + j][1];
    }

    // Merge các mảng tạm thời L và R vào mảng gốc
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i][0] <= R[j][0]) {
            assignments[k][0] = L[i][0];
            assignments[k][1] = L[i][1];
            i++;
        } else {
            assignments[k][0] = R[j][0];
            assignments[k][1] = R[j][1];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L và R vào mảng gốc (nếu có)
    while (i < n1) {
        assignments[k][0] = L[i][0];
        assignments[k][1] = L[i][1];
        i++;
        k++;
    }
    while (j < n2) {
        assignments[k][0] = R[j][0];
        assignments[k][1] = R[j][1];
        j++;
        k++;
    }
}

void mergeSort(long long assignments[][2], long long l, long long r) {
    if (l < r) {
        long long mid = l + (r - l) / 2;
        // Sắp xếp các nửa và merge chúng
        mergeSort(assignments, l, mid);
        mergeSort(assignments, mid + 1, r);
        merge(assignments, l, mid, r);
    }
}

int main() {
    long long N;
    cin >> N;
    long long assignments[N][2];

    // Nhập dữ liệu vào mảng assignments
    for (long long i = 0; i < N; ++i) {
        cin >> assignments[i][0] >> assignments[i][1];
    }

    // Sắp xếp assignments bằng thuật toán Merge Sort
    mergeSort(assignments, 0, N - 1);

    long long currentTime = 0;
    long long totalScore = 0;

    // Duyệt qua mảng assignments và tính điểm tối đa
    for (long long i = 0; i < N; ++i) {
        currentTime += assignments[i][0];
        totalScore += assignments[i][1] - currentTime;
    }

    cout << totalScore << endl;

    return 0;
}



