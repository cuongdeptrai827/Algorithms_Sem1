#include <iostream>
using namespace std;

int basicRecursionFib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    return basicRecursionFib(n - 1) + basicRecursionFib(n - 2);
}

int memoizedRecursionFib(int n, int cache[3]) {
    if (cache[n] > 0) {
        return cache[n];
    }

    if (n == 1 || n == 2) {
        cache[n] = 1;
    } else {
        cache[n] = memoizedRecursionFib(n - 1, cache) + memoizedRecursionFib(n - 2, cache);
    }

    return cache[n];
}

void basicLoopFib(int n, int cache[3]) {
    if (n == 1 || n == 2) {
        cache[n] = 1;
    } else {
        for (int index = 3; index <= n; index++) {
            cache[index] = cache[index - 1] + cache[index - 2];
        }
    }
}

int fastLoopFib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    int first = 1, second = 2;
    for (int index = 3; index <= n; index++) {
        second += first;
        first = second - first;
    }

    return second;
}

int main() {
    int n;
    std::cin >> n;

    int cache[3] = {0};

     std::cout << basicRecursionFib(n) << std::endl;
     std::cout << memoizedRecursionFib(n, cache) << std::endl;
     basicLoopFib(n, cache);
     for (int i = 0; i < 3; i++) {
       std::cout << cache[i] << " ";
     }

    std::cout << fastLoopFib(n) << std::endl;

    return 0;
}
