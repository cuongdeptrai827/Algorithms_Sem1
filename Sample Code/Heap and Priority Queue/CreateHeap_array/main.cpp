#include <iostream>

using namespace std;

class MaxHeap {
private:
    int* heap;
    int size;
    int capacity;

    void heapify(int i) {
        int largest = i;
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;

        if (left_child < size && heap[left_child] > heap[largest]) {
            largest = left_child;
        }

        if (right_child < size && heap[right_child] > heap[largest]) {
            largest = right_child;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap(int capacity) {
        this->capacity = capacity;
        heap = new int[capacity];
        size = 0;
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }

        heap[size] = value;
        int index = size;
        size++;

        while (index > 0) {
            int parent_index = (index - 1) / 2;
            if (heap[index] > heap[parent_index]) {
                swap(heap[index], heap[parent_index]);
                index = parent_index;
            } else {
                break;
            }
        }
    }

    int removeMax() {
        if (size == 0) {
            cout << "Heap is empty." << endl;
            return -1; // Trả về một giá trị không hợp lệ để chỉ ra rằng heap rỗng
        }

        int max_element = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return max_element;
    }

    void printHeap() {
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap(10);
    maxHeap.insert(3);
    maxHeap.insert(9);
    maxHeap.insert(1);
    maxHeap.insert(6);
    maxHeap.insert(5);

    cout << "Max-Heap: ";
    maxHeap.printHeap(); // Xuất: 9 6 1 3 5

    cout << "Loại bỏ phần tử lớn nhất: " << maxHeap.removeMax() << endl;
    cout << "Max-Heap sau khi loại bỏ: ";
    maxHeap.printHeap(); // Xuất: 6 5 1 3

    return 0;
}
