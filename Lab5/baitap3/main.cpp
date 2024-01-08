#include <iostream>

using namespace std;

struct AppleTree {
    struct Node {
        long long int weight;
        Node* left;
        Node* right;
        long long int count;  // Số lượng phần tử trong cây con

        Node(long long int x){
            weight = x;
            left = nullptr;
            right = nullptr;
            count = 1;
        }
    };

    Node* root;
    long long int validCount;  // Số lượng phần tử hợp lệ

    AppleTree(){
        root = nullptr;
        validCount = 0;
    }

    void addapple(long long int weight) {
        root = addAppleRecursive(root, weight);
        validCount++;
    }

    Node* addAppleRecursive(Node* cur, long long int weight) {
        if (cur == nullptr) {
            return new Node(weight);
        }

        if (weight < cur->weight) {
            cur->left = addAppleRecursive(cur->left, weight);
        } else if (weight > cur->weight) {
            cur->right = addAppleRecursive(cur->right, weight);
        }

        cur->count++;  // Tăng số lượng phần tử trong cây con
        return cur;
    }

    void removeApple(long long int x) {
        root = removeAppleRecursive(root, x);
        validCount--;
    }

    Node* removeAppleRecursive(Node* current, long long int x) {
        if (current == nullptr) {
            return nullptr;
        }

        if (x < current->weight) {
            current->left = removeAppleRecursive(current->left, x);
        } else if (x > current->weight) {
            current->right = removeAppleRecursive(current->right, x);
        } else {
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current ->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            Node* minNode = findMinNode(current->right);
            current->weight = minNode->weight;
            current->right = removeAppleRecursive(current->right, minNode->weight);
        }

        current->count--;  // Giảm số lượng phần tử trong cây con
        return current;
    }

    Node* findMinNode(Node* current) {
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    long long int getK_thMax(long long int k) {
        if (k > validCount || k <= 0) {
            return -1;
        }

        return getK_thMaxRecursive(root, k);
    }

    long long int getK_thMaxRecursive(Node* current, long long int k) {
        if (current == NULL) {
            return -1;
        }

        long long int rightCount = (current->right != NULL) ? current->right->count : 0;

        if (k == rightCount + 1) {
            return current->weight;
        } else if (k <= rightCount) {
            return getK_thMaxRecursive(current->right, k);
        } else {
            return getK_thMaxRecursive(current->left, k - rightCount - 1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;
    cin >> n;

    AppleTree tree;

    for (long long int i = 0; i < n; i++) {
        int command;
        long long int x;

        cin >> command >> x;

        if (command == 1) {
            tree.addapple(x);
        } else if (command == 0) {
            cout << tree.getK_thMax(x) << "\n";
        } else if (command == -1) {
            tree.removeApple(x);
        }
    }

    return 0;
}
