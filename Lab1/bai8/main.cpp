#include <iostream>
#include <cmath>

using namespace std;

int main(){
    // Input the number of room and the coefficients for each room
    int n;
    cin >> n;
    int a[n];
    long long  min = pow(10,10);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }


    if (n > 30) {
        for (int j = 0; j < 30; j++) {
            int follow = 0, count = 1;
            for (int i = j; i < n; i++){
                if ((follow & a[i]) == 0) {
                    follow = (a[i] | follow);
                }
                else{
                    count++;
                    follow = a[i];
                }
            }
            for (int i = 0; i < j; i++){
                if ((follow & a[i]) == 0) {
                    follow = (a[i] | follow);
                }
                else{
                    count++;
                    follow = a[i];
                }
            }
            if (count < min){
                min = count;
            }
        }
    }


    else{
        for (int j = 0; j < n; j++) {
            int follow = 0, count = 1;
            for (int i = j; i < n; i++){
                if ((follow & a[i]) == 0) {
                    follow = (a[i] | follow);
                }
                else{
                    count++;
                    follow = a[i];
                }
            }
            for (int i = 0; i < j; i++){
                if ((follow & a[i]) == 0) {
                    follow = (a[i] | follow);
                }
                else{
                    count ++;
                    follow = a[i];
                }
            }
            if (count  < min){
                min = count;
            }
        }
    }


    cout << min;
    return 0;
}