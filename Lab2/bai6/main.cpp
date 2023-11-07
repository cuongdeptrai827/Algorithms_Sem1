#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long partition(long long scores[], long long filmIndices[], long long low, long long high) {
    long long pivot = scores[high];
    long long i = low - 1;
    for (long long j = low; j <= high - 1; j++) {
        if (scores[j] > pivot || (scores[j] == pivot && filmIndices[j] < filmIndices[high])) {
            i++;
            swap(scores[i], scores[j]);
            swap(filmIndices[i], filmIndices[j]);
        }
    }
    swap(scores[i + 1], scores[high]);
    swap(filmIndices[i + 1], filmIndices[high]);
    return i + 1;
}

void quicksort(long long scores[], long long filmIndices[], long long low, long long high) {
    if (low < high) {
        long long pi = partition(scores, filmIndices, low, high);
        quicksort(scores, filmIndices, low, pi - 1);
        quicksort(scores, filmIndices, pi + 1, high);
    }
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    long long heso[n];
    for (long long i = 0; i < n; ++i) {
        cin >> heso[i];
    }

    long long scores[m];
    long long filmIndices[m];
    for (long long i = 0; i < m; ++i) {
        scores[i] = 0;
        filmIndices[i] = i + 1;
        for (long long j = 0; j < n; ++j) {
            long long rating;
            cin >> rating;
            scores[i] = (scores[i] + heso[j] * rating) % MOD;
        }
    }

    quicksort(scores, filmIndices, 0, m - 1);

    for (long long i = 0; i < k; ++i) {
        cout << filmIndices[i] << " ";
    }

    return 0;
}
