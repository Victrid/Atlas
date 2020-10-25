#ifndef TREE_H
#define TREE_H

// Add any standard library you need.
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

//
// Below is the class template provided by us.
// Feel free to reconstruct the code as long as its functions are realized.
//

// ==================== k-d tree ======================
struct kdNode {
    int key[2]; // To store 2 dimensional value
    kdNode* left  = nullptr;
    kdNode* right = nullptr;
};
class kdTree {
public:
    kdNode* root = nullptr;
    kdTree();
    ~kdTree();

    // Insert a new node with 2 dimensional value `arr`.
    // `dim` refers to the dimension of the root.
    void insert(kdNode*& root, int arr[], int dim);

    // Search node with value `arr`.
    // Return NULL if not exist.
    kdNode* search(kdNode*& root, int arr[], int dim);

    // Delete the node with value `arr`.
    void remove(kdNode*& root, int arr[], int dim);

    // Find the node with the minimum value in dimension `dimCmp`.
    // `dimCmp` equals to 0 or 1.
    kdNode* findMin(kdNode*& root, int dimCmp, int dim);

    // Find a vector of nodes whose values are >= `lower_bound` and <=
    // `upper_bound`. `lower_bound` contains lower bound for each dimension of
    // the target nodes. `upper_bound`, on the contrary, holds upper bound per
    // dimension. e.g. given lower_bound=[1, 2], upper_bound=[3, 4], node=[2, 3]
    // will be chosen, because 1<=2<=3, 2<=3<=4.
    vector<struct kdNode*> rangeSearch(kdNode* root, int dim, int lower_bound[],
                                       int upper_bound[]);

private:
    void rangeSearch(kdNode* root, int dim, int lower_bound[],
                     int upper_bound[], vector<struct kdNode*>& ansvector);
    void importTree(kdNode*& newroot, kdNode* oldroot, int newrootdim);
    void deleteSubTree(kdNode* root);
};

/*
// Your class will be instantiated and called as such:
const int k = 2;
kdTree* obj = new kdTree();
int points[][k] = {{30, 40}, {5, 25}, {70, 70},
                {10, 12}, {50, 30}, {35, 45}};
obj->insert(obj->root, points[0], 0);
obj->insert(obj->root, points[1], 0);
kdNode* res1 = obj->search(obj->root, points[2], 0); // and then test res1;
obj->remove(obj->root, points[1], 0);
kdNode* res2 = obj->findmin(obj->root, 1, 0); // and then test res2;
int bounds[][k] = {{0, 10}, {50, 35}};
vector<kdNode*> res3 = obj->rangesearch(obj->root, 0, bounds[0], bounds[1]);
// and then test res3.
*/

// ==================== trie (prefix tree) ======================
struct TrieNode {
    bool flag;
    map<char, TrieNode*> next;
};
class Trie {
public:
    TrieNode* root;
    Trie();

    // Inserts a word into the trie.
    void insert(string word);
    // Returns true if the word is in the trie.
    bool search(string word);

    // Returns true if there is any word in the trie that starts with the given
    // prefix.
    bool startsWith(string prefix);

private:
    void insert(TrieNode* cur, const string& str, int pos);
    bool search(const TrieNode* cur, const string& str, int pos);
    bool startsWith(const TrieNode* cur, const string& str, int pos);
    bool exist(const TrieNode* cur);
};

/*
// Your Trie object will be instantiated and called as such:
Trie* obj = new Trie();
string word = "apple";
string prefix = "app";
obj->insert(word);
bool res1 = obj->search(word);
bool res2 = obj->startsWith(prefix);
*/

#endif
