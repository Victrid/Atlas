#include "lc.hpp"

class Solution {
public:
    int minJumps(vector<int>& arr) {
        //* Using BFS method.
        //1.reduce vector size.
        for (auto i = arr.begin() + 2; i < arr.end(); i++) {
            while ((*i) == *(i - 1) && (*i) == *(i - 2)) {
                i = arr.erase(i);
            }
        }
        //2.construct a search node.
        //using an unordered_map to search for same numbers.
        //as introduced, map is good for searching as it only costs 
        //nearly const time.
        unordered_map<int, vector<vector<int>::iterator>> um;
        for (auto i = arr.begin(); i < arr.end(); i++) {
            if (um.find(*i) == um.end()) {
                vector<vector<int>::iterator> itr;
                itr.push_back(i);
                um[*i] = itr;
            } else {
                um[*i].push_back(i);
            }
        }

        //3. BFS search. using a vector to avoid loop.
        vector<bool> arrvisited(arr.size(), false);
        queue<vector<int>::iterator> q;
        vector<int>::iterator fin = arr.end();
        q.push(arr.begin());
        q.push(fin);
        int step = 0;
        while (!q.empty()) {
            if (q.front() == arr.end()) {
                q.pop();
                if (!q.empty()) {
                    q.push(fin);
                    step++;
                }
                continue;
            }
            if (q.front() == arr.end() - 1)
                return step;
            if (!arrvisited[q.front() - arr.begin()]) {
                if (q.front() != arr.begin() && !arrvisited[q.front() - arr.begin() - 1]) {
                    q.push(q.front() - 1);
                }
                if (q.front() + 1 != arr.end() && !arrvisited[q.front() - arr.begin() + 1]) {
                    q.push(q.front() + 1);
                }
                for (auto i = um[*q.front()].begin(); i < um[*q.front()].end(); i++) {
                    if (!arrvisited[*i - arr.begin()]) {
                        q.push(*i);
                    }
                }
            }
            arrvisited[q.front() - arr.begin()] = true;
            q.pop();
        }
        return step;
    }
};
