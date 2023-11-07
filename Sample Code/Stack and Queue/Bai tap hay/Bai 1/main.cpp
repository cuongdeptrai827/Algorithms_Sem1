#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." <<endl;
            return -1; // Return a sentinel value for an empty stack
        }
        Node* temp = head;
        int poppedData = temp->data;
        head = head->next;
        delete temp;
        return poppedData;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Return a sentinel value for an empty stack
        }
        return head->data;
    }
};

int main() {
    Stack stack;

    int n;
    cout << "Input the number to change in to binary form :"; cin>>n;

    while (n != 0) {
        stack.push(n % 2);
        n/=2;
    }
    while (! stack.isEmpty()){
        cout<<stack.top();
        stack.pop();
    }
    return 0;
}
