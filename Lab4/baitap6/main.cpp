#include <bits/stdc++.h>
#include <vector>

using namespace std;
class PriorityQueue {
private:
    vector<pair<long long, long long>> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].first < heap[index].first) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild].first > heap[largest].first) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].first > heap[largest].first) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(pair<long long, long long> value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (!empty()) {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        }
    }

    pair<long long, long long> top() const {
        if (!empty()) {
            return heap[0];
        }
        // Handle this case appropriately based on your requirements.
        // For simplicity, returning a default-constructed pair.
        return make_pair(0, 0);
    }

    bool empty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }
};

bool isPrime[(long long)(1e7)];

void eratos() {
    for (long long i = 0; i < (long long)(1e7); i++) isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for (long long i = 2; i * i <= (long long)(1e7) - 1; ++i) {
        if (isPrime[i] == true) {
            for (long long j = i * 2; j <= (long long)(1e7) - 1; j += i)
                isPrime[j] = false;
        }
    }
}

// Hàm mergesort
void merge(vector<long long>& arr, long long low, long long mid, long long high) {
    long long n1 = mid - low + 1;
    long long n2 = high - mid;

    vector<long long> L(n1), R(n2);

    for (long long i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (long long j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    long long i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<long long>& arr, long long low, long long high) {
    if (low < high) {
        long long mid = low + (high - low) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    eratos();

    long long st = 2;
    vector<long long> res;
    PriorityQueue q;

    while (q.size() < n) {
        if (isPrime[st]) {
            q.push({-st, st * 50});
        }
        st++;
    }

    for (long long i = 1; i <= n; i++) {
        pair<long long, long long> tmp = q.top();
        q.pop();
        long long power = tmp.second % 50;
        long long base = tmp.second / 50;
        power *= 2;
        power++;
        tmp.first *= tmp.first;
        tmp.first *= -1;
        tmp.second = base * 50 + power;
        q.push(tmp);
    }

    while (!q.empty()) {
        pair<long long, long long> tmp = q.top();
        q.pop();
        long long power = tmp.second % 50;
        long long base = tmp.second / 50;
        for (long long i = 0; i < power; i++) {
            res.push_back(base);
        }
    }

    mergesort(res, 0, res.size() - 1);

    cout << res.size() << endl;
    for (auto x : res) {
        cout << x << " ";
    }

    return 0;
}