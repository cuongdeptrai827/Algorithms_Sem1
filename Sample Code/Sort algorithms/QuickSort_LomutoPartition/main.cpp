#include <iostream>
using namespace std;


int median_of_three(int a[], int l, int r) {
    int mid = l + (r - l) / 2;
    if (a[l] > a[mid]) {
        swap(a[l],a[mid]);
    }
    if (a[l] > a[r]) {
        swap(a[l],a[r]);
    }
    if (a[mid] > a[r]) {
        swap(a[mid],a[r]);
    }
    return mid;
}

int lomuto_partition(int a[], int l, int r) {
    int pivotIndex = median_of_three(a, l, r);
    swap(a[pivotIndex],a[r]);

    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i],a[j]);
        }
    }

    // Making pivot into the middle
    swap(a[i+1],a[r]);
    return i + 1;
}

void quicksort(int a[], int l, int r){
    if (l >= r) return;
    int p = lomuto_partition(a,l,r);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);
}

int main(){
    int n;
     cin>>n;
     int a[n];
     for (int i=0;i<n;i++ ){
         cin>>a[i];
     }
     quicksort(a,0,n-1);
     for (int i=0; i<n; i++){
         cout<<a[i]<<" ";
     }
     return 0;
}