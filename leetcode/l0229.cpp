#include "lc.hpp"
typedef vector<int>::iterator viit;
class Solution {
public:
    // using BM method
    //!wrong
    vector<int> majorityElement(vector<int>& nums) {
        // for null input
        if (nums.begin() == nums.end()) {
            vector<int> ret;
            return ret;
        }
        // finding first two candidates
        viit Candidate_A = nums.begin();
        int A_count      = 0;
        viit Candidate_B = nums.begin();
        int B_count      = 0;
        // get first different candidate.
        do {
            A_count++;
            Candidate_B++;
            if (Candidate_B == nums.end()) {
                // if all elements are the same
                vector<int> ret;
                ret.push_back(*Candidate_A);
                return ret;
            }
        } while (*Candidate_A == *Candidate_B);
        B_count = 1;

        // first loop: vote candidates
        for (viit Vote = Candidate_B + 1; Vote < nums.end(); Vote++) {
            if (*Candidate_A == *Vote) {
                A_count++;
            } else if (*Candidate_B == *Vote) {
                B_count++;
            } else {
                A_count--;
                B_count--;
            }
            if (B_count > A_count) {
                // swap
                viit temp     = Candidate_A;
                Candidate_A   = Candidate_B;
                Candidate_B   = temp;
                int tempcount = A_count;
                A_count       = B_count;
                B_count       = tempcount;
            }
            if (B_count < 0) {

                if (A_count >= 0) {
                    Candidate_B = Vote;
                    B_count     = 1;
                } else {
                    // All previous votes invalid. Reselect candidates
                    Candidate_A = Vote;
                    A_count     = 0;
                    Candidate_B = Vote;
                    B_count     = 0;
                    do {
                        A_count++;
                        Candidate_B++;
                        if (Candidate_B == nums.end()) {
                            // all elements are the same
                            // second loop
                            vector<int> ret;
                            A_count = 0;
                            for (viit Vote = nums.begin(); Vote < nums.end();
                                 Vote++)
                                if (*Vote == *Candidate_A)
                                    A_count++;
                            if (A_count > (nums.end() - nums.begin()) / 3)
                                ret.push_back(*Candidate_A);
                            return ret;
                        }
                    } while (*Candidate_A == *Candidate_B);
                    B_count = 1;
                }
            }
        }

        // second loop: validate candidates
        A_count = 0;
        B_count = 0;
        for (viit Vote = nums.begin(); Vote < nums.end(); Vote++) {
            if (*Vote == *Candidate_A)
                A_count++;
            if (*Vote == *Candidate_B)
                B_count++;
        }
        vector<int> ret;
        if (A_count > (nums.end() - nums.begin()) / 3)
            ret.push_back(*Candidate_A);
        if (B_count > (nums.end() - nums.begin()) / 3)
            ret.push_back(*Candidate_B);

        return ret;
    }
};
int main() {
    Solution sol;
    vector<int> a  = {1, 2, 2, 3, 3, 4, 4, 5, 1, 1, 1, 1};
    vector<int> rt = sol.majorityElement(a);
    for (viit z = rt.begin(); z < rt.end(); z++) {
        cout << *z;
    }
    return 0;
}