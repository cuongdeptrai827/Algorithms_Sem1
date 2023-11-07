#include<iostream>
using namespace std;
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
// Phương pháp " median of three " chọn pivot = phần tử có giá trị bằng 1 nửa tổng l và r( ngoài ra có phương pháp chọn pivot khác - ví dụ như phương pháp Randomize Pivot - bài tập 2 - lab 2 )
int median_of_three(int a[], int l, int r) {
    int mid = l + (r - l) / 2;
    if (a[l] > a[mid]) {
        swap(a, l, mid);
    }
    if (a[l] > a[r]) {
        swap(a, l, r);
    }
    if (a[mid] > a[r]) {
        swap(a, mid, r);
    }
    return mid;
}

int hoare_partition(int a[], int l, int r) {
    int pivotIndex = median_of_three(a, l, r);
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

void quicksort( int a[], int l, int r){
    if ( l >= r ) return;
    int p = hoare_partition(a,l,r);
    quicksort (a, l, p);
    quicksort (a, p+1, r);
}

int main(){
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}