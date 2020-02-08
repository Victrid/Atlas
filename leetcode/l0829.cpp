class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 0;
        for (int i = 1; i * (i - 1) / 2 <= N; i++) {
            if (N % i == (i * (i - 1) / 2) % i)
                count++;
        }
        return count;
    }
};
int main(){
    int i = 15;
    Solution Sol;
    Sol.consecutiveNumbersSum(i);
    return 0;
}