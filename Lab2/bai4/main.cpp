#include <iostream>

using namespace std;
void swapping(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void WorstCase(int n) {
    int mas[n];
    for (int i = 0; i < n; ++i) {
        mas[i] = i + 1;
    }

    for (int i = 2; i < n; ++i) {
        swapping(mas,i,i/2);
    }

    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    WorstCase(n);

    return 0;
}
