//!error
#include "lc.hpp"
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X')
                    x++;
                else if (board[i][j] == 'O')
                    o++;
            }
        }
        if (x == 5)
            return false;
        if (x != o && x != o + 1)
            return false;

        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                {if(board[i][0]=='X')return false;}
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return false;
        }
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
            return false;
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
            return false;
        return true;
    }
};