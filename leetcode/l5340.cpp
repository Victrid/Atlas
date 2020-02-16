#include "lc.hpp"
// ugly one
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size())
            return 0;
        int row  = grid.size();
        int column   = grid[0].size();
        int search_row = 0, search_column = 0;
        int ans = 0;
        while (search_row < row) {
            //* here O(m+n).
            if (search_column == column - 1 && grid[search_row][search_column] >= 0) {
                search_row++;
            } else if (grid[search_row][search_column] >= 0 && grid[search_row][search_column + 1] >= 0) {
                search_column++;
            } else if (grid[search_row][search_column] >= 0 && grid[search_row][search_column + 1] < 0) {
                ans += (column - search_column - 1);
                search_row++;
            } else if (grid[search_row][search_column] < 0 && search_column == 0) {
                ans += column;
                search_row++;
            } else if (grid[search_row][search_column] < 0) {
                search_column--;
            }
        }
        return ans;
    }
};
