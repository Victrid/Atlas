#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    char tm;
    int* hgt  = new int[n];
    int* llm  = new int[n];
    int* rrm  = new int[n];
    int water = 0;
    for (int i = 0; i < n; i++) {
        cin >> tm;
        cin >> hgt[i];
    }
    cin >> tm;
    //每个点判断能够达到的高度
    int l = 0, r = n - 1;
    llm[0] = hgt[0];
    for (int i = 1; i < n; i++) {
        llm[i] = hgt[i] > llm[i - 1] ? hgt[i] : llm[i - 1];
    }
    rrm[n - 1] = hgt[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rrm[i] = hgt[i] > rrm[i + 1] ? hgt[i] : rrm[i + 1];
        water += (llm[i] > rrm[i] ? rrm[i] : llm[i]) - hgt[i];
    }
    cout << water;
}