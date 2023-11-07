#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class Stack {
private:
    Node* top;
public:

    Stack() {
        top = NULL;
    }


    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }


    void pop() {
        if (isEmpty()) {
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }


    bool isEmpty() {
        return top == NULL;
    }


    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }
};

// Hàm giải bài toán
long long MaxRectangleArea(int h[], int n) {
    Stack stack;
    long long MaxArea = 0;
    for (int i = 0; i < n; ++i) {
        while (!stack.isEmpty() && h[i] < h[stack.peek()]) {
            int height = h[stack.peek()];
            stack.pop();
            int width = stack.isEmpty() ? i : i - stack.peek() - 1;
            MaxArea = max(MaxArea, static_cast<long long>(height) * width);
        }
        stack.push(i);
    }

    while (!stack.isEmpty()) {
        int height = h[stack.peek()];
        stack.pop();
        int width = stack.isEmpty() ? n : n - stack.peek() - 1;
        MaxArea = max(MaxArea, static_cast<long long>(height) * width);
    }

    return MaxArea;
}

int main() {
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    long long MaxArea = MaxRectangleArea(h, n);
    cout << MaxArea << endl;

    return 0;
}