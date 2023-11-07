#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};
typedef struct Node* node;

// Kiem tra xem stack co rong hay khong
bool IsEmpty(node top){
    if (top == NULL) return true;
    else return false;
}

//Xac dinh so phan thu trong stack
int getSize(node top){
    int ans = 0;
    while (top != NULL){
        ans ++;
        top = top->next;
    }
    return ans;
}
// Khoi tao mot gia tri trong stack
node makeNode(int x){
    node temp = new Node();
    temp -> data = x;
    temp -> next = NULL;
    return temp;
}

// Day 1 phan tu vao trong Stack
void push(node &top,int x){
    node temp = makeNode(x);
    if (top == NULL){
        top = temp;
    }
    else{
        temp ->next = top;
        top =temp;
    }
}
// Day phan tu top ra khoi stack
void pop (node &top){
    if (top == NULL) return;
    top = top -> next;
}
// Tra ve gia tri dau tien o dinh stack ma khong loai bo no
int getTop(node top){
    return top -> data;
}

int main(){
    // Bien doi so thap phan ra so nhi phan
    node top = NULL;
    long long n;
    cin>>n;
    while ( n != 0 ){
        int r = n % 2;
        push(top,r);
        n /= 2;
    }
    while(!IsEmpty(top)){
        cout<<getTop(top);
        pop(top);
    }
    return 0 ;
}
 