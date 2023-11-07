#include <bit/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

bool empty(node back){
    return back == NULL;
}

int getSize (node back){
    int count = 0;
    while (back != NULL) {
        ++ count;
        back = back->next;
    }
    return count;
}
node makeNode(int x){
    node temp = new Node();
    temp -> data = x;
    temp -> next = NULL;
    return temp;
}
// push
void push (node &back, int x){
    node temp = makeNode(x);
    if (back == NULL) back = temp;
    else{
        temp -> next  = back;
        back = temp;
    }
}

//pop
void pop(node &back){
    node truoc = NULL; sau = back;
    while (sau -> next != NULL){
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL){
        back = NULL;
    }
    else{
        truoc -> next = NULL;
    }
}

int front(node back){
    while (back -> next != NULLL){
        back = back -> next;
    }
    return back -> data;
}

