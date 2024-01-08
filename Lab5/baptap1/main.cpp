#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

// Funcion to create a new BST node
struct node* newNode(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = x;
    temp -> left = nullptr;
    temp -> right = nullptr;
    return temp;
}

// funcion to insert a new node with given key in BST
struct node* insert(struct node* node, int x){

    // if the tree is empty, return a new node
    if (node == nullptr){
        return newNode(x);
    }

    // if the tree is node empty, recur down the tree
    if(x < node -> data){
        node -> left = insert(node -> left, x);
    }
    else if (x > node -> data){
        node -> right = insert(node -> right,x);
    }

    return node;
}

// function returns the node with minimum key value found in the tree
struct node* minValueNode(struct node* node){
    struct node* current = node;
    while (current && current -> left != nullptr){
        current = current -> left;
    }
    return current;
}

// function that deletes the key and returns to the new root
struct node* deleteNode(struct node* root, int x){
    // base case
    if (root == nullptr){
        return root;
    }

    // If the key to be deleted is smaller than the root's data, then it lies in right subtree
    if (x < root -> data){
        root -> left = deleteNode(root->left,x);
    }

    // if the key to be deleted is bigger the the root's data, then it lies in left subtree
    if (x > root -> data){
        root -> right = deleteNode(root->right,x);
    }

        // If the key to be deleted is same as root's key, then this is the node to be deleted
    else{
        // node with only on child or no child
        if (root -> left == nullptr){
            struct node* temp = root -> right;
            free(root);
            return temp;
        }
        else if (root -> right == nullptr){
            struct node* temp = root -> left;
            free(root);
            return temp;
        }

        // node with two children : get the inorder successor ( smallest in the right subtree)
        struct node*temp = minValueNode(root -> right);

        //copy the inorder successor's content the this node
        root -> data = temp -> data;

        // delete the inorder successor
        root -> right = deleteNode(root->right, temp -> data);
    }

    return root;
}

bool exist(struct node* node, int x){
    if(node == nullptr) {
        return false;
    }

    if (x < node -> data){
        return exist(node -> left, x);
    }
    if (x > node -> data){
        return exist(node -> right,x);
    }
    else {
        return true;
    }
}

int findNext(node* node, int x, int currentNext){
    if (node == nullptr){
        return currentNext;
    }

    // Nếu giá trị của nút lớn hơn x, cập nhật currentNext và tìm trong cây con trái
    if (x < node -> data){
        return findNext(node -> left, x, min(currentNext,node -> data));
    }
        // Nếu giá trị của nút nhỏ hơn x, tìm trong cây con bên phải
    else{
        return findNext(node -> right, x, currentNext);
    }
}


int findPrev(node* node, int x, int currentPrev) {
    if (node == nullptr) {
        return currentPrev;
    }

    if (x > node -> data) {
        // Nếu giá trị của nút nhỏ hơn x, cập nhật currentPrev và tìm trong cây con bên phải
        return findPrev(node->right, x, max(currentPrev, node->data));
    } else {
        // Nếu giá trị của nút lớn hơn hoặc bằng x, tìm trong cây con bên trái
        return findPrev(node->left, x, currentPrev);
    }
}

int main(){
    struct node* root = NULL;

    int n = 10;
    string operation;

    while (n--){
        cin >> operation;

        if (operation == "insert") {
            // Thêm x vào cây
            int x;
            cin >> x;
            insert(root,x);
        } else if (operation == "delete") {
            int x;
            cin >> x;
            deleteNode(root,x);
        } else if (operation == "exists") {
            // Kiểm tra x có tồn tại trong cây hay không
            int x;
            cin >> x;
            bool a = exist(root,x);
            if (a == 0) cout << "False" << endl;
            if (a == 1) cout << "True" << endl;

        } else if (operation == "next") {
            // Tìm và xuất phần tử nhỏ nhất lớn hơn x, hoặc "none" nếu không có
            int x;
            cin >> x;
            int value;
            int result = INT_MAX;
            result = findNext(root,value,x);
            if (result == INT_MAX) {
                cout << "none" << endl;
            } else {
                cout << result << endl;
            }
        } else if (operation == "prev") {
            // Tìm và xuất phần tử nhỏ nhất lớn hơn x, hoặc "none" nếu không có
            int x;
            cin >> x;
            int value;
            int result = INT_MAX;
            result = findPrev(root,value,x);
            if (result == INT_MAX) {
                cout << "none" << endl;
            } else {
                cout << result << endl;
            }
        }
    }

    return 0;
}
