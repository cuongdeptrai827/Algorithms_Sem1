#include <iostream>
using namespace std;

void insertion_sort(long long a[], long long n){
    for (long long  i = 1;i < n; i++){
        // Lay ra phan tu x o chi so i
        long long x = a[i];
        long long  position = i - 1;
        while ( (position >= 0) && (x < a[position]) ){
            a [position +1] = a[position];
            position--;
        }
        a[position + 1] = x;
    }
}
int main() {
    long long  n;
    cin>>n;
    long long a[n];
    for ( long long i=0;i < n;i++ ){
        cin>>a[i];
    }
    insertion_sort(a,n);
    for (long long  i = 0; i < n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
