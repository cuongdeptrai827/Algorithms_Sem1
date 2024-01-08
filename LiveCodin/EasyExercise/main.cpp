#include <iostream>
#include<vector>
using namespace std;


int lomuto_partition(vector<int>& a, int l, int r) {
    int pivot = a[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return (i + 1);
}

void quicksort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = lomuto_partition(a,l,r);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);

}


// Hàm tìm vị trí đầu tiên trong mảng sao cho arr[pos] >= key
int lower_bound(vector<int>& a, int key) {
    int l = 0;
    int r = a.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < key) {
           l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}


// Hàm tìm vị trí đầu tiên trong mảng sao cho arr[pos] > key
int upper_bound(vector<int>& a, int key) {
    int l = 0;
    int r = a.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= key) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int count_products_in_range(vector<int>& products, int l, int r) {
    int left_index = lower_bound(products, l);
    int right_index = upper_bound(products, r);
    return right_index - left_index;
}

vector<int> inventory_queries(int n, vector<int>& products, int k, vector<pair<int, int>>& queries) {
    // Sắp xếp số sản phẩm bằng quicksort
    quicksort(products, 0, n - 1);

    vector<int> result;

    // Xử lý từng truy vấn
    for (const auto& query : queries) {
        int l = query.first;
        int r = query.second;
        result.push_back(count_products_in_range(products, l, r));
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    vector<pair<int, int>> queries(k);
    for (int i = 0; i < k; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Lấy kết quả và in ra màn hình
    vector<int> result = inventory_queries(n, a, k, queries);
    for (int i = 0; i < k; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}



