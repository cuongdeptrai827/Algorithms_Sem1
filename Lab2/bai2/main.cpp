#include <iostream>
#include <cstdlib> // Thêm thư viện này để sử dụng rand()
using namespace std;

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int random_pivot(int l, int r) {
    return l + rand() % (r - l + 1); // Sinh số ngẫu nhiên trong khoảng từ l đến r
}

int hoare_partition(int a[], int l, int r) {
    int pivotIndex = random_pivot(l, r); // Chọn pivot ngẫu nhiên
    int pivot = a[pivotIndex];
    int i = l - 1;
    int j = r + 1;

    while (1) {
        do {
            j--;
        } while (a[j] > pivot);

        do {
            i++;
        } while (a[i] < pivot);

        if (i < j) {
            swap(a, i, j);
        }
        else return j;
    }
}

void quicksort(int a[], int l, int r) {
    if (l >= r) return;
    int p = hoare_partition(a, l, r);
    quicksort(a, l, p);
    quicksort(a, p + 1, r);
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    srand(time(0)); // Khởi tạo seed cho hàm rand() bằng thời gian hiện tại
    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
