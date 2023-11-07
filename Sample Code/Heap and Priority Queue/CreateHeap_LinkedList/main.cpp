#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class MaxHeap {
private:
    Node* root;

    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void destroyTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    void heapify(Node* node) {
        if (node == nullptr) {
            return;
        }

        Node* largest = node;
        Node* leftChild = node->left;
        Node* rightChild = node->right;

        if (leftChild != nullptr && leftChild->data > largest->data) {
            largest = leftChild;
        }

        if (rightChild != nullptr && rightChild->data > largest->data) {
            largest = rightChild;
        }

        if (largest != node) {
            swap(node->data, largest->data);
            heapify(largest);
        }
    }

public:
    MaxHeap() : root(nullptr) {}

    ~MaxHeap() {
        destroyTree(root);
    }

    void insert(int value) {
        if (root == nullptr) {
            root = createNode(value);
        } else {
            insertNode(root, value);
        }
    }

    void insertNode(Node* node, int value) {
        if (node->left == nullptr) {
            node->left = createNode(value);
        } else if (node->right == nullptr) {
            node->right = createNode(value);
        } else {
            if (node->left->left == nullptr || node->left->right == nullptr) {
                insertNode(node->left, value);
            } else {
                insertNode(node->right, value);
            }
        }
        heapify(root);
    }

    int removeMax() {
        if (root == nullptr) {
            return -1; // Trả về một giá trị không hợp lệ để chỉ ra rằng heap rỗng
        }

        int maxElement = root->data;
        Node* lastNode = getLastNode();
        if (lastNode != root) {
            swap(root->data, lastNode->data);
            if (lastNode->parent->left == lastNode) {
                delete lastNode->parent->left;
                lastNode->parent->left = nullptr;
            } else {
                delete lastNode->parent->right;
                lastNode->parent->right = nullptr;
            }
            heapify(root);
        } else {
            delete root;
            root = nullptr;
        }

        return maxElement;
    }

    Node* getLastNode() {
        if (root == nullptr) {
            return nullptr;
        }

        Node* lastNode = nullptr;
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            lastNode = queue.front();
            queue.pop();
            if (lastNode->left != nullptr) {
                queue.push(lastNode->left);
            }
            if (lastNode->right != nullptr) {
                queue.push(lastNode->right);
            }
        }
        return lastNode;
    }
};
