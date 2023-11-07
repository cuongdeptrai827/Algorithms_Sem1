#include <iostream>
#include <cstdlib>// Adding library to using function srand()
using namespace std;
// Function to swap 2 elements

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int random_pivot(int l, int r) {
    return l + rand() % (r - l + 1); // Create a random number in range from l to r
}

int hoare_partition(int a[], int l, int r) {
    int pivotIndex = random_pivot(l, r); // Select random pivot
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
        } else return j;
    }
}

void quicksort(int a[], int l, int r) {
    if (l >= r) return;
    int p = hoare_partition(a, l, r);
    quicksort(a, l, p);
    quicksort(a, p + 1, r);
}

int main() {
    int n, k;
    cin >> n >> k;
    int a, b, c, a1, a2;
    cin >> a >> b >> c >> a1 >> a2;
    int arr[n];
    arr[0] = a1;
    arr[1] = a2;
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 2] * a + arr[i - 1] * b + c;
    }
    srand(time(0));
    quicksort(arr, 0, n - 1);

    int xorResult = 0;
    for (int i = 0; i < k; i++) {
        xorResult ^= arr[i];
    }

    cout << xorResult;

    return 0;
}