#include<iostream>
using namespace std;

// Linear Search O(n)
bool ls(int a[], int n, int x){
    for (int i = 0; i < n; i++){
        if (a[i] == x) return true;
    }
    return false;
}

//Binary Search O(log(n))
// Luu y : Khi su dung binary search, cac phan tu phai duoc sap xep theo thu tu

bool bs(int a[],int n, int x){
    int l = 0;
    int r = n - 1;
    while ( l <= r ){
        int m = (l + r) / 2;
        if (a[m] == x) return true;
        else if (a[m] < x){ // phan tu mid < x, nen phai tim kiem o ben phai
            l = m + 1;
        }
        else r = m - 1; // phan tu mid > x, nen phai tim kiem o ben trai
    }
    return false;
}

// Cach khac de cai dat binary search la su dung de quy

bool bs1(int a[], int l, int r, int x){
    if (l > r) return false;
    int mid = (l + r) / 2;

    if (a[mid] == x)
        return true;

    else if (a[mid] < x)
        return bs1(a , mid + 1 , r , x);

    else
        return bs1(a, l , mid - 1 , x );
}

int main(){
    int n ,x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >>a[i];
    }
    if (bs(a , n , x)) {
        cout<<"Found !"<<endl;
    }
    else cout<<"Not found !"<<endl;
    return 0;
}