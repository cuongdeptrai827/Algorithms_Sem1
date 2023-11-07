#include <iostream>
#include <cstdlib>// Adding library to using function srand()
using namespace std;
// Function to swap 2 elements
void swap(long long a[], long long i, long long j) {
    long long temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int random_pivot(long long l, long long r) {
    return l + rand() % (r - l + 1); // Create a random number in range from l to r
}

int hoare_partition(long long a[], long long l, long long r) {
    long long pivotIndex = random_pivot(l, r); // Select random pivot
    long long pivot = a[pivotIndex];
    long long i = l - 1;
    long long j = r + 1;

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

void quicksort(long long a[], long long l, long long r) {
    if (l >= r) return;
    int p = hoare_partition(a, l, r);
    quicksort(a, l, p);
    quicksort(a, p + 1, r);
}

int main() {
    long long n;
    cin >> n;
    long long a[n];

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    srand(time(0));
    quicksort(a,0,n-1);

    long long storage[n];
    for (long long i = 0; i < n; i++){
        storage[i] = 0;
    }
    long long i = n - 1;
    long long j = 0;
    while (i > 0){
        if (a[i] == a[i - 1]){
            storage[j] = a[i];
            i -= 2;
            j++;
        }
        else if (a[i] - 1 == a[i - 1]){
            storage[j] = a[i] - 1;
            i -= 2;
            j++;
        }
        else{
            i--;
        }
    }
    long long sum = 0;

    for (long long k = 0; k < n; k += 2){
        sum += storage[k] * storage[k + 1];
    }
    cout << sum;
    return 0;
}