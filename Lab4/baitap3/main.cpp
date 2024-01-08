#include <iostream>
#include <vector>
using namespace std;

struct Seller {
    long long salary = 0;
    long long avai_time = 1000000000;
};

struct Heap {
    vector<Seller> sellers;
    bool is_time = false;

    void siftDown(int i) {
        if (!is_time) {
            while (2 * i + 1 < sellers.size()) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int j = left;
                if (2 * i + 2 < sellers.size() and sellers[right].salary < sellers[left].salary) {
                    j = right;
                }
                if (sellers[i].salary <= sellers[j].salary)
                    break;
                else {
                    swap(sellers[i], sellers[j]);
                    i = j;
                }
            }
        } else {
            while (2 * i + 1 < sellers.size()) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int j = left;
                if (2 * i + 2 < sellers.size() and sellers[right].avai_time < sellers[left].avai_time) {
                    j = right;
                }
                if (sellers[i].avai_time <= sellers[j].avai_time)
                    break;
                else {
                    swap(sellers[i], sellers[j]);
                    i = j;
                }
            }
        }
    }

    void shiftUp(int i) {
        if (!is_time) {
            while (sellers[i].salary < sellers[(i - 1) / 2].salary) {
                swap(sellers[i], sellers[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        } else {
            while (sellers[i].avai_time < sellers[(i - 1) / 2].avai_time) {
                swap(sellers[i], sellers[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }
    }

    void insert(Seller seller) {
        sellers.push_back(seller);
        shiftUp(sellers.size() - 1);
    }

    Seller extractMin() {
        Seller temp = sellers[0];
        sellers[0] = sellers[sellers.size() - 1];
        sellers[sellers.size() - 1] = temp;
        sellers.pop_back();
        siftDown(0);
        return temp;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numSellers;
    int numOrders;
    cin >> numSellers >> numOrders;

    Heap freeSellers;
    Heap busySellers;

    busySellers.is_time = true;

    for (int i = 0; i < numSellers; i++) {
        Seller newSeller;
        cin >> newSeller.salary;
        freeSellers.insert(newSeller);
    }

    int startTime;
    int workTime;
    long long totalSalary = 0;

    for (int i = 0; i < numOrders; i++) {
        cin >> startTime >> workTime;

        if (!busySellers.sellers.empty()) {
            Seller minSeller = busySellers.extractMin();

            while (minSeller.avai_time <= startTime) {
                minSeller.avai_time = 1000000000;
                freeSellers.insert(minSeller);
                if (!busySellers.sellers.empty())
                    minSeller = busySellers.extractMin();
            }

            if (minSeller.avai_time != 1000000000)
                busySellers.insert(minSeller);
        }

        if (!freeSellers.sellers.empty()) {
            Seller minSeller = freeSellers.extractMin();
            totalSalary += minSeller.salary * workTime;
            minSeller.avai_time = startTime + workTime;
            busySellers.insert(minSeller);
        }
    }

    cout << totalSalary;

    return 0;
}
