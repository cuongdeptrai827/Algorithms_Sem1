#include <iostream>
#include <vector>

using namespace std;

struct Node{
    long long data;
};

vector<Node> heap[1000001];

long long father(long long i){
    return (i - 1) / 2;
}

long long leftChild(long long i){
    return 2 * i + 1;
}

long long rightChild(long long i){
    return 2 * i + 2;
}

void sift_Up(long long row, long long i){
    while (i > 0 && heap[row][father(i)].data > heap[row][i].data){
        swap(heap[row][father(i)], heap[row][i]);
        i = father(i);
    }
}

void sift_Down(long long row, long i, long size){
    long long min = i;
    if (leftChild(i) < size && heap[row][leftChild(i)].data < heap[row][min].data){
        min = leftChild(i);
    }
    if (rightChild(i) < size && heap[row][rightChild(i)].data < heap[row][min].data){
        min = rightChild(i);
    }
    if (min != i){
        swap(heap[row][min], heap[row][i]);
        sift_Down(row, min, size);
    }
}

void insert(long long row, long long value){
    heap[row].push_back({ value });
    long long size = heap[row].size();
    sift_Up(row, size - 1);
}

void extract_Min(long long row){
    if (heap[row].empty()){
        cout << "*" << '\n';
        return;
    }
    long long min = heap[row][0].data;
    cout << heap[row][0].data << '\n';

    long long size = heap[row].size();
    heap[row][0] = heap[row][size - 1];
    heap[row].pop_back();
    size--;
    sift_Down(row, 0, size);
}

void decrease_Key(long long row, long long x, long long y){
    long long size = heap[row].size();
    bool found = false;

    for (long long i = 0; i < size; i++) {
        if (heap[row][i].data == x) {
            if (x >= y) {
                heap[row][i].data = y;
                sift_Up(row, i);
            }
            break;
        }
    }

    if (!found) {
        return;
    }
}
void create(long long &numOfTree){
    heap[numOfTree].clear();
    numOfTree++;
}
void merge(long long k, long long m, long long &numOfTree){
    vector<Node> mergedHeap;
    mergedHeap.insert(mergedHeap.end(), heap[k].begin(), heap[k].end());
    mergedHeap.insert(mergedHeap.end(), heap[m].begin(), heap[m].end());

    long long newSize = mergedHeap.size();


    heap[numOfTree] = mergedHeap;

    long long size = heap[numOfTree].size();
    for (long long i = size / 2 - 1; i >= 0; i--){
        sift_Down(numOfTree, i, size);
    }

    numOfTree++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string command;
    long long row = 0;
    long long int numOfTree = 0;
    while (cin >> command){
        if (command == "create"){
            create(numOfTree);
        }
        else if (command == "insert"){
            long long k, x;
            cin >> k >> x;
            insert(k, x);
        }
        else if (command == "extract-min"){
            long long k;
            cin >> k;
            extract_Min(k);
        }
        else if (command == "merge"){
            long long k, m;
            cin >> k >> m;
            merge(k, m, numOfTree);
        }
        else if (command == "decrease-key"){
            long long k, x, y;
            cin >> k >> x >> y;
            decrease_Key(k, x, y);
        }
        row++;
    }
    return 0;
}
