#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." <<endl;
            return -1; // Return a sentinel value for an empty stack
        }
        Node* temp = top;
        int poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Return a sentinel value for an empty stack
        }
        return top->data;
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout << "Stack after pushing elements:" << endl;
    while (!stack.isEmpty()) {
        cout << stack.pop() << endl;
    }

    return 0;
}
