#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value)
    {
        data = value;
        next = prev = NULL;
    }
};

struct Queue {
    Node *head = NULL,*back = NULL;

    void push_back(int x){
        Node* newNode = new Node(x);
        if(back == NULL){
            head = back = newNode;
            return;
        }
        newNode -> prev = back;
        back -> next = newNode;
        back = newNode;
        //back -> next = NULL;
    }

    void push_head(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        if (back == NULL) back = newNode;
        head = newNode;
    }

    void pop_head(){
        if(head == NULL) return;
        Node* del = head -> next;
        if (del != NULL) del->prev = NULL;
        else back = NULL;
        delete(head);
        head = del;
    }

    void pop_back() {
        if(head == NULL) return;
        Node* del = back -> prev;
        if (del != NULL) del -> next = NULL;
        else back = NULL;
        delete(back);
        back = del;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Queue bag;
    int n, k;
    cin >> n >> k;
    int t;
    int k_1 = min(k, n);

    for (int i = 0; i < k_1; i++) {
        cin >> t;
        bag.push_head(t);
    }

    if (n >= k) {
        for (int i = k; i < n; i++) {
            cin >> t;
            int t2 = bag.head->data;
            int t3 = bag.back->data;
            int max1 = max(t, max(t2, t3));
            int max2 = (t == max1) ? max(t2, t3) : ((t2 == max1) ? max(t, t3) : max(t, t2));

            bag.pop_head();
            bag.pop_back();

            bag.push_head(max2);
            bag.push_head(max1);
        }
    }

    while (bag.back != NULL) {
        cout << (bag.back)->data << " ";
        bag.pop_back();
    }

    return 0;
}