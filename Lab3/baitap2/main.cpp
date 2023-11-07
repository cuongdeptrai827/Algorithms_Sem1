#include <iostream>

struct Node {
    int data;
    Node* next;
};

typedef Node* node;

bool empty(node back) {
    return back == nullptr;
}

int getSize(node back) {
    int count = 0;
    while (back != nullptr) {
        ++count;
        back = back->next;
    }
    return count;
}

node makeNode(int x) {
    node temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    return temp;
}

void push(node& back, int x) {
    node temp = makeNode(x);
    if (back == nullptr) {
        back = temp;
    } else {
        temp->next = back;
        back = temp;
    }
}

void pop(node& back) {
    if (back == nullptr) {
        return;
    }
    node temp = back;
    back = back->next;
    delete temp;
}

int front(node back) {
    return back->data;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int n;
    std::cin >> n;

    char operand;
    int x;
    node back = nullptr;
    node last = nullptr;

    for (unsigned int i = 1; i <= n; i++) {
        std::cin >> operand;
        if (operand == '+') {
            std::cin >> x;
            if (back == nullptr) {
                back = makeNode(x);
                last = back;
            } else {
                last->next = makeNode(x);
                last = last->next;
            }
        } else {
            std::cout << front(back) << "\n";
            pop(back);
        }
    }

    // Free memory (delete remaining nodes in the stack)
    while (!empty(back)) {
        pop(back);
    }

    return 0;
}
