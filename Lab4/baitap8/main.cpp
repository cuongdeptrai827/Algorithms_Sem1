#include <iostream>
#include <string>

using namespace std;
int char_to_int(char y){
    return y - '0'; // Chuyển ký tự số thành số nguyên
}

char int_to_char(int x) {
    return '0' + x; // Chuyển số nguyên thành ký tự số
}

char char_to_char(char x){
    if (x == '-'){
        return '-';
    }
    return '0' + (x - '0'); // Chuyển ký tự số thành ký tự số
}

string Tong(string a, string b){
    int lengthA = a.length();
    int lengthB = b.length();

    if (lengthA < lengthB){
        swap(a, b);
        swap(lengthA, lengthB);
    }

    bool car = false;
    int tong = 0;
    int digitA;
    int digitB;

    for (int i = 0; i < lengthB; i++){
        digitA = char_to_int(a[lengthA - i - 1]);
        digitB = char_to_int(b[lengthB - i - 1]);
        tong = digitA + digitB + car;

        if (tong > 9){
            car = true;
            a[lengthA - i - 1] = int_to_char(tong - 10);
        } else{
            car = false;
            a[lengthA - i - 1] = int_to_char(tong);
        }
    }

    int k = 0;
    bool stop = true;

    while (car && stop){
        if (lengthA == lengthB){
            a = '1' + a;
            car = false;
        } else {
            if (char_to_int(a[lengthA - lengthB - 1 - k]) < 9){
                a[lengthA - lengthB - 1 - k] = int_to_char(char_to_int(a[lengthA - lengthB - 1 - k]) + 1);
                car = false;
            } else {
                a[lengthA - lengthB - 1 - k] = '0';
                car = true;
                if (k + 1 == lengthA - lengthB){
                    stop = false;
                    a = '1' + a;
                }
            }
            k += 1;
        }
    }

    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int quantity;
    cin >> quantity;

    string kqua;
    cin >> kqua;

    string x;

    for (int i = 1; i < quantity; i++){
        cin >> x;
        kqua = Tong(kqua, x);
    }

    cout << kqua;

    return 0;
}