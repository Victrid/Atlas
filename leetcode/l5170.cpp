#include "lc.hpp"

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int* w = new int[n]();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1)
                w[leftChild[i]]++;
            if (rightChild[i] != -1)
                w[rightChild[i]]++;
            if ((leftChild[i] != -1 && w[leftChild[i]] > 1) || (rightChild[i] != -1 && w[rightChild[i]] > 1))
                return false;
        }
        for (int i = 0; i < n; i++) {
            count += w[i];
        }
        if(count!=n-1)return false;
        else return true;
    }
};