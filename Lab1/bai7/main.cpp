#include <iostream>
using namespace std;

void collapse() {
    // Nhap so luong truy van t
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int q = 15, w = 30, k = 0;

        for (int i = 0; i < n; ++i) {
            char x, y;
            int a;
            cin >> x >> y >> a;

            if (x == '>') {
                if (a > q) q = a;
            } else if (x == '<') {
                if (a < w) w = a;
            }

            if (q <= w && k == 0) {
                cout << q << endl;
            } else {
                cout << "-1" << endl;
                ++k;
            }
        }
    }

}

int main() {
    collapse();
    return 0;
}