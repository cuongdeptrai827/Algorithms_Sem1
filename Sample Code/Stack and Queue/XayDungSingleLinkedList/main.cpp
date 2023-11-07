#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

// Cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x){
    node temp = new Node();
    temp -> data = x;
    temp -> next = NULL;
    return temp;
}

// Kiem tra Node rong hay khong ?
bool empty(node a){
    if ( a == NULL ) return true;
    else return false;
}
// Dem xem trong danh sach lien ket co bao nhieu phan tu
int Size(node a){
    int count = 0;
    while ( a!= NULL){
        ++count;
        a = a -> next; // Cho node hien tai nhay sang node tiep theo
    }
}

// Them mot phan tu vao dau danh sach lien ket ( trong truong hop su dung typedef)
void insertFirst1( node &a , int x){
    node temp = makeNode(x);
    if (a == NULL){
        a = temp;
    }
    else{
        temp -> next = a;
        a = temp;
    }
}
/*
// Them mot phan tu vao dau danh sach lien ket ( trong truong hop khong su dung typedef)
void insertFirst2( node *a , int x){
    if (*a == NULL){
        *a = temp;
    }
    else{
        temp -> next = *a;
        *a = temp;
    }
}
*/


void insertLast(node &a, int x){ // Them mot phan tu vao cuoi danh sach lien ket
    node temp = makeNode(x);
    if ( a == NULL){
        a = temp;
    }
    else{
        node p = a;
        while ( p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

// Them mot phan thu vao giua
void insertMiddle(node &a, int x, int pos){
    int n = Size(a);
    if (pos <= 0 || pos > n + 1){
        cout<<" Vi tri chen khong hop le !"<<endl;
    }
    if ( pos == 1){
        insertFirst1(a,x); return;
    }
    if ( pos == n + 1){
        insertLast(a,x); return;
    }
    node p = a;
    for (int i = 1; i < pos -1; i++){
        p = p -> next;
    }
    node temp = makeNode(x);
    temp -> next = p -> next;
    p -> next = temp;
}

// Xoa phan tu o dau
void deleteFirst(node &a){
    if (a == NULL) return;
    a = a-> next;
}

// Xoa phan tu o cuoi
void deleteLast(node &a){
    if (a == NULL) return;
     node truoc = NULL, sau = a;
     while ( sau->next != NULL){
         truoc = sau;
         sau = sau->next;
     }
     if (truoc == NULL){
         a = NULL;
     }
     else{
         truoc->next = NULL;
     }
}

// Xoa phan tu o giua
void deleteMiddle(node &a, int pos){
    if (pos <= 0 || pos > Size(a)) return;
    node truoc = NULL, sau = a;
    for (int i = 1; i < pos; i++){
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL){
        a = a->next;
    }
    else {
        truoc->next = sau ->next;
    }
}

void print(node a){
    while (a != NULL){
        cout<<a->data<<" ";
        a = a->next;
    }
}

int main(){
    node head = NULL;
    while(1) {
        cout<<endl;
        cout << " ----------------Menu-------------\n";
        cout << " 1. Chen phan tu vao dau danh sach\n";
        cout << " 2. Chen phan tu vao cuoi danh sach\n";
        cout << " 3. Chen phan tu vao giua danh sach\n";
        cout << " 4. Xoa phan tu o dau\n";
        cout << " 5. Xoa phan tu o cuoi \n";
        cout << " 6. Xoa phan tu o giua\n";
        cout << " 7. In ra danh sach lien het\n";
        int lc;
        cin >> lc;
        if (lc == 1) {
            int x;
            cout << "Nhap gia tri can chen : ";
            cin >> x;
            insertFirst1(head, x);
        } else if (lc == 2) {
            int x;
            cout << "Nhap gia tri can chen : ";
            cin >> x;
            insertLast(head, x);
        } else if (lc == 3) {
            int x, pos;
            cout << "Nhap gia tri can chen : ";
            cin >> x;
            cout << "Nhap vi tri can chen : ";
            cin >> pos;
            insertMiddle(head, x, pos);
        } else if (lc == 4) {
            int x;
            deleteFirst(head);
        } else if (lc == 5) {
            deleteLast(head);
        } else if (lc == 6) {
            int pos;
            cout << "Nhap vi tri can chen : ";
            cin >> pos;
            deleteMiddle(head, pos);
        } else if (lc == 7) {
            print(head);
        }
    }
    return 0;
}