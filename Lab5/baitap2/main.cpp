#include <iostream>
using namespace std;

struct Node {
    Node* left_child;
    Node* right_child;
    Node* father;
    int data;

    Node(int x){
        data = x;
        left_child = nullptr;
        right_child = nullptr;
        father = nullptr;
    }
};

struct BST {
    Node* root;

    BST(){
        root = nullptr;
    }

    void insert(int x) {
        if (exists(x) != nullptr) {
            return;
        }
        Node* leaf = new Node(x);
        Node* element = root;
        Node* father = nullptr;
        while (element != nullptr) {
            father = element;
            if (leaf->data < element->data) {
                element = element->left_child;
            } else {
                element = element->right_child;
            }
        }
        leaf->father = father;
        if (father == nullptr) {
            root = leaf;
        } else {
            if (leaf->data < father->data) {
                father->left_child = leaf;
            } else {
                father->right_child = leaf;
            }
        }
    }

    Node* exists(int x) {
        Node* element = root;
        while (element != nullptr && x != element->data) {
            if (x < element->data) {
                element = element->left_child;
            } else {
                element = element->right_child;
            }
        }
        return element;
    }

    Node* findNext(int x) {
        Node* element = root;
        Node* nextNode = nullptr;
        while (element != nullptr) {
            if (element->data > x) {
                nextNode = element;
                element = element->left_child;
            } else {
                element = element->right_child;
            }
        }
        return nextNode;
    }

    void deleteNode(int x) {
        Node* mark = exists(x);
        if (mark == nullptr) {
            return;
        }
        Node* prev;
        Node* element;
        if (mark->left_child == nullptr || mark->right_child == nullptr) {
            prev = mark;
        } else {
            prev = findNext(x);
        }
        if (prev->left_child != nullptr) {
            element = prev->left_child;
        } else {
            element = prev->right_child;
        }
        if (element != nullptr) {
            element->father = prev->father;
        }
        if (prev->father == nullptr) {
            root = element;
        } else {
            if (prev == prev->father->left_child) {
                prev->father->left_child = element;
            } else {
                prev->father->right_child = element;
            }
        }
        if (prev != mark) {
            mark->data = prev->data;
        }
        delete prev;
    }

    Node* findPrev(int x) {
        Node* element = root;
        Node* prev = nullptr;
        while (element != nullptr) {
            if (element->data < x) {
                prev = element;
                element = element->right_child;
            } else {
                element = element->left_child;
            }
        }
        return prev;
    }
};

int main() {
    BST tree;
    string command;
    int x;
    while (cin >> command) {
        if (command == "insert") {
            cin >> x;
            tree.insert(x);
        } else if (command == "delete") {
            cin >> x;
            tree.deleteNode(x);
        } else if (command == "exists") {
            cin >> x;
            bool result = (tree.exists(x) != NULL);
            cout << (result ? "true" : "false") << "\n";
        } else if (command == "next") {
            cin >> x;
            Node* result = tree.findNext(x);
            if (result != NULL) {
                cout << result->data << "\n";
            } else {
                cout << "none" << "\n";
            }
        } else if (command == "prev") {
            cin >> x;
            Node* result = tree.findPrev(x);
            if (result != NULL) {
                cout << result->data << "\n";
            } else {
                cout << "none" << "\n";
            }
        }

    }

    return 0;
}