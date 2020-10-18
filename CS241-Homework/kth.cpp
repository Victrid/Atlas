#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int inputarr[260];

int pivotsplit(int* arr, int size) {
    int x = arr[size - 1], sp = 0;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] >= x) {
            swap(arr[sp], arr[i]);
            sp++;
        }
    }
    swap(arr[sp], arr[size - 1]);
    return sp;
}
int kth(int* arr, int n, int k) {
    int splitpos = pivotsplit(arr, n);
    if (splitpos == k)
        return arr[splitpos];
    else
        return splitpos < k
                   ? kth(arr + splitpos + 1, n - splitpos - 1, k - splitpos - 1)
                   : kth(arr, splitpos, k);
}

int main() {
    // Input processing.
    int n = 0, k;
    std::string line;
    int number;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> number) {
        inputarr[n] = number;
        n++;
    }
    cin >> k;
    cout << kth(inputarr, n, k - 1);
    return 0;
}
