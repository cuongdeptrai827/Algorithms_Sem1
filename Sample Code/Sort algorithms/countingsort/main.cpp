#include <iostream>
using namespace std;
int count[10000001];
int main() {
    int a[1000];
    int n;
    cin >> n;
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++){
        cin >>a[i];
        count[a[i]]++;
        maximum = max(maximum,a[i]);
    }
    for (int i = 0; i <= maximum; i++){
        if (count[i] != 0){
            for (int j = 0; j < count[i]; j++){
                cout << i << " ";
            }
        }
    }

    return 0;
}
