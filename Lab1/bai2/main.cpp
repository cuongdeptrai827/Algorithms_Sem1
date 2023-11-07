#include <iostream>
using namespace std;

int main() {
    int ka, n, k;
    cin >> n >> ka;
    k = ka % n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    if (k > 0) {
        for (int j = 0; j <= k - 1; j++) {
            for (int i = 0; i <= n - 2; i++) {
                b[i + 1] = a[i];
            }
            b[0] = a[n - 1];
            for (int z = 0; z <= n - 1; z++) {
                a[z] = b[z];
            }
        }
    } else {
        k = -k;
        for (int j = 0; j <= k - 1; j++) {
            for (int i = 0; i <= n - 2; i++) { b[i] = a[i + 1]; }
            b[n - 1] = a[0];
            for (int z = 0; z <= n - 1; z++) { a[z] = b[z]; }
        }
    }
    for (int i = 0; i < n; i++) { cout << b[i] << " "; }
    return 0;
}