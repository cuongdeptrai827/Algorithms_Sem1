#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Giá trị không hợp lệ, stack rỗng
        }
        int value = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    bool isEmpty() const {
        return topNode == NULL;
    }

    int top() const {
        if (isEmpty()) {
            return -1; // Giá trị không hợp lệ, stack rỗng
        }
        return topNode->data;
    }
};

int main() {
    int n;
    cin >> n;

    Stack stack;
    int* difficulties = new int[n];
    int* Results = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> difficulties[i];
        Results[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        while (!stack.isEmpty() && difficulties[i] > difficulties[stack.top()]) {
            int top = stack.pop();
            Results[top] = i - top;
        }
        stack.push(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << Results[i] << " ";
    }
    cout << endl;

    delete[] difficulties;
    delete[] Results;

    return 0;
}

