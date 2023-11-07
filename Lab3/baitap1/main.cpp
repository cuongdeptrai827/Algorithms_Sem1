#include <iostream>

struct Node {
    int data;
    Node* next;
};

typedef Node* node;

bool isEmpty(node top) {
    return top == NULL;
}

node makeNode(int x) {
    node temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    return temp;
}

void push(node& top, int x) {
    node temp = makeNode(x);
    if (top == NULL) {
        top = temp;
    } else {
        temp->next = top;
        top = temp;
    }
}

void pop(node& top) {
    if (top == nullptr) {
        return;
    }
    node temp = top;
    top = top->next;
    delete temp;
}

int getTop(node top) {
    if (top != NULL) {
        return top->data;
    }
    return -1; // Return a sentinel value for an empty stack
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int n;
    std::cin >> n;

    char operand;
    int x;
    node top = nullptr;

    for (unsigned int i = 1; i <= n; i++) {
        std::cin >> operand;
        if (operand == '+') {
            std::cin >> x;
            push(top, x);
        } else {
            std::cout << getTop(top) << "\n";
            pop(top);
        }
    }

    // Free memory (delete remaining nodes in the stack)
    while (!isEmpty(top)) {
        pop(top);
    }

    return 0;
}

