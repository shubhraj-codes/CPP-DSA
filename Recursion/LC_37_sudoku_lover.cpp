class Solution {
public:
    bool canPut(vector<vector<char>>& board, int r, int c, int num)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[i][c] == num) return false;
        }

        for(int j = 0; j < 9; j++)
        {
            if(board[r][j] == num) return false;
        }

        int startRow = (r/3) * 3;
        int startCol = (c/3) * 3;

        for(int i = startRow; i < startRow + 3; i++)
        {
            for(int j = startCol; j < startCol + 3; j++)
            {
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.')
                {
                    for(int num = '1'; num <= '9'; num++)
                    {
                        if(canPut(board, r, c, num))
                        {
                            board[r][c] = num;

                            if(solve(board)) return true;

                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
