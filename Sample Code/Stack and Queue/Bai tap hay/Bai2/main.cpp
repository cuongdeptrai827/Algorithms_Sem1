#include <iostream>

class Stack {
private:
    char* data;
    int capacity;
    int topIndex;

public:
    Stack(int size) {
        capacity = size;
        data = new char[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] data;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    void push(char value) {
        if (isFull()) {
            std::cout << "Stack is full. Cannot push element." << std::endl;
            return;
        }
        data[++topIndex] = value;
    }

    char pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop element." << std::endl;
            return '\0'; // Return a sentinel value for an empty stack
        }
        return data[topIndex--];
    }
};

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(); // Consume the newline character after reading 't'
    while (t--) {
        const int maxSize = 1000;
        char input[maxSize];
        std::cin.getline(input, maxSize);
        int inputLength = std::cin.gcount() - 1; // Exclude the newline character

        Stack stack(inputLength);
        bool isValid = true;
        for (int i = 0; i < inputLength; ++i) {
            char x = input[i];
            if (x == '(') {
                stack.push(x);
            } else {
                if (stack.isEmpty()) {
                    isValid = false;
                    break;
                } else {
                    stack.pop();
                }
            }
        }
        if (isValid && stack.isEmpty()) {
            std::cout << "Valid" << std::endl;
        } else {
            std::cout << "Invalid" << std::endl;
        }
    }
    return 0;
}
