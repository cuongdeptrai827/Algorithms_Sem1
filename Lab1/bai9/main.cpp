#include <iostream>
using namespace std;


void Bin_count(){
    // Nhap cac phan tu x va y
    long long  x, y;
    cin >> x >> y;

    // Tao mang d de luu tru cac phan tu tu 2^0 den 2^59
    long long d[60], q = 1;
    for (int i = 0; i < 60; i++){
        d[i] = q;
        q = q * 2;
    }

    long long kol = 0;

    // Kiểm tra các dãy con: Sử dụng ba vòng lặp for để kiểm tra tất cả các tổ hợp của r, m, và l từ 1 đến 58.
    // Nếu tổng của chúng (l + m + r) không vượt quá 60, chương trình tính tổng s bằng cách cộng các số mũ
    // của 2 từ mảng d[] tương ứng với chỉ số i.
    // Các số mũ được chọn phải thỏa mãn điều kiện: i < r hoặc (i >= r + m và i < r + m + l).
    // Nếu tổng s nằm trong khoảng từ x đến y, biến kol được tăng lên một.
    for (int a = 1; a <= 58; a++){
        for (int b = 1; b <= 58; b++){
            for (int c = 1; c <= 58; c++){
                if (c + b + a <= 60) {
                    long long  sum = 0;
                    for (int i = 0; i < 60; i++) {
                        if (i < a) {
                            sum = sum + d[i];
                        }
                        else if ((i >= a + b) && (i < a + b + c)) {
                            sum = sum + d[i];
                        }
                    }
                    if (sum >= x && sum <= y) {
                        kol++;
                    }
                }
            }
        }
    }
    cout << kol;
}
int main(){
    Bin_count();
    return 0;
}